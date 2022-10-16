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

		set<int> ans;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				ans.insert(abs(x[i] - x[j]));
			}
		}
		cout << ans.size() << '\n';
	}

	return 0;
}