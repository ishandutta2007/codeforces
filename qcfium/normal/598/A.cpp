#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int main() {
	int t = ri();
	for (int i = 0; i < t; i++) {
		int n = ri();
		int64_t res = (int64_t) (n + 1) * n / 2;
		for (int j = 1; j <= n; j <<= 1) res -= j * 2;
		printf("%" PRId64 "\n", res);
	}
	return 0;
}