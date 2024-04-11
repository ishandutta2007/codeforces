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

int solve(int n, int gr, int m) {
	if (m == 0) {
		if (n == 0) return 1;
		else return 0;
	}

	int rep = n-gr;
	int fol = gr;

	int ans = 1;
	ans = (ans*modpow(m, rep, M)) % M;
	ans = (ans*modpow(m-1, fol, M)) % M; 

	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();

	int n, m, sum = 0; cin >> n >> m;
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i]; sum += d[i];
	}

	if (sum % 2) {
		cout << modpow(m, n, M) << '\n';
		return 0;
	}

	int grps = 0;
	map<int, int> cnt; int cur = 0;
	for (int i = 0; i < n; i++) {
		cnt[cur % (sum/2)]++;
		if (cnt[cur % (sum/2)] == 2) grps++;
		cur += d[i];
	}

	int ans = 0;
	for (int smgr = 0; smgr <= grps; smgr++) {
		if (smgr > m) break;
		int tmp = 1;

		// pick smgr groups
		tmp = (tmp*nCk(grps, smgr)) % M;

		// pick smgr colors, assign
		tmp = (tmp*nCk(m, smgr)) % M;
		tmp = (tmp*ft[smgr]) % M;

		// the remaining lamps
		int lmps = n - smgr*2;
		int diffgr = grps - smgr;
		int col = m - smgr;
		tmp = (tmp*solve(lmps, diffgr, col)) % M;

		//cout << smgr << ' ' << tmp << '\n';

		ans = (ans + tmp) % M;
	}
	cout << ans << '\n';

	return 0;
}