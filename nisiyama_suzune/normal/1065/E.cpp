#include <bits/stdc++.h>

const int MOD = 998244353;

int N, M, A;
int B[210000];

int fpm (int a, int m) {
	int res = 1, mul = a;
	while (m) {
		if (m & 1) res = 1ll * res * mul % MOD;
		mul = 1ll * mul * mul % MOD;
		m >>= 1;
	}
	return res;
}

int main () {
	scanf ("%d%d%d", &N, &M, &A);
	for (int i = 1; i <= M; ++i) scanf ("%d", &B[i]);
	long long res = 1;
	for (int i = 1; i <= M; ++i) {
		long long tot = fpm (A, 2 * (B[i] - B[i - 1])), same = fpm (A, B[i] - B[i - 1]);
		res *= ((tot - same + MOD) % MOD * fpm (2, MOD - 2) % MOD + same) % MOD;
		res %= MOD;
	}
	(res *= fpm (A, N - B[M] * 2)) %= MOD;
	printf ("%lld\n", res);
}