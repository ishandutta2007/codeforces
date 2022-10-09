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
		std::set<int> map;
		std::cin >> n;
		while (n--) {
			int x;
			std::cin >> x;
			if (map.count(x)) {
				x = -x;
			}
			if (!map.count(x)) {
				map.emplace(x);
			}
		}
		std::cout << map.size() << '\n';
	}
	return 0;
}