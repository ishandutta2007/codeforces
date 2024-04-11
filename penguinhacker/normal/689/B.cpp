#include <bits/stdc++.h>
using namespace std;

int n, dist[200000];
vector<int> adj[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0, u; i<n; ++i) {
		cin >> u, u--;
		adj[i].push_back(u);
		if (i>0)
			adj[i].push_back(i-1);
		if (i<n-1)
			adj[i].push_back(i+1);
	}

	memset(dist, 0x3f, sizeof(dist));
	queue<int> q;
	q.push(0); dist[0] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v:adj[u]) {
			if (dist[u]+1<dist[v]) {
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
	for (int i=0; i<n; ++i)
		cout << dist[i] << ' ';
	return 0;
}