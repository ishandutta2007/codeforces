#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e4;
int n, k, dp[mxN][501];
vector<int> adj[mxN];
ll ans;

void dfs(int u=0, int p=-1) {
	dp[u][0]=1;
	for (int v : adj[u]) {
		if (v==p)
			continue;
		dfs(v, u);
		for (int i=0; i<k; ++i)
			ans+=(ll)dp[v][i]*dp[u][k-i-1];
		for (int i=0; i<k; ++i)
			dp[u][i+1]+=dp[v][i];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	cout << ans;
	return 0;
}