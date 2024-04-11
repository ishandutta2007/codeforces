#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 50;
const int mod = 1e9 + 7;
const int inv2 = (mod + 1) >> 1;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

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

int f[N], g[N];

void solve() {
	int n;
	cin >> n;
	f[n + 1] = g[n + 1] = 1;
	g[n + 2] = 0;
	for (int i = n; i >= 1; --i) {
		int k = min(n + 2, 2 * i);
		if (2 * i == n + 1) {
			k = n + 2;
		}
		f[i] = dec(g[i + 1], g[k]);
		g[i] = inc(f[i], g[i + 1]);
	}
	int z = 1, q = fastpow(inv2, n);
	for (int i = 1; i <= n; ++i) {
		int ret = mul(z, f[i]);
		if (i == n) {
			cout << mul(inc(ret, z), q) << '\n';
		}
		else {
			cout << mul(ret, q) << '\n';
		}
		if (i % 2) pud(z, 2);
	}	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}