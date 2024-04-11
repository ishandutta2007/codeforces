#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n+2);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > a[i-1] && a[i] > a[i+1]) ans += a[i];
		if (a[i] < a[i-1] && a[i] < a[i+1]) ans -= a[i];
	}

	cout << ans << '\n';
	while (q--) {
		int l, r; cin >> l >> r;

		set<int> tc;
		tc.insert(l-1); tc.insert(l); tc.insert(l+1);
		tc.insert(r-1); tc.insert(r); tc.insert(r+1);

		for (int i: tc) {
			if (a[i] > a[i-1] && a[i] > a[i+1]) ans -= a[i];
			if (a[i] < a[i-1] && a[i] < a[i+1]) ans += a[i];
		}

		swap(a[l], a[r]);

		for (int i: tc) {
			if (a[i] > a[i-1] && a[i] > a[i+1]) ans += a[i];
			if (a[i] < a[i-1] && a[i] < a[i+1]) ans -= a[i];
		}

		cout << ans << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}