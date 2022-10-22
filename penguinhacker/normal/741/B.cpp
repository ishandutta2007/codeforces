#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, W, w[1000], b[1000], dp[1001]={}, dp2[1001];
bool vis[1000]={};
vector<int> adj[1000];
vector<pair<int, int>> items;

pair<int, int> dfs(int u) {
	vis[u]=1;
	int currw=w[u], currb=b[u];
	items.push_back({w[u], b[u]});
	for (int v:adj[u])
		if (!vis[v]) {
			pair<int, int> x=dfs(v);
			currw+=x.first;
			currb+=x.second;
		}
	return {currw, currb};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> W;
	for (int i=0; i<n; ++i)
		cin >> w[i];
	for (int i=0; i<n; ++i)
		cin >> b[i];
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for (int i=0; i<n; ++i) {
		if (vis[i])
			continue;
		items.clear();
		items.push_back(dfs(i));
		for (int i=0; i<=W; ++i)
			dp2[i]=dp[i]; //dp2 is old dp
		for (pair<int, int> x:items) {
			int currw=x.first, currb=x.second;
			for (int j=currw; j<=W; ++j)
				dp[j]=max(dp[j], dp2[j-currw]+currb);
		}
	}
	int ans=0;
	for (int i=0; i<=W; ++i)
		ans=max(ans, dp[i]);
	cout << ans;
	return 0;
}