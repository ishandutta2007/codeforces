#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=500000;
int n, k;
ll dp[mxN][2];
vector<pair<int, int>> adj[mxN];

void dfs(int u=0, int p=-1) {
	vector<ll> a;
	for (auto x : adj[u]) {
		int v=x.first, w=x.second;
		if (v==p)
			continue;
		dfs(v, u);
		dp[u][0]+=dp[v][0];
		a.push_back(dp[v][1]+w-dp[v][0]);
	}
	sort(a.rbegin(), a.rend());
	for (int i=0; i<min((int)a.size(), k); ++i)
		if (a[i]>0)
			dp[u][0]+=a[i];
	dp[u][1]=dp[u][0];
	if (k<=a.size()&&a[k-1]>0)
		dp[u][1]-=a[k-1];
}

void solve() {
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		adj[i].clear();
		dp[i][0]=dp[i][1]=0;
	}
	for (int i=0, u, v, w; i<n-1; ++i) {
		cin >> u >> v >> w, --u, --v;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	dfs();
	cout << dp[0][0] << '\n';
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

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/