#include <bits/stdc++.h>
using namespace std;

int n, c[100000];
vector<int> adj[100000];

bool dfs(int root, int u, int p) {
	if (c[u]!=c[p])
		return 0;
	for (int v:adj[u])
		if (v!=p&&v!=root&&!dfs(root, v, u))
			return 0;
	return 1;
}

bool ok(int u) {
	for (int v:adj[u])
		if (!dfs(u, v, v))
			return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0, u, v; i<n-1; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=0; i<n; ++i)
		cin >> c[i];

	for (int i=0; i<n; ++i) {
		for (int j:adj[i]) {
			if (c[i]!=c[j]) {
				if (ok(i))
					cout << "YES\n" << i+1;
				else if (ok(j))
					cout << "YES\n" << j+1;
				else
					cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES\n" << 1;
	return 0;
}