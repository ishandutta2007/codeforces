#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, dp[200000], sze[200000];
vector<int> adj[200000];

void dfs(int u=0, int p=-1, int d=0) {
	sze[u]=1;
	for (int v:adj[u])
		if (v!=p) {
			dfs(v, u, d+1);
			sze[u]+=sze[v];
		}
	dp[u]=d-(sze[u]-1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0, u, v; i<n-1; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	sort(dp, dp+n);
	ll ans=0;
	for (int i=n-1; i>=n-k; --i)
		ans+=dp[i];
	cout << ans;
	return 0;
}