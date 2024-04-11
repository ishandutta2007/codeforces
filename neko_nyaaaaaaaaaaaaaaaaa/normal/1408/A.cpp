#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n), b(n), c(n);
		for (int &i: a) cin >> i;
		for (int &i: b) cin >> i;
		for (int &i: c) cin >> i;

		int prv = 0;
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (a[i] != prv) {
				ans.push_back(a[i]);
				prv = a[i];
			} else if (b[i] != prv) {
				ans.push_back(b[i]);
				prv = b[i];
			} else {
				ans.push_back(c[i]);
				prv = c[i];
			}
		}

		if (a[0] != ans[1] && a[0] != ans[n-1]) ans[0] = a[0];
		else if (b[0] != ans[1] && b[0] != ans[n-1]) ans[0] = b[0];
		else ans[0] = c[0];

		for (int i: ans) cout << i << ' ';
			cout << '\n';
	}

	return 0;
}