#include <bits/stdc++.h>

const int mod = 1e9 + 7;
inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline void upd(int &x, int y) { x = inc(x, y); }

int main() {
	int n, m, x;
	std::cin >> n >> m >> x;
	if (n > m) puts("0");
	else {
		std::vector<std::vector<std::vector<int>>> dp(m + 1, std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1)));
		dp[0][0][0] = 1;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j <= n; ++j) {
				for (int k = 0; k <= j; ++k) {
					if (j + 1 <= n && k + 1 <= n) {
						upd(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
					}
					if (j + 1 <= n) {
						upd(dp[i + 1][j + 1][k], dp[i][j][k]);
					}
					if (x != i + 1) {
						if (k + 1 <= j)
							upd(dp[i + 1][j][k + 1], dp[i][j][k]);
						upd(dp[i + 1][j][k], dp[i][j][k]);
					}
				}
			}
		}
		int ans = dp[m][n][n];
		for (int i = 1; i <= n; ++i) ans = 1ll * i * ans % mod;
		std::cout << ans << '\n';
	}
	return 0;
}