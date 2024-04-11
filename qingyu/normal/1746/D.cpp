#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 50;

int64_t a[N];
vector<int> adj[N];
map<int, int64_t> dp[N];

int64_t solve(int x, int64_t k) {
	if (!k)
		return 0;
	if (dp[x].count(k))
		return dp[x][k];
	if (adj[x].empty()) {
		return dp[x][k] = k * a[x];
	}
	int64_t ans = k * a[x];
	int t = k / adj[x].size(), z = k % adj[x].size();
	if (!z) {
		for (int y : adj[x])
			ans += solve(y, t);
		return dp[x][k] = ans;
	}
	vector<int64_t> rec;
	for (int y : adj[x]) {
		int64_t v1 = solve(y, t), v2 = solve(y, t + 1);
		rec.push_back(v1 - v2);
		ans += v1;
	}
	nth_element(rec.begin(), rec.begin() + z, rec.end());
	for (int i = 0; i < z; ++i) ans -= rec[i];
	return dp[x][k] = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		for (int i = 2; i <= n; ++i) {
			int x;
			cin >> x;
			adj[x].push_back(i);
		}
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		cout << solve(1, k) << "\n";
		for (int i = 1; i <= n; ++i) {
			adj[i].clear();
			dp[i].clear();
		}
	}
	return 0;
}