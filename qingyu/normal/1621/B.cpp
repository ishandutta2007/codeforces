#include <bits/stdc++.h>

const int mod = 998244353;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); } 
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		long long min = 1e18, max = -1e18;
		long long cmin = 0, cmax = 0;
	   	long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			long long l, r, c;
			std::cin >> l >> r >> c;
			if (l < min) {
				min = l;
				cmin = c;
				ans = 1e18;
			}
			else if (l == min) {
				cmin = std::min(cmin, c);
			}
			if (r > max) {
				max = r;
				cmax = c;
				ans = 1e18;
			}
			else if (r == max) {
				cmax = std::min(cmax, c);
			}
			ans = std::min(ans, (long long)(cmin + cmax));
			if (l == min && r == max) {
				ans = std::min(ans, c);
			}
			std::cout << ans << '\n';
		}
	}
}