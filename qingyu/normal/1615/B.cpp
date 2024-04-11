#include <bits/stdc++.h>

const int mod = 998244353;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); } 
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

const int N = 2e5 + 50;

int bit[20][N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	for (int i = 0; i < 20; ++i) {
		for (int k = 1; k <= 2e5; ++k) {
			if (k >> i & 1) {
				bit[i][k] = bit[i][k - 1] + 1;
			}
			else {
				bit[i][k] = bit[i][k - 1];
			}
		}
	}
	int t;
	std::cin >> t;
	while (t--) {
		int l, r;
		std::cin >> l >> r;
		int ans = r - l + 1, total = r - l + 1;
		for (int i = 0; i < 20; ++i) {
			ans = std::min(ans, total - (bit[i][r] - bit[i][l - 1]));
		}
		std::cout << ans << '\n';
	}
}