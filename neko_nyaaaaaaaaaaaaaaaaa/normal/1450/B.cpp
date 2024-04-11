#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		int at = 0;
		for (int j = 0; j < n; j++) {
			int dist = abs(x[i] - x[j]);
			dist += abs(y[i] - y[j]);

			if (dist <= k) at++;
		}
		if (at == n) {
			cout << "1\n";
			return;
		}
	}
	cout << "-1\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}