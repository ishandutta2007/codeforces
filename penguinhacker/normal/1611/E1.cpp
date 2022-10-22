#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, INF=1e9;
int n, k, d[mxN], dp[mxN];
bool has[mxN];
vector<int> adj[mxN];

void dfs1(int u=0, int p=-1) {
	dp[u]=has[u]?0:INF;
	for (int v : adj[u])
		if (v^p) {
			d[v]=d[u]+1;
			dfs1(v, u);
			dp[u]=min(dp[u], dp[v]+1);
		}
}

bool dfs2(int u=0, int p=-1) {
	if (d[u]>=dp[u])
		return 0;
	if (u&&adj[u].size()==1)
		return 1;
	for (int v : adj[u])
		if (v^p&&dfs2(v, u))
			return 1;
	return 0;
}

void solve() {
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		adj[i].clear();
		has[i]=0;
	}
	for (int i=0; i<k; ++i) {
		int x;
		cin >> x, --x;
		has[x]=1;
	}
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1();
	cout << (dfs2()?"YES":"NO") << "\n";
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