#include <stdio.h>

int n;

int main() {
	int i,j;
	scanf("%d",&n);
	for(i=1;i<n;i++) {
		for(j=1;j<n;j++) {
			printf("%d ",i*j/n*10+((i*j)%n));
		}
		printf("\n");
	}
	return 0;
}