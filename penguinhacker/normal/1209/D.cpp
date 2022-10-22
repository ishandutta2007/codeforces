#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[100000]={};
vector<int> adj[100000];

int dfs(int u) {
	if (visited[u])
		return 0;
	int cnt=1;
	visited[u]=1;
	for (int v:adj[u])
		cnt+=dfs(v);
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int ans=0;
	for (int i=0; i<n; ++i) {
		if (!visited[i])
			ans+=dfs(i)-1;
	}
	
	cout << m-ans << '\n';
	return 0;
}