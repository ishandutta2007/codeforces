#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const ll INF = 1e18;

int n, m, k;
vector<pair<pi, int>> adj[300000]; //<adjacent, weight, ind>
ll dist[300000];
bool processed[300000] = {0};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=1, u, v, w; i<=m; ++i) {
		cin >> u >> v >> w, u--, v--;
		adj[u].push_back({{v, w}, i});
		adj[v].push_back({{u, w}, i});
	}
	for (int i=0; i<n; ++i)
		dist[i] = INF;
	
	vector<int> ans_set;
	priority_queue<pair<pair<ll, int>, int>> q; //length, node, edge
	q.push({{0, 0}, 0});
	dist[0] = 0;
	while (!q.empty()) {
		int u = q.top().first.second;
		int edge = q.top().second;
		q.pop();
		if (processed[u])
			continue;
		processed[u] = 1;
		ans_set.push_back(edge);
		for (auto x:adj[u]) {
			int v = x.first.first;
			int w = x.first.second;
			int ind = x.second;
			if (dist[u]+w<dist[v]) {
				dist[v] = dist[u]+w;
				q.push({{-dist[v], v}, ind});
			}
		}
	}
	int toPrint = min(k, (int) ans_set.size()-1);
	cout << toPrint << '\n';
	for (int i=1; i<=toPrint; ++i)
		cout << ans_set[i] << ' ';
	return 0;
}