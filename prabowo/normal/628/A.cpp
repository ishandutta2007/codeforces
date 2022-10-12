#include <cstdio>

int main () {
	int n, b, p;
	scanf ("%d %d %d", &n, &b, &p);
	
	int bottle = 0;
	int towel = n * p;
	
	int k = 512;
	while (n > 1) {
		while (k <= n) {
			bottle += k * b + (k >> 1);
			n -= k >> 1;
		}
		
		k >>= 1;
	}
	
	printf ("%d %d\n", bottle, towel);
	return 0;
}