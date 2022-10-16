#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int ans = 0;

		int prev = a[n-1];
		for (int i = n-2; i >= 0; i--) {
			if (a[i] > prev) {
				ans += abs(a[i] - prev);
				prev = a[i];
			} else {
				prev = a[i];
			}
		}
		cout << ans << '\n';
	}

	return 0;
}