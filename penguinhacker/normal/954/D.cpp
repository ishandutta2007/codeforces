#include <bits/stdc++.h>
using namespace std;

#define ll long long
int n, m, s, t, dist[1000][2];
bool connected[1000][1000];
vector<int> adj[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(connected, 0, sizeof(connected));
	cin >> n >> m >> s >> t, s--, t--;
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v, u--, v--;
		connected[u][v] = connected[v][u] = 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for (int i=0; i<2; ++i) {
		bool visited[1000] = {0};
		queue<int> q;
		if (i==0) {
			q.push(s); visited[s] = 1; dist[s][i] = 0;
		}
		else {
			q.push(t); visited[t] = 1; dist[t][i] = 0;
		}
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v:adj[u]) {
				if (!visited[v]) {
					visited[v] = 1;
					dist[v][i] = dist[u][i]+1;
					q.push(v);
				}
			}
		}
	}

	int ans = 0;
	for (int i=0; i<n; ++i) {
		for (int j=i+1; j<n; ++j) {
			if (connected[i][j])
				continue;
			if (dist[i][0]+dist[j][1]+1>=dist[t][0] && dist[j][0]+dist[i][1]+1>=dist[t][0])
				ans++;
		}
	}
	cout << ans;
	return 0;
}