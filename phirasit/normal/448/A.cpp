#include <stdio.h>

int main() {
	int n, a1, a2, a3, b1, b2, b3;
	scanf("%d%d%d%d%d%d%d", &a1, &a2, &a3, &b1, &b2, &b3, &n);
	int val = (a1+a2+a3 + 4) / 5  + (b1+b2+b3 + 9) / 10;
	printf("%s\n", val > n ? "NO" : "YES");
	return 0;
}