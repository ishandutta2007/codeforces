#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, x;
	cin >> n >> x;

	vector<i64> dp(n+1), res(n+1);
	for (int k = 0; k < n; k++) {
		int y; cin >> y;
		vector<i64> ndp(n+1);
		for (int i = 0; i <= n; i++) {
			ndp[i] = max(dp[i]+y, 0LL);
			if (i > 0) ndp[i] = max(ndp[i], dp[i-1]+x+y);
			res[i] = max(res[i], ndp[i]);
		}
		swap(dp,ndp);
	}
	
	for (int i = 0; i <= n; i++) {
		cout << res[i] << " \n"[i==n];
	}
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}