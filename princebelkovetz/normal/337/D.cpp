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
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
vector <vector <int>> a, all;
set <int> evil;
vector <bool> used;
vector <int> distunder, distup;
void dfs(int v) {
	used[v] = true;
	if (evil.find(v) != evil.end()) {
		distunder[v] = 0;
		distup[v] = 0;
	}
	for (auto u : a[v]) {
		if (used[u]) continue;
		dfs(u);
		distunder[v] = max(distunder[v], distunder[u] + 1);
		all[v].push_back(distunder[u]);
	}
	sort(all[v].rbegin(), all[v].rend());
}
void dfs2(int v) {
	used[v] = true;
	for (auto u : a[v]) {
		if (used[u]) continue;
		distup[u] = max(distup[v] + 1, distup[u]);
		if (all[v].size() > 1) {
			if (distunder[u] >= all[v][0])
				distup[u] = max(distup[u], all[v][1] + 2);
			else
				distup[u] = max(distup[u], all[v][0] + 2);
		}
		dfs2(u);
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int n, m, d; cin >> n >> m >> d;
	a.resize(n + 1); all.resize(n + 1);
	distunder.resize(n + 1, -1e9);
	used.resize(n + 1);
	distup.resize(n + 1, -1e9);
	for (int i = 0; i < m; ++i) {
		int x; cin >> x;
		evil.insert(x);
	}
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
	for (int i = 1; i <= n; ++i)
		if (distunder[i] <= d and distup[i] <= d) 
			++ans;
	cout << ans << '\n';
}