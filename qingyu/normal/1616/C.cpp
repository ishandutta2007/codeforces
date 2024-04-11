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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; ++i) std::cin >> a[i];
		int ans = n - 2;
		if (n == 1) ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				// a[i] = x 
				// a[j] = x + (j - i) * d
				// d = (a[j] - a[i]) / (j - i)
				int ret = 0;
				for (int k = 1; k <= n; ++k) {
					if (a[k] * (j - i) != a[i] * (j - i) + (k - i) * (a[j] - a[i])) {
						++ret;
					}
				}
				ans = std::min(ans, ret);
			}
		}
		std::cout << ans << '\n';;

	}
	return 0;
}