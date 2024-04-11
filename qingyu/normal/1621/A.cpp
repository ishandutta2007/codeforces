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
		int n, k;
		std::cin >> n >> k;
		if ((n + 1) / 2 < k) {
			puts("-1");
		}
		else {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if ((i + 1) / 2 <= k && i == j && (i % 2 == 1)) {
						putchar('R');
					}
					else putchar('.');
				}
				putchar('\n');
			}
		}
	}
}