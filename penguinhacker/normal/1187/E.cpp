#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, s[mxN];
vector<int> adj[mxN];
ll dp[mxN], ans;

void dfs1(int u=0, int p=-1) {
	s[u]=1;
	for (int v : adj[u])
		if (v^p) {
			dfs1(v, u);
			s[u]+=s[v];
			dp[u]+=dp[v];
		}
	dp[u]+=s[u];
}

void dfs2(int u=0, int p=-1) {
	ans=max(ans, dp[u]);
	for (int v : adj[u])
		if (v^p) {
			ll du=dp[u];
			dp[u]-=dp[v]+s[v];
			dp[v]+=dp[u]+n-s[v];
			dfs2(v, u);
			dp[u]=du;
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1();
	dfs2();
	cout << ans;
	return 0;
}