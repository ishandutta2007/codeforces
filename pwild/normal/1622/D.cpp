#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 5050, MOD = 998244353;

i64 inv[N], fac[N], inv_fac[N];

void precalc() {
	inv[1] = 1;
	for (int n = 2; n < N; n++) {
		inv[n] = (MOD - (MOD/n)*inv[MOD%n] % MOD) % MOD;
	}

	fac[0] = 1;
	for (int n = 1; n < N; n++) {
		fac[n] = n*fac[n-1] % MOD;
	}

	inv_fac[0] = 1;
	for (int n = 1; n < N; n++) {
		inv_fac[n] = inv[n]*inv_fac[n-1] % MOD;
	}
}

i64 binom(i64 n, i64 k) {
	if (k < 0 || k > n) return 0;
	return fac[n] * inv_fac[k] % MOD * inv_fac[n-k] % MOD;
}

int main() {
	int n, k;
	cin >> n >> k;

	precalc();

	string a; cin >> a;
	
	i64 res = 1;
	for (int i = 0; i < n; i++) {
		int o = 0, j = i;
		for (; j < n; j++) {
			if (o == k && a[j] == '1') break;
			o += a[j] == '1';
		}
		if (i == 0 && o < k) break;

		int z = j-i-o;
		res = (res + binom(j-i-1, z-(a[i]=='1'))) % MOD;
		cerr << j-i-1 << " " << z-(a[i]=='1') << endl;
	}
	cout << res << '\n';
}