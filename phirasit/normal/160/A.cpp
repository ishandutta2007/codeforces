#include <stdio.h>
#include <stdlib.h>

int arr[110];
int n;

int cmp(const void *a,const void *b) {
	int x = *(int*)a,y = *(int*)b;
	return x - y;
}
int main() {
	int i,j,k;
	scanf("%d",&n);
	for(i=j=0;i<n;i++) {
		scanf("%d",&arr[i]);
		j += arr[i];
	}
	qsort(arr,n,sizeof(int),cmp);
	for(i=n-1,k=0;i>=0;i--) {
		k += arr[i];
		if(k > j-k)
			break;
	}
	printf("%d\n",n-i);		
	return 0;
}