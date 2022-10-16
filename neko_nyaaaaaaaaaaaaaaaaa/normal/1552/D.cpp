#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int sm = 1;
	for (int i = 1; i <= n; i++) {
		sm *= 3;
	}

	for (int ms = 1; ms < sm; ms++) {
		int sum = 0;
		int msk = ms;
		for (int i = 0; i < n; i++) {
			if (msk % 3 == 0) {

			} else if (msk % 3 == 1) {
				sum -= a[i];
			} else if (msk % 3 == 2) {
				sum += a[i];
			}
			msk /= 3;
		}
		if (sum == 0) {
			cout << "YES\n"; return;
		}
	}
	cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}