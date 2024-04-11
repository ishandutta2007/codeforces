#include <bits/stdc++.h>

const int MOD = 998244353;

void euclid (const long long &a, const long long &b, long long &x, long long &y) {
	if (b == 0) x = 1, y = 0;
	else euclid (b, a % b, y, x), y -= a / b * x; }
long long inverse (long long x, long long m = MOD) {
	long long a, b; euclid (x, m, a, b); return (a % m + m) % m; }

int N, M;
int dp[3010][3010];
int p[210000], w[210000];
int tot[2];
int ans[210000];

int main () {
	scanf ("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) scanf ("%d", &p[i]);
	for (int i = 1; i <= N; ++i) {
		scanf ("%d", &w[i]);
		tot[p[i]] += w[i];
	}
	for (int d1 = 0; d1 <= M; ++d1) {
		int d2 = M - d1;
		int i = tot[0] - d1, j = tot[1] + d2;
		dp[d1][d2] = i;
	}
	for (int k = M - 1; k >= 0; --k) {
		for (int d1 = 0; d1 <= k; ++d1) {
			int d2 = k - d1;
			int i = tot[0] - d1, j = tot[1] + d2;
			dp[d1][d2] = (1ll * i * inverse (i + j) % MOD * dp[d1 + 1][d2] + 1ll * j * inverse (i + j) % MOD * dp[d1][d2 + 1]) % MOD;
		}
	}
	int prob = dp[0][0];
	for (int i = 1; i <= N; ++i) if (p[i] == 0)
		ans[i] = 1ll * prob * w[i] % MOD * inverse (tot[0]) % MOD;

	for (int d1 = 0; d1 <= M; ++d1) {
		int d2 = M - d1;
		int i = tot[0] - d1, j = tot[1] + d2;
		dp[d1][d2] = j;
	}
	for (int k = M - 1; k >= 0; --k) {
		for (int d1 = 0; d1 <= k; ++d1) {
			int d2 = k - d1;
			int i = tot[0] - d1, j = tot[1] + d2;
			dp[d1][d2] = (1ll * i * inverse (i + j) % MOD * dp[d1 + 1][d2] + 1ll * j * inverse (i + j) % MOD * dp[d1][d2 + 1]) % MOD;
		}
	}
	prob = dp[0][0];
	for (int i = 1; i <= N; ++i) if (p[i] == 1)
		ans[i] = 1ll * prob * w[i] % MOD * inverse (tot[1]) % MOD;

	for (int i = 1; i <= N; ++i) printf ("%d\n", ans[i]);
}