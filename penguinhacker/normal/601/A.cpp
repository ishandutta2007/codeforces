#include <bits/stdc++.h>
using namespace std;

int n, m, dist[401];
vector<int> adj[401];
bool edge[401][401], visited[401]={0};
bool who = 0; //1 for train (given edges)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(edge, 0, sizeof(edge));
	cin >> n >> m;
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v;
		edge[u][v] = 1;
		edge[v][u] = 1;
	}
	for (int i=1; i<=n; ++i)
		dist[i] = -1;

	if (edge[1][n]) {
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=n; ++j) {
				if (i!=j&&!edge[i][j]) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
	}
	else {
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=n; ++j) {
				if (i!=j&&edge[i][j]) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
	}

	queue<int> q;
	q.push(1);
	dist[1] = 0;
	visited[1] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int u:adj[x]) {
			if (!visited[u]) {
				visited[u] = 1;
				q.push(u);
				dist[u] = dist[x]+1;
			}
		}
	}
	cout << dist[n];
	return 0;
}