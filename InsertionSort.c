#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insertion(int* list,int n);
int main(void)
{
	int n = 0;
	int* list = (int*)malloc(100 * sizeof(int));
	printf("Input: ");
	FILE* fp = fopen("lab1.data","r");
	while (EOF!=fscanf(fp,"%d",(list+n)))
	{
		printf("%d ",*(list+n));
		n++;
	}
	list = (int*)realloc(list, n * sizeof(int));
	insertion(list, n);
	free(list);
	fclose(fp);
}
void insertion(int* list,int n)
{
	int key;
	for (int i = 1; i < n; i++)
	{
		key = *(list + i);
		for (int j = i - 1; j >= 0; j--)
		{
			if(*(list + j) > key)
				*(list + j + 1) = *(list + j);
			else break;
			*(list+j) = key;
		}
	}
	printf("\nSorted: ");
	for(int i=0;i<n;i++)
		printf("%d ", *(list + i));
}
