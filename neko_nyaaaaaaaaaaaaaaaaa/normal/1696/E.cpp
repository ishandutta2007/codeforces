#include <bits/stdc++.h>
using namespace std;

// hockeystick identity

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

const int MXN = 200000;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();

	int n; cin >> n;
	vector<int> cc(MXN+1);
	for (int i = 0; i <= n; i++) {
		int x; cin >> x;
		cc[x]--; cc[0]++;
	}
	for (int i = 1; i <= MXN; i++) {
		cc[i] += cc[i-1];
	}

	int ans = 0;
	for (int i = 0; i <= MXN; i++) {
		if (cc[i] == 0) continue;
		ans = (ans + nCk(i+cc[i], i+1)) % M;
	}
	cout << ans << '\n';

	return 0;
}