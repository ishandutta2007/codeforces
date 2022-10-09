#include <bits/stdc++.h>

const int N = 1e6 + 50;
const int mod = 998244353;

int n, ans, x[N], y[N], s[N], f[N], g[N];

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> x[i] >> y[i] >> s[i];
	}
	for (int i = 1; i <= n; ++i) {
		int j = std::lower_bound(x + 1, x + n + 1, y[i]) - x;
		g[i] = inc(x[i] - y[i], dec(f[i - 1], f[j - 1]));
		if (s[i]) upd(ans, g[i]);
		f[i] = inc(f[i - 1], g[i]);
	}
	upd(ans, x[n] + 1);
	std::cout << ans;
	return 0;
}