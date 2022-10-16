#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

vector<int> dijkstra(int n, int start, vector<vector<pair<int, int>>> adj) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(n, INF);
	vector<int> vis(n);
	dist[start] = 0;
 
	pq.push({0, start});
	while (pq.size()) {
		auto tmp = pq.top();
		int now = tmp.second, w = tmp.first;
		pq.pop();
 
		if (vis[now]) continue;
		vis[now] = 1;
 
		for (auto u: adj[now]) {
			if (dist[now] + u.second < dist[u.first]) {
				dist[u.first] = dist[now] + u.second;
				pq.push({dist[u.first], u.first});
			}
		}
	}
 
	return dist;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n);
	vector<vector<pair<int, int>>> adj2(n+1);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w; u--, v--;
		adj[u].emplace_back(v, w);
		adj2[v].emplace_back(u, w);
	}

	vector<int> d0 = dijkstra(n, 0, adj);
	for (int i = 0; i < n; i++) {
		adj2[n].emplace_back(i, d0[i]);
	}
	vector<int> ans = dijkstra(n+1, n, adj2); 

	for (int i = 1; i < n; i++) {
		if (ans[i] == INF) cout << "-1 ";
		else cout << ans[i] << ' ';
	}

	return 0;
}