#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	int ans = 0;

	for (int i = 0; i < 9; i++) {
		vector<int> a, b;
		for (int j = 1; j <= n; j++) {
			if (j & (1 << i)) a.push_back(j);
			else b.push_back(j);
		}

		if (a.size() == 0 || b.size() == 0) break;

		cout << a.size() << ' ' << b.size() << ' ';
		for (int j: a) cout << j << ' ';
		for (int j: b) cout << j << ' ';
		cout << endl;

		int x; cin >> x;
		if (x == -1) exit(0);
		ans = max(ans, x);
	}
	cout << "-1 " << ans << endl;
}

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}