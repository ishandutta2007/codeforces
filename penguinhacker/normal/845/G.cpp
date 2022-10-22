#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, eu[mxN], ev[mxN], ew[mxN], tin[mxN], t, dp[mxN];
vector<int> adj[mxN], b;

void add(int x) {
	for (int i : b)
		x=min(x, x^i);
	if (x)
		b.push_back(x);
}

void dfs(int u=0, int p=-1) {
	tin[u]=++t;
	for (int x : adj[u]) {
		if (x==p)
			continue;
		int v=eu[x]^ev[x]^u;
		if (!tin[v]) {
			dp[v]=dp[u]^ew[x];
			dfs(v, x);
		} else if (tin[v]<tin[u])
			add(dp[u]^dp[v]^ew[x]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> eu[i] >> ev[i] >> ew[i], --eu[i], --ev[i];
		if (eu[i]==ev[i])
			add(ew[i]);
		else {
			adj[eu[i]].push_back(i);
			adj[ev[i]].push_back(i);
		}
	}
	dfs();
	int ans=dp[n-1];
	for (int i : b)
		ans=min(ans, ans^i);
	cout << ans;
	return 0;
}