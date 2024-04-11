#include <stdio.h>
int gcd(register int x, register int y) {return y ? gcd(y, x % y) : x;}
int main() {
	int n;
	scanf("%d", &n);
	for(int i = n / 2, j = n - i; i >= 1; --i, ++j) {
		if(gcd(i, j) == 1) return !printf("%d %d\n", i, j);
	}
	return 0;
}