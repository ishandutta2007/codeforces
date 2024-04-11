#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, c[200000], dp[200000];
vector<int> adj[200000];

void dfs1(int u=0, int p=-1) {
	dp[u]=c[u];
	for (int v : adj[u])
		if (v!=p) {
			dfs1(v, u);
			if (dp[v]>0)
				dp[u]+=dp[v];
		}
}

void dfs2(int u=0, int p=-1) {
	if (u!=0) {
		int x=dp[p]-(dp[u]>0?dp[u]:0);
		if (x>0)
			dp[u]+=x;
	}
	for (int v : adj[u])
		if (v!=p)
			dfs2(v, u);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> c[i];
		if (c[i]==0)
			c[i]=-1;
	}
	for (int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1();
	dfs2();
	for (int i=0; i<n; ++i)
		cout << dp[i] << ' ';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/