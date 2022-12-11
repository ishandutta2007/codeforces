#include <stdio.h>

int n,k;

int main() {
	int i,j;
	scanf("%d %d",&n,&k);
	for(i=0;i<k-n%k;i++)
		printf("%d ",n/k);
	for(i=0;i<n%k;i++)
		printf("%d ",n/k+1);
	return 0;
}