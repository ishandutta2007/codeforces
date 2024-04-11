#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=200000;
int n, k, sub[mxN];
ll dp[mxN];
bool b[mxN];
vector<int> adj[mxN];

void dfs(int u=0, int p=-1) {
	sub[u]=b[u];
	for (int v: adj[u]) if (v!=p) {
		dfs(v, u);
		sub[u]+=sub[v];
		dp[u]+=dp[v];
		dp[u]+=sub[v];
	}
}
ll ans=1e18;
void dfs2(int u=0, int p=-1) {
	ans=min(ans, dp[u]);
	for (int v: adj[u]) if (v!=p) {
		dp[v]=dp[u]+2*k-2*sub[v];
		dfs2(v, u);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<2*k; ++i) {
		int a; cin >> a, --a;
		b[a]=1;
	}
	for (int i=1; i<n; ++i) {
		int u, v; cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	dfs2();
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/