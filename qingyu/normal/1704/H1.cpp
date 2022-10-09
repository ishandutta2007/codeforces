#include <bits/stdc++.h>

using namespace std;

const int N = 5050;
int mod;

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

int n, fact[N], C[N][N], pw[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	std::cin >> n >> mod;
	for (int i = 0; i <= n; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = inc(C[i - 1][j], C[i - 1][j - 1]);
		}
	}
	fact[0] = 1;
	for (int i = 1; i <= n; ++i)
		fact[i] = mul(i, fact[i - 1]);
	for (int i = 0; i <= n; ++i) {
		pw[i][0] = 1;
		for (int j = 1; j <= n; ++j) {
			pw[i][j] = mul(pw[i][j - 1], i);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; 2 * i + j <= n; ++j) {
			assert(n - i - j - 1 >= 0);
			int ret = mul(C[n][i], C[n - i][j]);
			pud(ret, fact[n - i - j]);
			pud(ret, C[n - i - j - 1][i - 1]);
			pud(ret, pw[n - 1][i]);
			pud(ret, pw[n - i - j][j]);
			upd(ans, ret);
		}
	}
	std::cout << ans << '\n';
	return 0;
}