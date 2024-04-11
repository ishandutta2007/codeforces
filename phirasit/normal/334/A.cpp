#include <stdio.h>

int main() {
	int n,k,i;
	scanf("%d",&n);
	for(i=1;i<n*n/2;i+=2)
		printf("%d %d ",i,n*n-i+1);
	printf("\n");
	for(i=2;i<=n*n/2;i+=2)
		printf("%d %d ",i,n*n-i+1);
	printf("\n");
	return 0;
}