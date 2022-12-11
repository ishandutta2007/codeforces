#include <stdio.h>

int n,k;

int main() {
	int i;
	scanf("%d %d",&n,&k);
	for(i=0;i<k+1;i++) {
		printf("%d ",k-i+1);
	}
	for(i=0;i<n-k-1;i++) {
		printf("%d ",i+k+2);
	}
	return 0;
}