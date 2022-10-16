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
const long long M = 998244353;

long long ft[MAX];
long long ftinv[MAX];
int pm[MAX];
int npm[MAX];
int pw2[MAX];

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

void init2() {
	npm[0] = npm[1] = 1;
	for (int i = 2; i < MAX; i++) {
		npm[i] = (npm[i-1] + (i-1)*npm[i-2]) % M;
	}

	pm[0] = pm[1] = 1;
	for (int i = 2; i < MAX; i++) {
		pm[i] = (pm[i-2]*i) % M;
	}

	pw2[0] = 1;
	for (int i = 1; i < MAX; i++) {
		pw2[i] = (pw2[i-1]*2) % M;
	}
}

void solve() {
	int n; cin >> n;
	int ans = npm[n];
	for (int i = 4; i <= n; i += 4) {
		int pr = i/2;
		int lf = n-i;

		int pick = nCk(n - pr, pr);
		int p1 = pm[pr-1];
		int p2 = npm[lf];

		int tmp = (p1*p2) % M;
		tmp = (tmp*pick) % M;
		tmp = (tmp*pw2[pr/2]) % M;
		ans = (ans + tmp) % M;

		//cout << pick << ' ' << p1 << ' ' << p2 << endl;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();
	init2();

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}