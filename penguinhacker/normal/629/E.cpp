#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, d[mxN], anc[mxN][17], tin[mxN], tout[mxN], t, s[mxN];
ll dp1[mxN], dp2[mxN];
vector<int> adj[mxN];

void dfs1(int u=0, int p=-1) {
	s[u]=1;
	tin[u]=t++;
	for (int i=1; i<17; ++i)
		anc[u][i]=anc[anc[u][i-1]][i-1];
	for (int v : adj[u])
		if (v^p) {
			d[v]=d[u]+1;
			anc[v][0]=u;
			dfs1(v, u);
			s[u]+=s[v];
			dp1[u]+=dp1[v]+s[v];
		}
	tout[u]=t++;
	dp2[u]=dp1[u];
}

void dfs2(int u=0, int p=-1) {
	for (int v : adj[u])
		if (v^p) {
			ll x=dp2[u]-dp1[v]-s[v];
			dp2[v]+=x+n-s[v];
			dfs2(v, u);
		}
}

bool is_anc(int u, int v) {
	return tin[u]<=tin[v]&&tout[v]<=tout[u];
}

int lca(int u, int v) {
	for (int i=16; ~i; --i)
		if (!is_anc(anc[u][i], v))
			u=anc[u][i];
	return anc[u][0];
}

int lift(int u, int x) {
	for (int i=0; i<17; ++i)
		if (x&1<<i)
			u=anc[u][i];
	return u;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	cin >> n >> m;
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1();
	dfs2();
	while(m--) {
		int u, v;
		cin >> u >> v, --u, --v;
		if (d[u]>d[v])
			swap(u, v);
		double ans=1;
		if (is_anc(u, v)) {
			ans+=d[v]-d[u];
			ans+=(double)dp1[v]/s[v];
			v=lift(v, d[v]-d[u]-1);
			ans+=(double)(dp2[u]-dp1[v]-s[v])/(n-s[v]);
		} else {
			ans+=d[u]+d[v]-2*d[lca(u, v)];
			ans+=(double)dp1[u]/s[u];
			ans+=(double)dp1[v]/s[v];
		}
		cout << ans << "\n";
	}
	return 0;
}