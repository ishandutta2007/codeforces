#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, dp[1000001];
pair<int, int> a[2000], b[2000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i].first >> b[i].second;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x = max(0, b[j].first - a[i].first + 1);
			int y = max(0, b[j].second - a[i].second + 1);
			if (x > 0) {
				dp[x - 1] = max(dp[x - 1], y);
			}
		}
	}
	for (int i = 999999; i >= 0; --i) {
		dp[i] = max(dp[i], dp[i + 1]);
	}
	int ans = INT_MAX;
	for (int i = 0; i <= 1000000; ++i) {
		ans = min(ans, i + dp[i]);
	}
	cout << ans;
	return 0;
}