#include <bits/stdc++.h>
using namespace std;

int n, m, k, has = 0;
vector<int> adj[200001];
vector<int> spec(200001);

vector<int> solve_bfs() {
	vector<int> dist(200001, 10000000);
	vector<int> vis(200001);
	queue<int> q;
	q.push(1); dist[1] = 0; vis[1] = 1;

	while (q.size()) {
		int u = q.front(); q.pop();

		for (int v: adj[u]) {
			if (!vis[v]) {
				vis[v] = 1;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return dist;
}

vector<int> adj2[200001];
vector<int> vs(200001);
vector<int> yes(200001);

int dfs(int now) {
	vs[now] = 1;
	if (now == n) return yes[now] = 1;

	int rs = 0;
	for (int u: adj2[now]) {
		if (!vs[u]) rs |= dfs(u);		
		else rs |= yes[u];
	}
	return yes[now] = rs;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;
	while (k--) {
		int x; cin >> x;
		spec[x] = 1;
	}
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);

		if (spec[x] && spec[y]) has = 1;
	}
	vector<int> d = solve_bfs();
	if (has) {
		cout << d[n] << '\n';
		exit(0);
	}

	for (int i = 1; i <= n; i++) {
		for (int u: adj[i]) {
			if (abs(d[u] - d[i]) == 1) {
				adj2[i].push_back(u);
			}
		}
	}
	dfs(1);

	int x = -1, y = -1;
	for (int i = 1; i <= n; i++) {
		if (!yes[i]) {
			d[i] = 10000000;
			if (spec[i]) x = i;
		}
	}
	if (x != -1) {
		for (int i = 1; i <= n; i++) {
			if (spec[i] && i != x) y = i;
		}
	} else {
		vector<pair<int, int>> sp;
		for (int i = 1; i <= n; i++) {
			if (spec[i]) sp.emplace_back(d[i], i);
		}
		sort(sp.begin(), sp.end());

		int mn_diff = 100000000;
		for (int i = 1; i < sp.size(); i++) {
			int ab = abs(sp[i].first - sp[i-1].first);
			if (ab < mn_diff) {
				mn_diff = ab;
				x = sp[i].second;
				y = sp[i-1].second;
			}

		}
	}
	adj[x].push_back(y);
	adj[y].push_back(x);

	vector<int> anss = solve_bfs();
	cout << anss[n] << '\n';

	return 0;
}