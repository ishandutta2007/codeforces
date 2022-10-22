#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, l[mxN], r[mxN];
vector<int> adj[mxN];
ll dp[mxN][2];

void dfs(int u=0, int p=-1) {
	dp[u][0]=dp[u][1]=0;
	for (int v : adj[u]) {
		if (v==p)
			continue;
		dfs(v, u);
		dp[u][0]+=max(dp[v][0]+abs(l[u]-l[v]), dp[v][1]+abs(l[u]-r[v]));
		dp[u][1]+=max(dp[v][0]+abs(r[u]-l[v]), dp[v][1]+abs(r[u]-r[v]));
	}
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> l[i] >> r[i];
		adj[i].clear();
	}
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	cout << max(dp[0][0], dp[0][1]) << "\n";
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