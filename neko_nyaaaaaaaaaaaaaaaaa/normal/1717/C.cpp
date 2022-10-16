#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	a.push_back(a[0]);
	b.push_back(b[0]);

	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) continue;
		else if (a[i] > b[i]) {
			cout << "NO\n";
			return;
		} else if (b[i] - b[i+1] > 1) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}