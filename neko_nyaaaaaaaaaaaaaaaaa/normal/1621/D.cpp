#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

void solve() {
	int n, preans = 0; cin >> n;
	vector<vector<int>> a(2*n, vector<int>(2*n));
	for (int i = 0; i < 2*n; i++) {
		for (int j = 0; j < 2*n; j++) {
			cin >> a[i][j];
			if (i >= n && j >= n) {
				preans += a[i][j];
				a[i][j] = 0;
			}
		}
	}

	int ans = INF;
	ans = min(ans, a[0][n]);
	ans = min(ans, a[0][2*n-1]);
	ans = min(ans, a[n-1][n]);
	ans = min(ans, a[n-1][2*n-1]);

	ans = min(ans, a[n][0]);
	ans = min(ans, a[2*n-1][0]);
	ans = min(ans, a[n][n-1]);
	ans = min(ans, a[2*n-1][n-1]);

	cout << ans+preans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}