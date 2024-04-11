#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 1000001, MOD = 1e9 + 7;
int n, m;
ll f[mxN], iF[mxN], iv[mxN], pm[mxN], pm1[mxN], p[mxN];

void pc() {
	f[0] = iF[0] = f[1] = iF[1] = iv[1] = 1;
	for (int i = 2; i <= n; ++i) {
		iv[i] = MOD - (MOD / i) * iv[MOD % i] % MOD;
		f[i] = f[i - 1] * i % MOD;
		iF[i] = iF[i - 1] * iv[i] % MOD;
	}
	pm[0] = pm1[0] = 1;
}

ll C(int a, int b) {
	return f[a] * iF[b] % MOD * iF[a - b] % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	pc();
	for (int i = 1; i <= n; ++i) {
		pm[i] = pm[i - 1] * m % MOD;
		pm1[i] = pm1[i - 1] * (m - 1) % MOD;
	}
	for (int i = 0; i < n; ++i)
		p[i] = (C(n, i) * pm1[n - i] + (i ? p[i - 1] : 0)) % MOD;
	ll ans = pm[n] + 69696969ll * MOD;
	for (int i = 1; i <= n; ++i) {
		ans += pm[i] * pm[n] % MOD;
		ans -= pm[i] * p[i - 1] % MOD;
	}
	cout << ans % MOD;
	return 0;
}