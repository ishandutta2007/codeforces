#include <stdio.h>
#include <stdlib.h>
int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}
int main()
{
	int n, l , r;
	scanf("%d %d %d", &n , &l ,&r);
	--l;
	--r;
	int hamisi[2][n];
	for(int i=0; i<n; i++)
	{
		scanf("%d",&hamisi[0][i]);
	}
	for(int i=0; i<n; i++)
	{
		scanf("%d",&hamisi[1][i]);
	}
	for(int i=0; i<l; i++)
	{
		if(hamisi[0][i]!=hamisi[1][i])
		{
			printf("LIE\n");
			return 0;
		}
	}
	for(int i=r+1; i<n; i++)
	{
		if(hamisi[0][i]!=hamisi[1][i])
		{
			printf("LIE\n");
			return 0;
		}
	}
	int arr1[n];
	int arr2[n];
	for(int i=0; i<n; i++)
	{
		arr1[i] = -1; arr2[i] = -1;
	}
	for(int i=l; i<=r; i++)
	{
		arr1[i] = hamisi[0][i];
		arr2[i] = hamisi[1][i];
	}
	qsort (arr1, sizeof(arr1)/sizeof(*arr1), sizeof(*arr1), comp);
	qsort (arr2, sizeof(arr2)/sizeof(*arr2), sizeof(*arr2), comp);
	for(int i=0; i<n; i++)
	{
		if(arr1[i]!=arr2[i])
		{
			printf("LIE\n");
		}
	}
	printf("TRUTH\n");
}