#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, L, R, sum = 0; cin >> n >> L >> R;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].second;
		sum += a[i].second;
		a[i].second *= -1;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
	}
	sort(a.begin(), a.end());
	int l = sum - R, r = sum - L;

	vector<int> dp(sum+1, -998244353);
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		int x = -a[i].second;
		for (int j = sum; j >= x; j--) {
			dp[j] = max(dp[j], dp[j - x] + a[i].first*(j >= l && j <= r));
		}
	}
	cout << *max_element(dp.begin(), dp.end()) << '\n';

	return 0;
}