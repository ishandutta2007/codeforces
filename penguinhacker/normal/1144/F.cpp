#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, col[200000], e[200000]; //e is just to store first vertex of an edge
vector<int> adj[200000];

void dfs(int u=0, int p=0) {
	col[u]=p^1;
	for (int v:adj[u]) {
		if (col[v]!=-1) {
			if (col[u]==col[v]) {
				cout << "NO";
				exit(0);
			}
		}
		else {
			dfs(v, col[u]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		col[i]=-1;
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		e[i]=u;
	}
	dfs();
	cout << "YES\n";
	for (int i=0; i<m; ++i)
		cout << col[e[i]];
	return 0;
}