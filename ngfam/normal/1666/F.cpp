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

const int MAX = 7001;

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

void solve() {
	int n; cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; mp[-x]++;
	}

	int placed = 0;
	vector<int> dp;

	for (auto [sz, k]: mp) {
		if (dp.empty()) {
			if (k > 1) {
				cout << "0\n";
				return;
			}
			placed = 1;
			dp.resize(n/2 + 1); 
			dp[1] = 1;

			continue;
		}

		vector<int> nxt(n/2 + 1);
		for (int ev = 1; ev <= n/2; ev++) {
			if (ev > placed) continue;
			int slots = (ev - 1) - (placed - ev);
			if (ev == n/2) slots++;
			if (slots < 0) continue;
			if (ev == n/2) {
				// place k items in the remaining slots
				if (slots >= k) {
					nxt[ev] = (nxt[ev] + dp[ev]*nCk(slots, k)) % M;
				}
			} else {
				// two choices
				// place k items in the remaining slots
				if (slots >= k) {
					nxt[ev] = (nxt[ev] + dp[ev]*nCk(slots, k)) % M;
				}
				// place k-1 items in the existing slots, but you get one extra slot
				if (slots >= k-1) {
					nxt[ev+1] = (nxt[ev+1] + dp[ev]*nCk(slots, k-1)) % M;
				}
			}
		}

		placed += k;
		swap(nxt, dp);
	}
	cout << dp[n/2] << '\n';
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