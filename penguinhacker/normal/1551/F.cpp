#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=1e9+7;
int n, k, d[100][100];
vector<int> adj[100];
ll ans, dp[100];

void dfs(int u, int p, int c, int rt) {
	++d[rt][c];
	for (int v : adj[u])
		if (v^p)
			dfs(v, u, c+1, rt);
}

void cmp(vector<int>& v) {
	memset(dp, 0, sizeof(dp));
	dp[0]=1;
	for (int i=0; i<v.size(); ++i)
		for (int j=min(i+1, k); j; --j)
			dp[j]=(dp[j]+dp[j-1]*v[i])%M;
	ans=(ans+dp[k])%M;
}

void solve() {
	cin >> n >> k;
	for (int i=0; i<n; ++i)
		adj[i].clear();
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (k==2) {
		cout << n*(n-1)/2 << "\n";
		return;
	}
	ans=0;
	for (int i=0; i<n; ++i) {
		memset(d, 0, sizeof(d));
		for (int j : adj[i])
			dfs(j, i, 1, j);
		for (int j=1; j<n; ++j) {
			vector<int> v;
			for (int k2 : adj[i])
				if (d[k2][j])
					v.push_back(d[k2][j]);
			if (v.size()<k)
				continue;
			cmp(v);
		}
	}
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