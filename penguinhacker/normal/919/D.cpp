#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, m, vis[mxN], dp[mxN][26], ans;
vector<int> adj[mxN], ord;
string s;

void dfs(int u) {
	++vis[u];
	for (int v : adj[u]) {
		if (!vis[v])
			dfs(v);
		else if (vis[v]==1) {
			cout << -1;
			exit(0);
		}
	}
	++vis[u];
	ord.push_back(u);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s;
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[v].push_back(u);
	}
	for (int i=0; i<n; ++i)
		if (!vis[i])
			dfs(i);
	for (int i=0; i<n; ++i) {
		int u=ord[i];
		//cout << u << " ";
		for (int v : adj[u])
			for (int j=0; j<26; ++j)
				dp[u][j]=max(dp[u][j], dp[v][j]);
		++dp[u][s[u]-'a'];
		ans=max(ans, *max_element(dp[u], dp[u]+26));
	}
	cout << ans;
	return 0;
}