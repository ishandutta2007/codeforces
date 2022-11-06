#include <bits/stdc++.h>
using namespace std;

int N, M, u, v;
vector<tuple<int, int, bool> > adj[200005];
bitset<200005> vis, eset;
bool inv;
short ed[200005];

void dfs(int n, int p, bool d) {
	if (vis[n]) return;
	vis[n] = 1;
	for (auto u : adj[n]) {
		if (get<1>(u) != p && eset[get<1>(u)] && ed[get<1>(u)] != (get<2>(u) ? !d : d)) {
			inv = 1;
			return;
		}
		eset[get<1>(u)] = 1;
		ed[get<1>(u)] = (get<2>(u) ? !d : d);
		dfs(get<0>(u), get<1>(u), !d);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		adj[u].emplace_back(v, i, 1);
		adj[v].emplace_back(u, i, 0);
	}
	vis.reset();
	eset.reset();
	dfs(1, -1, 0);
	if (!inv) {
		cout << "YES\n";
		for (int i = 0; i < M; i++) cout << ed[i];
		cout << '\n';
		return 0;
	}
	inv = 0;
	vis.reset();
	eset.reset();
	memset(ed, 0, sizeof ed);
	dfs(1, -1, 1);
	if (!inv) {
		cout << "YES\n";
		for (int i = 0; i < M; i++) cout << ed[i];
		cout << '\n';
	} else cout << "NO\n";
}