#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &i: a) cin >> i;

	int ans = a[n-1] - a[0];
	for (int i = 1; i < n; i++) {
		ans = max(ans, a[i] - a[0]);
	}
	for (int i = 0; i < n-1; i++) {
		ans = max(ans, a[n-1] - a[i]);
	}
	for (int i = 1; i < n; i++) {
		ans = max(ans, a[i-1] - a[i]);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}