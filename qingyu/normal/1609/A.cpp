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
long long a[N], b[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		int j = 1;
		for (int i = 1; i <= n; ++i) {
		   	std::cin >> a[i];
			b[i] = a[i];
		}
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int k = 1; k <= n; ++k) a[k] = b[k];
			long long sum = 0;
			for (int k = 1; k <= n; ++k)
				if (i != k) {
					while (a[k] % 2 == 0) {
						a[k] /= 2;
						a[i] *= 2;
					}
				}
			for (int i = 1; i <= n; ++i) sum += a[i];
			ans = std::max(ans, sum);
		}	
		std::cout << ans << '\n';
	}
	return 0;
}