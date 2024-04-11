#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, INF=1e9;
int n, m, d, ans;
bool b[mxN];
vector<int> adj[mxN];
ar<int, 2> dp[mxN];

void ins(ar<int, 2>& x, int y) {
	if (y>x[0])
		x={y, x[0]};
	else if (y>x[1])
		x[1]=y;
}

void dfs1(int u=0, int p=-1) {
	if (b[u])
		ins(dp[u], 0);
	for (int v : adj[u])
		if (v^p)
			dfs1(v, u), ins(dp[u], dp[v][0]+1);
}

void dfs2(int u=0, int p=-1) {
	ans+=dp[u][0]<=d;
	for (int v : adj[u]) {
		if (v==p)
			continue;
		ins(dp[v], (dp[v][0]+1==dp[u][0]?dp[u][1]:dp[u][0])+1);
		dfs2(v, u);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> d;
	for (int i=0; i<m; ++i) {
		int x;
		cin >> x, --x;
		b[x]=1;
	}
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fill(dp, dp+n, ar<int, 2>{-INF, -INF});
	dfs1();
	dfs2();
	cout << ans;
	return 0;
}