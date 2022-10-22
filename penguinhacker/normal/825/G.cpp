#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, q, ans, dp[mxN], mn=mxN;
vector<int> adj[mxN];

void dfs(int u, int p=-1) {
	dp[u]=p^-1?min(u, dp[p]):u;
	for (int v : adj[u])
		if (v^p)
			dfs(v, u);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=1; i<n; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i=0; i<q; ++i) {
		int t, u;
		cin >> t >> u;
		if ((u+=ans)>=n)
			u-=n;
		if (i==0) {
			dfs(u);
		} else if (t==1) {
			mn=min(mn, dp[u]);
		} else {
			cout << (ans=min(mn, dp[u])+1) << "\n";
		}
	}
	return 0;
}