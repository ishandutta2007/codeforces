#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 998244353;

long long modpow(long long n, long long k, long long MOD) {
	long long ans = 1;
	while (k > 0) {
		if (k & 1) ans = (ans*n) % MOD;
		n = (n*n) % MOD; k >>= 1;
	}
	return ans;
}

const int MAX = 1000001;

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

int getEq(int v1, int v2) {
	if (v1 == 0 || v2 == 0) return 1;

	int ans = 1;
	for (int i = 1; i <= min(v1, v2); i++) {
		int p1 = nCk(v1, i);
		int p2 = nCk(v2, i);
		int cz = ft[i];

		int tmp = 1;
		tmp = (tmp*p1) % M;
		tmp = (tmp*p2) % M;
		//tmp = (tmp*cz) % M;

		ans = (ans+tmp) % M;
	}
	return ans;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n+1);
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		tot += a[i];
	}
	if (tot == 0) {
		int ans = 1;
		for (int i = 1; i < n; i++) {
			ans = (ans*2) % M;
		}
		cout << ans << '\n';
		return;
	}

	map<int, int> mp1, mp2;
	int sm = 0, ct = 0;
	for (int i = 1; i <= n; i++) {
		sm += a[i];
		if (sm*2 < tot) {
			mp1[sm]++;
		} else if (sm*2 == tot) {
			ct++;
		}
	}

	sm = 0;
	for (int i = n; i >= 1; i--) {
		sm += a[i];
		if (sm*2 < tot) {
			mp2[sm]++;
		}
	}

	int ans = 1;
	for (auto [u, v1]: mp1) {
		int v2 = mp2[u];

		int tmp = getEq(v1, v2);
		ans = (ans*tmp) % M;
	}

	for (int i = 1; i <= ct; i++) {
		ans = (ans*2) % M;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}