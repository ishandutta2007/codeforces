#include <stdio.h>
#include <stdlib.h>

int arr[20];
int n;

int cmp(const void *a,const void *b) {
	int x = *(int*)a,y = *(int*)b;
	return x - y;
}
int main() {
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<12;i++) {
		scanf("%d",&arr[i]);
	}
	qsort(arr,12,sizeof(int),cmp);
	for(n!=0?i=11:i=12,k=0;i>=0 && n;i--) {
		k += arr[i];
		if(k >= n)
			break;
	}
	if(i < 0) printf("-1\n");
	else
	printf("%d\n",12-i);
	return 0;
}