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

		int l = 0, r = 0;
		for (int i = 0; i < n; i++) {
			if (a[i]) r = i;
		}
		for (int i = n-1; i >= 0; i--) {
			if (a[i]) l = i;
		}

		int ans = 0;
		for (int i = l; i <= r; i++) {
			ans += (a[i] == 0);
		}
		cout << ans << '\n';
	}

	return 0;
}