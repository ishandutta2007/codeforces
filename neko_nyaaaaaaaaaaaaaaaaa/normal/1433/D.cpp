#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		vector<pair<int, int>> ans;
		for (int i = 1; i < n; i++) {
			if (a[i] != a[0]) {
				ans.emplace_back(1, i+1);
			}
		}

		for (int j = 0; j < n; j++) {
			if (a[j] != a[0]) {
				for (int i = 1; i < n; i++) {
					if (a[i] == a[0]) {
						ans.emplace_back(i+1, j+1);
					}
				}
				break;
			}
		}

		if (ans.empty()) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (auto [u, v]: ans) cout << u << ' ' << v << '\n';
		}
	}

	return 0;
}