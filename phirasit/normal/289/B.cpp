#include <stdio.h>
#include <stdlib.h>

int arr[10010];
int n,m,d;

int cmp(const void *a,const void *b) {
	return *(int*)a - *(int*)b;
}
int abs(int x) {
	if(x < 0) return -x;
	return x;
}
int main() {
	int ans = 0;
	int i,j,ch = 0;
	scanf("%d %d %d",&n,&m,&d);
	for(i=0;i<n*m;i++) {
		scanf("%d",&arr[i]);
		if(arr[i]%d != arr[0]%d)
			ch = 1;
	}
	if(ch) {
		printf("-1\n");
		return 0;
	}
	qsort(arr,n*m,sizeof(int),cmp);
	for(i=0;i<n*m;i++)
		ans += abs((arr[i]-arr[n*m/2])/d);
	printf("%d\n",ans);
	return 0;
}