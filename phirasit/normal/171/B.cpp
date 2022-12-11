#include <stdio.h>

int n;

int main() {
	scanf("%d",&n);
	int ans = n*n*6 - n*6 + 1;
	printf("%d\n",ans);
	return 0;
}