#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
const ll INF=1e18;
int n, t[mxN], h[mxN];
vector<int> adj[mxN];
ll dp[mxN][2], ans=INF; // up, down

void dfs(int u=0, int p=-1) {
	vector<ar<ll, 2>> c;
	for (int v : adj[u])
		if (v!=p) {
			dfs(v, u);
			if (h[v]>h[u])
				dp[v][0]=INF;
			if (h[v]<h[u])
				dp[v][1]=INF;
			c.push_back({dp[v][1]-dp[v][0], dp[v][0]});
		}
	sort(c.begin(), c.end());
	vector<ll> suf(c.size());
	for (int i=(int)c.size()-1; ~i; --i)
		suf[i]=min(INF, c[i][1]+(i+1<c.size()?suf[i+1]:0));
	dp[u][0]=dp[u][1]=INF;
	auto Ck=[&](int ups, ll cost) {
		if (cost>=INF)
			return;
		int downs=c.size()-ups;
		if (u) {
			dp[u][0]=min(dp[u][0], cost+(ll)max(ups, downs+1)*t[u]);
			dp[u][1]=min(dp[u][1], cost+(ll)max(ups+1, downs)*t[u]);
		} else {
			ans=min(ans, cost+(ll)max(ups, downs)*t[u]);
		}
	};
	Ck(c.size(), c.size()?suf[0]:0);
	ll cur=0;
	for (int i=0; i<c.size(); ++i) {
		cur=min(INF, cur+c[i][0]+c[i][1]);
		Ck(c.size()-i-1, cur+(i+1<c.size()?suf[i+1]:0));
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> t[i];
	for (int i=0; i<n; ++i)
		cin >> h[i];
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