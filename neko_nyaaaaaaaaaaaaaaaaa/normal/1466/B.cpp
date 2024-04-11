#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> x(n);
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}

		for (int i = 1; i < n; i++) {
			if (x[i] <= x[i-1]) x[i]++;
		}

		set<int> ans;
		for (int i = 0; i < n; i++) {
			ans.insert(x[i]);
		}
		cout << ans.size() << '\n';
	}

	return 0;
}