#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int eq = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i-1]) eq++;
	}
	if (eq <= 1) {
		cout << "0\n";
		return;
	}

	int l = n, r = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i-1]) {
			l = min(l, i);
			r = max(r, i);
		}
	}

	if (r-l == 1) {
		cout << "1\n";
	} else {
		cout << r-l-1 << '\n';
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