#include <cstdio>

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		int c = gcd(a, b);
		a /= c, b /= c;
		if (a > b) c = a, a = b, b = c;
		if (k == 1) puts("REBEL");
		else if (b == 1) puts("OBEY");
		else {
			if (k <= (b - 2) / a + 1) puts("REBEL");
			else puts("OBEY");
		}
	}
	return 0;
}