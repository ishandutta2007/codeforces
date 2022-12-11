#include <stdio.h>

int arr[110];
int n;

int main() {
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		if(i > 0)
			arr[i] += arr[i-1];
	}
	int x,y;
	scanf("%d %d",&x,&y);
	for(i=0;i<n;i++) {
		int k;
		if(i > 0)
			k = arr[i-1];
		else
			k = 0;
		int p = arr[n-1];
		if(i > 0) p -= arr[i-1];
		if(x <= k && k <= y && x <= p && p <= y) {
			printf("%d\n",i+1);
			break;
		}
	}
	if(i >= n)
		printf("0");
	return 0;
}