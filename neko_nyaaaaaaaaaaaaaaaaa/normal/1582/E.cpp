#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

void solve() {
	int n; cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	reverse(a.begin()+1, a.end());
	for (int i = 1; i <= n; i++) {
		a[i] += a[i-1];
	}

	vector<int> dp(n+1, INF);
	for (int k = 1; k <= 500; k++) {
		vector<int> nxt(n+1, -INF);

		bool ok = 0;
		int mx = dp[0];
		for (int i = 1; i+k-1 <= n; i++) {
			int sum = a[i+k-1] - a[i-1];
			if (sum < mx) {
				nxt[i+k-1] = sum;
				ok = 1;
			}
			mx = max(mx, dp[i]);
		}

		if (!ok) {
			cout << k-1 << '\n';
			return;
		}
		swap(dp, nxt);
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}