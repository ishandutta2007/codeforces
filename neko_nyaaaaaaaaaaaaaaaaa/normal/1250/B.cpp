#include <bits/stdc++.h>
using namespace std;

const long long M = 1e9+7;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<int> dp(10001);
	dp[0] = 1;
	int ans = 0;
	while (n--) {
		int x; cin >> x;
		vector<int> nxt(10001);
		for (int i = 0; i <= 10000; i++) {
			if (i+x <= 10000)
				nxt[i+x] = (nxt[i+x] + dp[i]) % M;
			if (abs(i-x) <= 10000) {
				nxt[abs(i-x)] = (nxt[abs(i-x)] + dp[i]) % M;
			}
		}
		ans = (ans + nxt[0]) % M;

		swap(dp, nxt);
		dp[0] = (dp[0] + 1) % M;
	}
	cout << ans << '\n';

	return 0;
}