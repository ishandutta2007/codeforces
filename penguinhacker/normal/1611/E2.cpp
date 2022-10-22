#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, INF=1e9;
int n, k, x[mxN], d[mxN], anc[mxN][18], dp[mxN];
vector<int> adj[mxN];
bool has[mxN];

void dfs(int u=0, int p=-1) {
	for (int i=1; i<18; ++i)
		anc[u][i]=anc[anc[u][i-1]][i-1];
	for (int v : adj[u])
		if (v^p) {
			d[v]=d[u]+1;
			anc[v][0]=u;
			dfs(v, u);
		}
}

int lift(int u, int a) {
	for (int i=0; i<18; ++i)
		if (a&1<<i)
			u=anc[u][i];
	return u;
}

void dfs2(int u=0, int p=-1) {
	if (has[u]) {
		dp[u]=1;
		return;
	}
	if (u&&adj[u].size()==1) {
		dp[u]=INF;
		return;
	}
	dp[u]=0;
	for (int v : adj[u])
		if (v^p) {
			dfs2(v, u);
			dp[u]=min(INF, dp[u]+dp[v]);
		}
}

void solve() {
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		adj[i].clear();
		has[i]=0;
	}
	for (int i=0; i<k; ++i)
		cin >> x[i], --x[i];
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	for (int i=0; i<k; ++i)
		has[lift(x[i], d[x[i]]/2)]=1;
	dfs2();
	cout << (dp[0]==INF?-1:dp[0]) << "\n";
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