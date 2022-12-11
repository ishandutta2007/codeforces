#include <stdio.h>

int n;

int main() {
	int i;
	scanf("%d",&n);
	printf("%d ",n);
	for(i=1;i<n;i++)
		printf("%d ",i);
	return 0;
}