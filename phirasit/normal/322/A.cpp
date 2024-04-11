#include <stdio.h>

int n,k;

int main() {
	int i;
	scanf("%d %d",&n,&k);
	printf("%d\n",n+k-1);
	for(i=1;i<=k;i++)
		printf("%d %d\n",1,i);
	for(i=2;i<=n;i++)
		printf("%d %d\n",i,1);
}