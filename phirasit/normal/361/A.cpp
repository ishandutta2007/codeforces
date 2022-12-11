#include <stdio.h>

int n,k;

int main() {
	int i,j;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(i == j) {
				printf("%d ",k);
			}else {
				printf("0 ");
			}
		}
		printf("\n");
	}
	return 0;
}