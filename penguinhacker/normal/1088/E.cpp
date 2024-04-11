#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
const ll INF=1e18;
int n, a[mxN];
vector<int> adj[mxN];
ll dp[mxN], best, cnt_best;

void dfs1(int u=0, int p=-1) {
	dp[u]=a[u];
	for (int v : adj[u]) {
		if (v==p)
			continue;
		dfs1(v, u);
		dp[u]+=max(0ll, dp[v]);
	}
}

void dfs2(int u=0, int p=-1) {
	dp[u]=a[u];
	for (int v : adj[u]) {
		if (v==p)
			continue;
		dfs2(v, u);
		dp[u]+=max(0ll, dp[v]);
	}
	//cout << dp[u] << endl;
	if (dp[u]==best) {
		++cnt_best;
		dp[u]=-INF;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (*max_element(a, a+n)<=0) {
		ll mx=*max_element(a, a+n);
		int cnt=count(a, a+n, mx);
		cout << mx*cnt << " " << cnt;
		return 0;
	}
	dfs1();
	best=*max_element(dp, dp+n);
	dfs2();
	cout << best*cnt_best << " " << cnt_best;
	return 0;
}