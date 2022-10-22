#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
vector <vector <int>> a;
vector <int> cost, sum, res;
vector <bool> used;
void dfs(int v) {
	used[v] = true;
	for (auto u : a[v]) {
		if (used[u]) continue;
		dfs(u);
		sum[v] += sum[u];
		res[v] += res[u];
	}
	res[v] += sum[v];
	sum[v] += cost[v];
}
void dfs2(int v) {
	used[v] = true;
	for (auto u : a[v]) {
		if (used[u]) continue;
		res[u] = res[v] - sum[u] + sum[1] - sum[u];
		dfs2(u);
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int n; cin >> n;
	a.resize(n + 1);
	cost.resize(n + 1);
	sum.resize(n + 1);
	res.resize(n + 1);
	used.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> cost[i];
	for (int i = 0; i < n - 1; ++i) {
		int u, v; cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i)
		used[i] = false;
	dfs2(1);
	int ans = 0;
	for (auto x : res)
		ans = max(ans, x);
	cout << ans << '\n';

}