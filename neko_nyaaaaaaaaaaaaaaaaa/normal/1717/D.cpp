#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
using namespace std;

#define int long long

long long modpow(long long n, long long k, long long MOD) {
	long long ans = 1;
	while (k > 0) {
		if (k & 1) ans = (ans*n) % MOD;
		n = (n*n) % MOD; k >>= 1;
	}
	return ans;
}

const int MAX = 1000001;
const long long M = 1e9+7;

long long ft[MAX];
long long ftinv[MAX];

void init() {
	ft[0] = 1;
	for (int i = 1; i < MAX; i++) {
		ft[i] = (ft[i-1]*i) % M;
	}
	ftinv[MAX - 1] = modpow(ft[MAX - 1], M-2, M);

	for (int i = MAX - 2; i >= 0; i--) {
		ftinv[i] = (ftinv[i+1]*(i+1)) % M;
	}
}

long long nCk(int n, int k) {
	if (k == 0 || k == n) return 1;
	if (k < 0 || k > n) return 0;
	return ft[n] * (ftinv[k] * ftinv[n-k] % M) % M; 
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();
	
	int n, k; cin >> n >> k;

	int elim = 0;
	for (int i = k+1; i <= n; i++) {
		elim = (elim + nCk(n, i)) % M;
	}
	int ans = modpow(2, n, M) % M;
	ans = (ans - elim) % M;
	if (ans < 0) ans += M;
	cout << ans << '\n';

	return 0;
}