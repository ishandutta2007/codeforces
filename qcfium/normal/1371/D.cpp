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
		int num = ri();
		printf("%d\n", num % n ? 2 : 0);
		bool res[n][n];
		memset(res, 0, sizeof(res));
		for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) {
			if (--num < 0) break;
			res[k][(j + k) % n] = true;
		}
		for (auto &i : res) {
			for (auto j : i) printf("%d", j);
			puts("");
		}
	}
	return 0;
}