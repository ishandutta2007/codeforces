#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, q;
		cin >> n >> q;
		ar<ll, 2> dp = {0, (ll)-1e18};
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			ar<ll, 2> new_dp = dp;
			new_dp[0] = max(new_dp[0], dp[1] - a);
			new_dp[1] = max(new_dp[1], dp[0] + a);
			swap(dp, new_dp);
		}
		cout << max(dp[0], dp[1]) << "\n";
	}
	return 0;
}