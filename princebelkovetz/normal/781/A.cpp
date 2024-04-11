#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <cassert>
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
vector <vector <int>> g;
vector <int> col;
int ans = 0;
void dfs(int v, int p) {
	int cur = 1;
	for (auto u : g[v]) {
		if (col[u]) continue;
		while (cur == col[v] or cur == p) cur++;
		col[u] = cur;
		ans = max(ans, cur);
		cur++;
		dfs(u, col[v]);
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(3);
	int n; cin >> n;
	g.resize(n + 1);
	col.resize(n + 1);
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	col[1] = 1;
	dfs(1, -1);
	cout << ans << '\n';
	for (int i = 1; i <= n; ++i) cout << col[i] << ' ';
}