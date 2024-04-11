#include <stdio.h>
#include <stdlib.h>

int arr[2000010];
int n;

int cmp(const void *a,const void *b) {
	return *(int*)a - *(int*)b;
}
int main() {
	long long ans = 0;
	int i,j,k;
	scanf("%d",&n);
	for(i=1,k=0;i<=n;i*=4)
		k++;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	qsort(arr,n,sizeof(int),cmp);
	for(i=1,j=1;i<=n;i++) {
		 if(i > j) {
		 	j*= 4;
		 	k--;
		 }
		 ans += (long long) k * arr[n-i];
	}
	printf("%I64d\n",ans);
	return 0;
}