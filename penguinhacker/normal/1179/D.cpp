#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5;
const ll INF=1e18;
int n, s[mxN];
vector<int> adj[mxN];
ll dp[mxN], ans=INF;

ll c2(ll x) {
	return x*(x-1)/2;
}

ll ix(ar<ll, 2> a, ar<ll, 2> b) { // when does b overtake a
	assert(a[0]>b[0]);
	ll x=a[0]-b[0], y=b[1]-a[1];
	return y>=0?(y+x-1)/x:y/x;
}

void dfs(int u=0) {
	s[u]=1;
	if (adj[u].empty())
		return;
	for (int v : adj[u]) {
		adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
		dfs(v);
		s[u]+=s[v];
	}
	dp[u]=INF;
	for (int v : adj[u])
		dp[u]=min(dp[u], dp[v]+c2(s[u]-s[v]));
	if (adj[u].size()==1) {
		int v=adj[u][0];
		ans=min(ans, dp[v]+c2(n-s[v]));
		return;
	}
	sort(adj[u].begin(), adj[u].end(), [&](int a, int b) { return s[a]<s[b]; });
	vector<ar<ll, 2>> lines;
	for (int v : adj[u]) {
		if (lines.size()) {
			ll x=n-s[v];
			while(lines.size()>=2&&ix(lines.end()[-2], lines.back())>x)
				lines.pop_back();
			ans=min(ans, c2(x)+dp[v]+lines.back()[0]*x+lines.back()[1]);
		}
		ar<ll, 2> cur={-s[v], dp[v]+c2(s[v]+1)};
		while(lines.size()&&lines.back()[0]==cur[0]&&cur[1]<lines.back()[1])
			lines.pop_back();
		if (lines.size()&&lines.back()[0]==cur[0]&&lines.back()[1]<=cur[1])
			continue;
		while(lines.size()>=2&&ix(lines.back(), cur)<=ix(lines.end()[-2], lines.back()))
			lines.pop_back();
		lines.push_back(cur);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	cout << (ll)n*(n-1)-ans;
	return 0;
}