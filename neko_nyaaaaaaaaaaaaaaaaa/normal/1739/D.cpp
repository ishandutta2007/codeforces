#include <bits/stdc++.h>
using namespace std;

bool ok(int n, int k, vector<int> p, int mx) {
	vector<int> deg(n+1);
	for (int i = 2; i <= n; i++) {
		deg[p[i]]++;
	}

	vector<int> dp(n+1, 998244353);
	queue<int> st;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			st.push(i); dp[i] = mx;
		}
	}

	while (st.size()) {
		int u = st.front(); st.pop();
		if (u == 1) break;

		if (dp[u] == 1) {
			dp[p[u]] = min(dp[p[u]], mx);
		} else {
			dp[p[u]] = min(dp[p[u]], dp[u]-1);
		}

		deg[p[u]]--;
		if (deg[p[u]] == 0) st.push(p[u]);
	}

	//for (int i = 1; i <= n; i++) {
	//	cout << dp[i] << ' ';
	//}
	//cout << '\n';

	int ans = 0;
	for (int i = 2; i <= n; i++) {
		if (p[i] != 1 && dp[i] == 1) ans++;
	}
	//cout << ans << '\n';
	return (ans <= k);
}

void solve() {
	int n, k; cin >> n >> k;
	vector<int> p(n+1);
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
	}

	int lo = 1, hi = n;
	while (lo < hi) {
		int mid = (lo + hi)/2;

		//cout << mid << ' ';
		if (ok(n, k, p, mid)) {
			hi = mid;
		} else {
			lo = mid+1;
		}
	}
	cout << lo << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}