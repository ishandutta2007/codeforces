#include <bits/stdc++.h>
using namespace std;
const int maxn = 1500, maxm = 1e5, mod = 1e9 + 7;
int n, m, val[maxn + 10], p, tmp, k;
int f[maxn + 10][maxn + 10], sf[maxn + 10][maxn + 10];
int inv[maxm + 10], fac[maxm + 10], ifac[maxm + 10];
int sv[maxn + 10], ssf[maxn + 10][maxn + 10];
int pn[maxm + 10], pm[maxm + 10];

void init() {
	fac[0] = ifac[0] = pn[0] = pm[0] = 1;
	for (int i = 1; i <= maxm; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		inv[i] = i == 1 ? 1 : mod - 1ll * (mod / i) * inv[mod % i] % mod;
		ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
		pn[i] = 1ll * pn[i - 1] * p % mod;
		pm[i] = 1ll * pm[i - 1] * (mod + 1 - p) % mod;
	}
}

int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1ll * ans * x % mod;
		y >>= 1; x = 1ll * x * x % mod;
	}
	return ans;
}

inline int comb(int x, int y) {
	return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

int main() {
	scanf("%d%d%d%d%d", &n, &m, &p, &tmp, &k);
	p = 1ll * p * fpow(tmp, mod - 2) % mod;
	init();
	for (int i = 0; i <= m && i <= k; ++i)
		val[i] = 1ll * comb(k, i) * pn[i] % mod * pm[k - i] % mod;
	for (int i = 0; i <= m; ++i)
		sv[i] = ((i ? sv[i - 1] : 0) + val[i]) % mod;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= i; ++j)
			(f[1][i] += 1ll * val[j - 1] * val[m - i] % mod) %= mod;
	for (int i = 2; i <= n + 1; ++i) {
		for (int j = 1; j <= m; ++j) {
			sf[i - 1][j] = (sf[i - 1][j - 1] + f[i - 1][j]) % mod;
			ssf[i - 1][j] = (ssf[i - 1][j - 1] + 1ll * sf[i - 1][j] * val[j]) % mod;
		}
		for (int j = 1; j <= m; ++j) {
			int w = sf[i - 1][m] - sf[i - 1][m - j];
			if (w < 0) w += mod;
			w = 1ll * w * sv[j - 1] % mod;
			w -= ssf[i - 1][j - 1];
			w = (w % mod + mod) % mod;
			f[i][j] = 1ll * w * val[m - j] % mod;
		}
	}
	printf("%d", sf[n][m]);
}