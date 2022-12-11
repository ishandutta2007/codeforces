#include <stdio.h>

int n,k;

int main() {
	int i,j;
	scanf("%d %d",&n,&k);
	if(k == n) {
		printf("-1\n");
	}else {
		for(i=1;i<n-k;i++) {
			printf("%d ",i+1);
		}
		printf("1 ");
		for(i=n-k+1;i<=n;i++)
			printf("%d ",i);
		printf("\n");
	}
	return 0;
}