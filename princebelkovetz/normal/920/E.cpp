#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <queue>
using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
const int N = 1e6 + 2, mod = 1e9 + 7, mod2 = 998244353;
set <int> unused;
vector <set <int>> g;
vector <int> color;
int c = 0;
void dfs(int v) {
	unused.erase(v);
	color[v] = c;
	int cur = 0;
	while (true) {
		auto it = unused.upper_bound(cur);
		if (it == unused.end()) break;
		cur = *it;
		if (g[v].find(cur) == g[v].end())
			dfs(cur);
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n, m; cin >> n >> m;
	g.resize(n + 1);
	color.resize(n + 1);
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	for (int i = 1; i <= n; ++i)
		unused.insert(i);
	for (int i = 1; i <= n; ++i) {
		if (unused.find(i) == unused.end()) continue;
		dfs(i);
		c++;
	}
	vector <int> cnt(c);
	for (int i = 1; i <= n; ++i)
		cnt[color[i]]++;
	sort(cnt.begin(), cnt.end());
	cout << cnt.size() << '\n';
	for (auto x : cnt) cout << x << ' ';
	cout << '\n';
	return 0;
}