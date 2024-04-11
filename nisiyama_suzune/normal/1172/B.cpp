#include <bits/stdc++.h>

#define fac ff

const int MOD = 998244353;
int fac[210000], inv[210000];

int N;
std::vector <int> edge[210000];


void euclid (const long long &a, const long long &b, long long &x, long long &y) {
	if (b == 0) x = 1, y = 0;
	else euclid (b, a % b, y, x), y -= a / b * x; }
long long inverse (long long x, long long m) {
	long long a, b; euclid (x, m, a, b); return (a % m + m) % m; }
int C (int n, int m) { return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD; }

int calc (int u, int f) {
	int ret = 1;
	for (int e : edge[u]) if (e != f) ret = 1ll * ret * calc (e, u) % MOD;
	ret = 1ll * ret * fac[edge[u].size () - 1] % MOD;
	ret = 1ll * ret * edge[u].size () % MOD;
	return ret;
}

int calc_tot () {
	int ret = 1;
	for (int e : edge[1]) ret = 1ll * ret * calc (e, 1) % MOD;
	ret = 1ll * ret * fac[edge[1].size ()] % MOD;
	ret = 1ll * ret * N % MOD;
	return ret;
}

int main () {
	scanf ("%d", &N);
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		scanf ("%d%d", &u, &v);
		edge[u].push_back (v);
		edge[v].push_back (u);
	}
	fac[0] = 1;
	for (int i = 1; i <= N; ++i) fac[i] = 1ll * fac[i - 1] * i % MOD;
	for (int i = 0; i <= N; ++i) inv[i] = inverse (fac[i], MOD);
	printf ("%d\n", calc_tot ());
}