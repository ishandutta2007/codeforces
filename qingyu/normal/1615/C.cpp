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
		std::string s, t;
		std::cin >> n >> s >> t;
		int ans = 1e9;
		auto solve_even = [&](auto s, auto t, int o) {
			int ret = 0;
			int cnt[2] = { 0, 0 };
			for (int i = 0; i < n; ++i) {
				if (s[i] != t[i]) {
					++cnt[s[i] - '0'];	
					++ret;
				}
			}
			if (cnt[0] != cnt[1]) return (int)1e9;
			return ret;
		};
		auto solve_odd = [&](auto s, auto t, int o) {
			int ret = 0;
			int cnt[2] = { 0, 0 };
			for (int i = 0; i < n; ++i) {
				if (s[i] == t[i]) {
					++cnt[s[i] - '0'];
					++ret;
				}
			}
			if (cnt[1] != cnt[0] + 1) return (int)1e9;
			return ret;
		};


		int x = solve_even(s, t, 0);
		int y = solve_odd(s, t, 1);
		if (x % 2 == 0) ans = std::min(ans, x);
		if (y % 2 == 1) ans = std::min(ans, y);
		if (ans == 1e9) ans = -1;
		std::cout << ans << '\n';
	}
}