#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=4e5, M=1e9+7;
int n, a[mxN][2];
bool vis[mxN];
vector<int> adj[mxN];

void dfs(int u) {
	vis[u]=1;
	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
}

void solve() {
	cin >> n;
	for (int j : {0, 1})
		for (int i=0; i<n; ++i)
			cin >> a[i][j], --a[i][j];
	for (int i=0; i<n; ++i) {
		adj[i].clear();
		vis[i]=0;
	}
	for (int i=0; i<n; ++i) {
		int u=a[i][0], v=a[i][1];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans=1;
	for (int i=0; i<n; ++i)
		if (!vis[i])
			dfs(i), ans=2*ans%M;
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}