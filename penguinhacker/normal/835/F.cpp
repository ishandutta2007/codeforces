#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, e[mxN];
ll diam, to[mxN], pd[mxN], sd[mxN], pf[mxN], sf[mxN];
vector<ar<int, 2>> adj[mxN];
vector<int> path, cyc;
bool vis[mxN];

bool dfs1(int u=0, int p=-1) {
	if (vis[u]) {
		cyc.push_back(u);
		for (; path.back()!=u; path.pop_back())
			cyc.push_back(path.back());
		return 1;
	}
	vis[u]=1;
	path.push_back(u);
	for (auto [v, w] : adj[u])
		if (v^p&&dfs1(v, u))
			return 1;
	path.pop_back();
	return 0;
}

ll dfs2(int u) {
	vis[u]=1;
	ar<ll, 2> b={};
	for (auto [v, w] : adj[u])
		if (!vis[v]) {
			ll c=dfs2(v)+w;
			if (c>b[0])
				b={c, b[0]};
			else if (c>b[1])
				b[1]=c;
		}
	diam=max(diam, b[0]+b[1]);
	return b[0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		int u, v, w;
		cin >> u >> v >> w, --u, --v;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	assert(dfs1()&&cyc.size()>=3);
	memset(vis, 0, sizeof(vis));
	n=cyc.size();
	for (int i=0; i<n; ++i) {
		int nxt=cyc[(i+1)%n], prv=cyc[(i+n-1)%n];
		vis[nxt]=vis[prv]=1;
		for (auto [v, w] : adj[cyc[i]])
			if (v==nxt)
				e[i]=w;
		to[i]=dfs2(cyc[i]);
	}
	ll ce=0, cf=0;
	for (int i=0; i<n; ++i) {
		pd[i]=i?max(pd[i-1], ce+to[i]+cf):to[i];
		pf[i]=i?max(pf[i-1], ce+to[i]):to[i];
		cf=max(cf, to[i]-ce);
		ce+=e[i];
	}
	ce=0, cf=0;
	for (int i=n-1; ~i; --i) {
		sd[i]=i+1<n?max(sd[i+1], ce+to[i]+cf):to[i];
		sf[i]=i+1<n?max(sf[i+1], ce+to[i]):to[i];
		cf=max(cf, to[i]-ce);
		ce+=e[(i+n-1)%n];
	}
	ll ans=pd[n-1];
	for (int i=0; i+1<n; ++i) // cut between i-i+1
		ans=min(ans, max({pd[i], sd[i+1], pf[i]+sf[i+1]+e[n-1]}));
	cout << max(ans, diam);
	return 0;
}