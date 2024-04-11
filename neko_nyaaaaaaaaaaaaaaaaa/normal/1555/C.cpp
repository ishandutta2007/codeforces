#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		for (int &i: a) cin >> i;
		for (int &i: b) cin >> i;

		int as = accumulate(a.begin(), a.end(), 0), bs = 0;
		int ans = as;

		for (int i = 0; i < n; i++) {
			as -= a[i];
			ans = min(ans, max(as, bs));
			bs += b[i];
		}
		cout << ans << '\n';
	}

	return 0;
}