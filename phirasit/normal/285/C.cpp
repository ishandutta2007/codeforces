#include <stdio.h>
#include <stdlib.h>

int arr[300010];
int n,k;

int cmp(const void *a,const void *b) {
	return *(int*)a - *(int*)b;
}
int abs(int x) {
	if(x < 0) return -x;
	return x;
}
int main() {
	long long ans = 0;
	int i,j,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&arr[i]);
	}
	qsort(arr+1,n,sizeof(int),cmp);
	for(i=1;i<=n;i++)
		ans += abs(i-arr[i]);
	printf("%I64d\n",ans);
	return 0;
}