#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <cstring>
#include <queue>
#include <map>
#define int long long
#define endl "\n"
#define debug(x) cout << #x << " actually equals " << x << endl

using namespace std;
const int mxN = 1e5 + 7, mod = 1e9 + 7;
vector <int> adj[mxN], readj[mxN], topsort;
int cost[mxN], used[mxN], kpp[mxN];

void dfs(int u) {
	used[u] = true;
	for (auto v : readj[u]) {
		if (used[v]) continue;
		dfs(v);
	}
	topsort.push_back(u);
}
void dfs2(int u, int &c) {
	used[u] = true;
	kpp[u] = c;
	for (auto v : adj[u]) {
		if (used[v]) continue;
		dfs2(v, c);
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(3);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> cost[i];
	int m; cin >> m;
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		readj[v].push_back(u);
	}
	memset(used, false, sizeof(used));
	for (int i = 1; i <= n; ++i) {
		if (used[i]) continue;
		dfs(i);
	}
	memset(used, false, sizeof(used));
	int c = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (used[topsort[i]]) continue;
		++c;
		dfs2(topsort[i], c);
	}
	cout << endl;
	vector <int> minCost(c + 1, 1e9), nummin(c + 1, 0);
	
	for (int i = 1; i <= n; ++i) {
		if (minCost[kpp[i]] > cost[i]) {
			minCost[kpp[i]] = cost[i];
			nummin[kpp[i]] = 1;
		}
		else if (minCost[kpp[i]] == cost[i]) nummin[kpp[i]]++;
	}
	int ans = 0, nums = 1;
	for (int i = 1; i <= c; ++i) {
		ans += minCost[i];
		nums = (nums * nummin[i]) % mod;
	}
	cout << ans << " " << nums;
	return 0;
}