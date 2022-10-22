#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, p, k, x, y, a[100000], dp[100000];

int cost(int i) { //start from ith block
	int jumps = (n - i - 1) / k;
	int ret = dp[i + k * jumps] - dp[i] + a[i]; //number of filled blocks
	return x * (jumps + 1 - ret);
}

void solve() {
	cin >> n >> p >> k, --p;
	string temp; cin >> temp;
	for (int i = 0; i < n; ++i) {
		a[i] = temp[i] - '0';
		dp[i] = a[i] + (i >= k ? dp[i - k] : 0);
	}
	cin >> x >> y;
	int ans = cost(p);
	int cur = 0;
	for (int i = 0; i < n - p - 1; ++i) {
		cur += y;
		ans = min(ans, cur + cost(p + i + 1));
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}