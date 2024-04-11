#include <stdio.h>
#define dmin(x, y) ((x) < (y) ? (x) : (y))
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	if(k == 0 || k == n) return !printf("0 0");
	printf("1 %d", dmin(n - k, k * 2));
	return 0;
}