#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mxN = 1e5 + 7, inf = 1e9 + 5;
vector <int> adj[mxN];
bool used[mxN];
int num[mxN];
pair <int, int> dp[mxN];

void dfs(int v) {
	used[v] = true;
	for (auto u : adj[v]) {
		if (used[u]) continue;
		dfs(u);
		dp[v].first = max(dp[v].first, dp[u].first);
		dp[v].second = max(dp[v].second, dp[u].second);
	}
	int cur = num[v] + dp[v].second - dp[v].first;
	if (cur < 0) dp[v].second -= cur;
	if (cur > 0) dp[v].first += cur;
	num[v] = cur;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(2);
	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) cin >> num[i];
	dfs(1);
	//for (int i = 1; i <= n; ++i) cout << dp[i].first << " " << dp[i].second << endl;
	//for (int i = 1; i <= n; ++i) cout << num[i] << " ";
	cout << dp[1].first + dp[1].second;
}