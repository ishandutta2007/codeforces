#include <stdio.h>

int n;

int main() {
	scanf("%d",&n);
	if(n%2 == 0 && n > 2) printf("YES\n");
	else printf("NO\n");
	return 0;
}