#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const ll INF = 1e18;

int n, m, last[100000];
bool processed[100000];
ll dist[100000];
vector<pi> adj[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0, u, v, w; i<m; ++i) {
		cin >> u >> v >> w, u--, v--;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for (int i=0; i<n; ++i)
		dist[i] = INF;
	
	priority_queue<pair<ll, pi>> q;
	q.push({0, make_pair(0, 0)});
	dist[0] = 0;
	while (!q.empty()) {
		int u = q.top().second.first, l = q.top().second.second;
		q.pop();
		if (processed[u])
			continue;
		processed[u] = 1;
		last[u] = l;
		for (auto v : adj[u]) {
			int a = v.first; int b = v.second;
			if (dist[u]+b < dist[a]) {
				dist[a] = dist[u]+b;
				q.push({-dist[a], make_pair(a, u)});
			}
		}
	}
	if (dist[n-1] == INF)
		cout << -1;
	else {
		vector<int> path;
		int curr = n-1;
		path.push_back(n-1);
		while (curr != 0) {
			curr = last[curr];
			path.push_back(curr);
		}
		reverse(path.begin(), path.end());
		for (int i:path)
			cout << i+1 << ' ';
	}
	return 0;
}