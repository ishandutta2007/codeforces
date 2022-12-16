#include <bits/stdc++.h>

const int MOD = 998244353;

int N, A, B;
int strong[3000], cp[3000][3000];
int fact[3000], lfact[3000];
int ans[3000];

int inv (int x) {
	int n = MOD - 2, res = 1, mul = x;
	while (n) {
		if (n & 1) res = 1ll * res * mul % MOD;
		mul = 1ll * mul * mul % MOD;
		n >>= 1;
	}
	return res;
}

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> A >> B;
	
	fact[0] = 1; fact[1] = 1ll * A * inv (B) % MOD;
	for (int i = 2; i <= N; ++i) fact[i] = 1ll * fact[i - 1] * fact[1] % MOD;
	lfact[0] = 1; lfact[1] = 1ll * (B - A) * inv (B) % MOD;
	for (int i = 2; i <= N; ++i) lfact[i] = 1ll * lfact[i - 1] * lfact[1] % MOD;

	for (int s = 0; s <= N; ++s) cp[s][0] = 1;
	for (int s = 1; s <= N; ++s)
		for (int i = 1; i <= s; ++i)
			cp[s][i] = (1ll * cp[s - 1][i] * lfact[i] + 1ll * cp[s - 1][i - 1] * fact[s - i]) % MOD;
	strong[1] = 1;
	for (int s = 2; s <= N; ++s) {
		strong[s] = 1;
		for (int i = 1; i <= s - 1; ++i)
			strong[s] = (strong[s] - 1ll * strong[i] * cp[s][i] % MOD + MOD) % MOD;
	}
	ans[0] = ans[1] = 0;
	for (int s = 2; s <= N; ++s) {
		for (int i = 1; i < s; ++i)
			ans[s] = (ans[s] + 1ll * strong[i] * cp[s][i] % MOD * (1ll * i * (s - i) % MOD + 1ll * i * (i - 1) / 2 % MOD + ans[i] + ans[s - i])) % MOD;
		ans[s] = (ans[s] + 1ll * s * (s - 1) / 2 * strong[s]) % MOD * inv ((1 - strong[s] + MOD) % MOD) % MOD;
	}
	std::cout << ans[N] << std::endl;
}