#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	
	int prv = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		x = abs(x);
		
		if (i % 2) cout << x << ' ';
		else cout << -x << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}