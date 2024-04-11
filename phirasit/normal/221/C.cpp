#include <stdio.h>
#include <stdlib.h>

int last[100010];
int arr[100010];
int n;

int cmp(const void *a,const void *b) {
	int x = *(int*)a,y = *(int*)b;
	return x - y;
}
int main() {
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		last[i] = arr[i];
	}
	qsort(arr,n,sizeof(int),cmp);
	for(i=j=0;i<n;i++)
		if(arr[i] != last[i])
			j++;
	if(j <= 2) printf("YES\n");
	else printf("NO\n");
	return 0;
}