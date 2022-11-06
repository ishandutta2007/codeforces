#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;
set<pair<int, int> > s;
std::vector<int> vv;
std::vector<std::vector<int> > gr;
std::vector<int> vis;
int k;

pair<int, int> dfs(int u, int l) {
	vis[u] = l;
	vv.pb(u);
	for (int v : gr[u]) {
		if ((vis[v]) && (vis[u] - vis[v]) >= k) {
			return {vis[v], vis[u]};
		} else if(!vis[v]) {
			return dfs(v, l + 1);
		}
	}
	return {-1, -1};
}

int32_t main()
{
	int n; cin >> n;
	int m; cin >> m;
	cin >> k;
	gr.resize(n);
	for (int i = 0; i < m; ++i) {
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		gr[u].pb(v);
		gr[v].pb(u);
	}
	vis.resize(n, 0);
	auto pp = dfs(0, 1);
	cout << pp.second - pp.first + 1 << "\n";
	for (int i = pp.first - 1; i < pp.second; ++i) {
		cout << vv[i] + 1 << " ";
	} 
}