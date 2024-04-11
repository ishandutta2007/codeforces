#include <bits/stdc++.h>

const int mod = 998244353;

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

const int N = 1e6 + 50;
int t, n, m, a[N], pri[N], ptot, b[N], tot;
int stat[N];
bool np[N];

inline void init(int n) {
	np[1] = true;
	for (int i = 2; i <= n; ++i) {
		if (!np[i]) {
			pri[++ptot] = i;
		}
		for (int j = 1; j <= ptot && i * pri[j] <= n; ++j) {
			np[i * pri[j]] = true;
			if (i % pri[j] == 0) break;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> t;
	init(1e6);
	while (t--) {
		std::cin >> n >> m;
		for (int i = 1; i <= n; ++i) std::cin >> a[i];
		long long ans = 0;
		for (int i = 1; i <= m; ++i) {
			int tot = 0;
			for (int j = 0; i + j * m <= n; ++j) {
				b[j + 1] = a[i + j * m];
				++tot;
			}
			int f = 0, g = 0;
			// f: already have a prime
			// g: don't have a prime
			for (int j = 1; j <= tot; ++j) {
				int _f = f, _g = g;
				if (b[j] == 1) {
					f = _f + 1;
					g = _g;
				}
				else if (!np[b[j]]) {
					f = 0;
					g = _f + 1;
				}
				else {
					f = g = 0;
				}
				ans += g;
			}
		}
		for (int i = 1; i <= n; ++i)
			if (!np[a[i]])
				--ans;
		std::cout << ans << '\n';
	}
	return 0;
}