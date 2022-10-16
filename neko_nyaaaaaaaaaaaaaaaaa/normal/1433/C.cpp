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

		int mx = *max_element(a.begin(), a.end());
		int mn = *min_element(a.begin(), a.end());

		if (mx == mn) cout << "-1\n";
		else {
			int ans = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] != mx) continue;
				if (i > 0 && a[i] != a[i-1]) {
					ans = i+1; break;
				}
				if (i+1 < n && a[i] != a[i+1]) {
					ans = i+1; break;
				}
			}
			cout << ans << '\n';
		}
	}

	return 0;
}