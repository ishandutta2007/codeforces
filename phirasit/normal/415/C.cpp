#include <stdio.h>

int n, k;

int main() {
	scanf("%d%d", &n, &k);
	if(n == 1) {
		printf("%d\n", k == 0 ? 1 : -1);
		return 0;
	}
	int x = n/2;
	if(k < x) {
		printf("-1\n");
		return 0;
	}
	k -= x - 1;
	for(int i = 0;i < 2*(x-1);i++) {
		printf("%d ", i+1);
	}
	if(k == 1) {
		int v = 2*(x-1) + 1;
		printf("%d %d %d\n", v, v+1, v+2);
		return 0;
	}
	int p = k;
	while(p <= 2*(x-1)) {
		p += k;
	}
	printf("%d %d ", p, p+k);
	if(n%2) {
		printf("%d", p+k+1);
	}
	printf("\n");
	return 0;
}