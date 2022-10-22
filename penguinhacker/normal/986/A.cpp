#include <bits/stdc++.h>
using namespace std;

int n, m, s, k, prod[100000], dist[100000][101];
vector<int> adj[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k >> s;
	for (int i=0; i<n; ++i)
		cin >> prod[i];
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	memset(dist, 0x3f, sizeof(dist));
	for (int j=1; j<=k; ++j) {
		queue<int> q;
		for (int i=0; i<n; ++i) {
			if (prod[i]==j) {
				dist[i][j] = 0;
				q.push(i);
			}
		}
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v:adj[u]) {
				if (dist[u][j]+1<dist[v][j]) {
					dist[v][j] = dist[u][j]+1;
					q.push(v);
				}
			}
		}
	}
	
	for (int i=0; i<n; ++i) {
		vector<int> v;
		for (int j=1; j<=k; ++j)
			v.push_back(dist[i][j]);
		sort(v.begin(), v.end());
		int ans = 0;
		for (int j=0; j<s; ++j)
			ans += v[j];
		cout << ans << ' ';
	}
	return 0;
}