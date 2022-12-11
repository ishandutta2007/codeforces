#include <stdio.h>

int h[310];
int p, n;

int main() {
	scanf("%d%d", &p, &n);
	for(int i = 1;i <= n;i++) {
		int x;
		scanf("%d", &x);
		if(h[x%p]) {
			printf("%d\n", i);
			return 0;
		}
		h[x%p] = 1;
	}
	printf("-1\n");
	return 0;
}