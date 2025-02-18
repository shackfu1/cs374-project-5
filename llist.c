#include "llist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void llist_insert_head(struct node **head, struct node *n){
	n->next = *head;
    *head = n;
}

struct node *llist_delete_head(struct node **head){
	if (*head != NULL && (*head)->next != NULL) {
		struct node *prev_head = *head;
    	*head = (*head)->next;
    	return prev_head;
    }else if (*head != NULL){
    	*head = NULL;
    	return NULL;
    }else{
    	return NULL;
    }
}

void llist_insert_tail(struct node **head, struct node *n){
	struct node *temp = *head;
	while (temp != NULL && temp->next != NULL) {
        temp = temp->next; 
	}
	if (temp != NULL){
		temp->next = n;
	}

}

void llist_print(struct node *head){
	if (head == NULL) {
        printf("[empty]");
    } else {
    	while (head != NULL) {
    		printf("%i", head->value);
    		if (head->next != NULL){
    			printf(" -> ");
    		}
	        head = head->next; 
    	}
    }

    printf("\n");
}

void llist_free(struct node **head){
	while (*head != NULL) {
		struct node *prev = *head;
	    *head = (*head)->next; 
	    node_free(prev);
	}
}

struct node *node_alloc(int value){
	struct node *n = malloc(sizeof *n);

    n->value = value;
    n->next = NULL;

    return n;
}

void node_free(struct node *n){
	free(n);
}


int main(int argc, char *argv[])
{
	struct node *head = NULL;

	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "ih") == 0 || strcmp(argv[i], "it") == 0){
			int value = atoi(argv[i+1]);
			struct node *n = node_alloc(value);
			if (head){
				if (strcmp(argv[i], "ih") == 0){
					llist_insert_head(&head, n);
				}else{
					llist_insert_tail(&head, n);
				}
			}else{
				head = n;
			}
		}else if (strcmp(argv[i], "dh") == 0){
			llist_delete_head(&head);
		}else if (strcmp(argv[i], "f") == 0){
			llist_free(&head);
		}else if (strcmp(argv[i], "p") == 0){
			llist_print(head);
		}
    }
}