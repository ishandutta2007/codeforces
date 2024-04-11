#include <bits/stdc++.h>

using namespace std;

const int N = 5050;
const int mod = 998244353;

int S[N][N], pw[N], f[N], g[N];

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

void init(int n) {
	S[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			S[i][j] = (1ll * S[i - 1][j] * j + S[i - 1][j - 1]) % mod;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init(N - 1);
	int T;
	cin >> T;
	while (T--) {
		int n, m, k;
		cin >> n >> m >> k;
		pw[0] = 1;
		const int t = mul(m + 1 >> 1, fastpow(m, mod - 2));
		for (int i = 1; i <= k; ++i) pw[i] = mul(pw[i - 1], t);
		f[0] = 1;
		for (int i = 1; i <= k; ++i) f[i] = mul(f[i - 1], n - i + 1);
		int ans = 0;
		for (int i = 1; i <= k; ++i)
			upd(ans, mul(mul(S[k][i], f[i]), pw[i]));
		pud(ans, fastpow(m, n));
		cout << ans << '\n';
	}
	return 0;
}