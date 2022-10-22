#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, p[mxN], l[mxN], r[mxN], dp[mxN], val[mxN];
vector<int> adj[mxN];

void dfs(int u=0) {
	if (adj[u].empty()) {
		dp[u]=1;
		val[u]=r[u];
		return;
	}
	dp[u]=0;
	ll sum=0;
	for (int v : adj[u]) {
		dfs(v);
		sum+=val[v];
		dp[u]+=dp[v];
	}
	sum=min(sum, (ll)r[u]);
	if (sum>=l[u]) {
		val[u]=sum;
		return;
	}
	val[u]=r[u];
	++dp[u];
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		adj[i].clear();
	for (int i=1; i<n; ++i) {
		cin >> p[i], --p[i];
		adj[p[i]].push_back(i);
	}
	for (int i=0; i<n; ++i)
		cin >> l[i] >> r[i];
	dfs();
	cout << dp[0] << "\n";
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