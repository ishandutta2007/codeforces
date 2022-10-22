#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, m, c[100000], visited[100000];
vector<int> adj[100000];
ll ans=0;

int dfs(int s) {
	visited[s] = true;
	int cm = c[s];
	for (int u : adj[s]) {
		if (!visited[u]) {
			cm = min(cm, dfs(u));
		}
	}
	return cm;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> c[i];
		visited[i] = 0;
	}
	for (int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for (int i=0; i<n; ++i) {
		if (!visited[i]) {
			ans += dfs(i);
		}
	}

	cout << ans << '\n';
	return 0;
}