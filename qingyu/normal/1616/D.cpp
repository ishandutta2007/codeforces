#include <bits/stdc++.h>

const int mod = 998244353;
const int N = 1e6 + 50;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

inline int fastpow(int x, int p) {
	int r = 1;
	while (p) {
		if (p & 1) pud(r, x);
		pud(x, x);
		p >>= 1;
	}
	return r;
}

int dp[N][3]; // dp[i][//

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		int n, x;
		std::cin >> n;
		std::vector<int> a(n + 1);
		a[0] = 0;
		for (int i = 1; i <= n; ++i) std::cin >> a[i];
		std::cin >> x;
		for (int i = 1; i <= n; ++i) {
			a[i] -= x;
		}
		memset(dp, 0xcf, sizeof dp);
		dp[1][0] = 0; dp[1][1] = 1; dp[1][2] = 1;
		for (int i = 2; i <= n; ++i) {
			dp[i][0] = std::max(std::max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
			dp[i][1] = dp[i - 1][0] + 1;
			if (a[i - 1] + a[i] >= 0) {
				dp[i][2] = std::max(dp[i][2], dp[i - 1][1] + 1);
				if (a[i - 2] + a[i - 1] + a[i] >= 0) {
					dp[i][2] = std::max(dp[i][2], dp[i - 1][2] + 1);
				}
			}
		}
		std::cout << std::max(std::max(dp[n][0], dp[n][1]), dp[n][2]) << '\n';
	}
	return 0;
}