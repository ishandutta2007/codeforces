#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> ans(n+1, -1e17);
	ans[0] = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			ans[j-i+1] = max(ans[j-i+1], sum);
		}
	}

	for (int k = 0; k <= n; k++) {
		int res = 0;
		for (int len = 0; len <= n; len++) {
			res = max(res, ans[len] + x*min(len, k));
		}
		cout << res << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}