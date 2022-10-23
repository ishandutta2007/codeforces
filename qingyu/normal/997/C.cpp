#include <bits/stdc++.h>

using namespace std;

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

inline int pw(int x) {
	return fastpow(3, x);
}

void solve() {
	int n;
	cin >> n;
	int ans = pw(1ll * n * n % (mod - 1)), ret = 1;
	dpu(ans, fastpow(dec(pw(n), 3), n));
	pud(ans, 2);
	for (int i = 1; i <= n; ++i) {
		pud(ret, n - i + 1);
		pud(ret, fastpow(i, mod - 2));
		int k = pw(1ll * n * (n - i) % (mod - 1));
		dpu(k, fastpow(dec(pw(n - i), 1), n));
		pud(k, 3);
		(i & 1 ? dpu : upd)(ans, mul(k, ret));
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}