#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9+7;

int p2[2001];

void init() {
	p2[0] = 1;
	for (int i = 1; i <= 2000; i++) {
		p2[i] = (p2[i-1]*2) % M;
	}
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> cnt(60);
	for (int i: a) {
		for (int j = 0; j < 60; j++) {
			if (i & (1LL << j)) cnt[j]++;
		}
	}

	int ans = 0;
	for (int j = 0; j < n; j++) {
		// left side
		// sum of all (a[i] & a[j])
		int ls = 0;
		for (int b = 0; b < 60; b++) {
			if (a[j] & (1LL << b)) {
				ls = (ls + p2[b]*cnt[b]) % M;
			}
		}

		// how many times enter the sum?
		int rs = 0;
		for (int b = 0; b < 60; b++) {
			if (a[j] & (1LL << b)) {
				// all pairs
				rs = (rs + p2[b]*n) % M;
			} else {
				rs = (rs + p2[b]*cnt[b]) % M;
			}
		}

		ans = (ans + ls*rs) % M;
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