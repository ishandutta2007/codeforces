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
		int r = ri();
		int max = std::min(n - 1, r);
		int64_t res = (int64_t) max * (max + 1) / 2;
		if (max < r) res++;
		printf("%" PRId64 "\n", res);
	}
	return 0;
}