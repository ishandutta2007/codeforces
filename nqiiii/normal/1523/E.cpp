#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5, mod = 1e9 + 7;
int T, fac[maxn + 10], inv[maxn + 10], ifac[maxn + 10];
int n, k;

void init() {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= maxn; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		inv[i] = i == 1 ? 1 : mod - 1ll * mod / i * inv[mod % i] % mod;
		ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
	}
}

int comb(int n, int m) {
	return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int icomb(int n, int m) {
	return 1ll * ifac[n] * fac[m] % mod * fac[n - m] % mod;
}

int main() {
	init();
	scanf("%d", &T);
	while (T--) {
		int ans = 1;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i) {
			long long A = n - 1ll * (i - 1) * (k - 1);
			if (A >= i) {
				int v = 1ll * comb(A, i) * icomb(n, i) % mod;
				ans += v; ans %= mod;
			}
		}
		printf("%d\n", ans);
	}
}