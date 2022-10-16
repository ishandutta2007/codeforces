#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	vector<pair<int, int>> a(n+1);
	for (int i = 1; i <= n; i++) {
	      cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	vector<int> dp(n+1, 0);
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
	      int pos = lower_bound(a.begin(), a.begin()+i, make_pair(a[i].first - a[i].second, 0)) - a.begin() - 1;
	      dp[i] = (pos == -1 ? 0 : dp[pos]) + 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
	      ans = max(ans, dp[i]);
	}
	cout << n - ans;
	
	return 0;
}