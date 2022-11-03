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
		int m = ri();
		int a[n][m];
		for (auto &i : a) for (auto &j : i) j = ri();
		int res[n][m];
		bool ok = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res[i][j] = 4;
				if (!i) res[i][j]--;
				if (i == n - 1) res[i][j]--;
				if (!j) res[i][j]--;
				if (j == m - 1) res[i][j]--;
				if (a[i][j] > res[i][j]) {
					ok = false;
				}
			}
		}
		if (ok) {
			puts("Yes");
			for (auto &i : res) {
				for (auto j : i) printf("%d ", j);
				puts("");
			}
			
		} else puts("NO");
	}
	return 0;
}