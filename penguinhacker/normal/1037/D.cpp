#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, p[200000], child[200000], par[200000];
vector<int> adj[200000];

void dfs(int u=0, int p=-1) {
	for (int v : adj[u]) {
		if (v != p) {
			child[u]++;
			par[v] = u;
			dfs(v, u);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(child, 0, sizeof(child));
	cin >> n;
	for (int i=0, u, v; i<n-1; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=0; i<n; ++i) cin >> p[i], p[i]--;
	dfs();
	
	if (p[0] != 0) {
		cout << "No";
		return 0;
	}
	int curr=0, bound=1;
	while (bound < n) {
		for (int i=bound; i<bound+child[p[curr]]; ++i) {
			if (par[p[i]] != p[curr]) {
				cout << "No";
				return 0;
			}
		}
		bound += child[p[curr]];
		curr++;
	}
	cout << "Yes";
	return 0;
}