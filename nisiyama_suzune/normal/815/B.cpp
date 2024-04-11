#include <cstdio>

int N;
int A[210000];

int mul[210000];

const int MOD = 1E9 + 7;

long long inverse (const long long &x) {
	if (x == 1) return 1;
	return (MOD - MOD / x) * inverse (MOD % x) % MOD;
}

int C (int n, int m) {
	return 1LL * mul[n] * inverse (mul[m]) % MOD * inverse (mul[n - m]) % MOD;
}

int main () {
	scanf ("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf ("%d", A + i);
	mul[0] = 1;
	for (int i = 1; i <= N; ++i)
		mul[i] = 1LL * mul[i - 1] * i % MOD;
	int ans = 0;
	if (N % 4 == 1) {
		for (int i = 0; i < N; i += 2) {
			ans = ans + 1LL * C (N / 2, i / 2) * A[i] % MOD;
			ans %= MOD;
		}
	} else if (N % 4 == 2) {
		for (int i = 0; i < N; ++i) {
			ans = ans + 1LL * C ((N - 1) / 2, i / 2) * A[i] % MOD;
			ans %= MOD;
		}
	} else if (N % 4 == 3) {
		int lst = 0, tag = -1;
		for (int i = 0; i < N - 1; ++i) {
			ans = (ans + MOD + 1LL * ((long long) C ((N - 2) / 2, i / 2) + lst * tag + MOD) * A[i] % MOD) % MOD;
			tag = -tag;
			lst = C ((N - 2) / 2, i / 2);
		}
		ans = (ans + MOD - A[N - 1]) % MOD;
	} else if (N % 4 == 0) {
		int tag = 1;
		for (int i = 0; i < N; ++i) {
			ans = (ans + MOD + 1LL * tag * C ((N - 1) / 2, i / 2) * A[i] % MOD) % MOD;
			tag = -tag;
		}
	}
	printf ("%d\n", ans);
}