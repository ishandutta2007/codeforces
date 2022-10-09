#include <bits/stdc++.h>

const int N = 1e6 + 50;
int n, mod, fact[N], inv[N];

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y), y = inc(x, y); }
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

inline void init(int n) {
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = mul(i, fact[i - 1]);
	inv[n] = fastpow(fact[n], mod - 2);
	for (int i = n - 1; i >= 0; --i) inv[i] = mul(i + 1, inv[i + 1]);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> mod;
	int ans = 0;
	init(n);
	for (int k = 1; k <= n; ++k) {
		int t = mul(mul(mul(n - k + 1, n - k + 1), fact[k]), fact[n - k]);
		upd(ans, t);
	}
	std::cout << ans << '\n';
	return 0;
}