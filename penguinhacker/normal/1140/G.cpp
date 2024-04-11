#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
const ll INF=1e18;
int n, q, anc[mxN][19], dep[mxN];
vector<ar<ll, 3>> adj[mxN];
ll br[mxN], d[mxN][2], dp[mxN], lft[mxN][19][2][2];

void smin(ll& x, ll y) {
	if (y<x)
		x=y;
}

void dfs1(int u=0) {
	dp[u]=d[u][0]+d[u][1]+br[u];
	for (int i=1; i<19; ++i)
		anc[u][i]=anc[u][i-1]^-1?anc[anc[u][i-1]][i-1]:-1;
	for (ar<ll, 3> v : adj[u]) {
		adj[v[0]].erase(find(adj[v[0]].begin(), adj[v[0]].end(), ar<ll, 3>{u, v[1], v[2]}));
		d[v[0]][0]=d[u][0]+v[1], d[v[0]][1]=d[u][1]+v[2];
		dep[v[0]]=dep[u]+1;
		anc[v[0]][0]=u;
		dfs1(v[0]);
		smin(dp[u], dp[v[0]]);
	}
	smin(br[u], dp[u]-d[u][0]-d[u][1]);
}

void dfs2(int u=0, ll mn=INF) {
	mn=min(mn, dp[u]-2*(d[u][0]+d[u][1]));
	smin(br[u], d[u][0]+d[u][1]+mn);
	if (u) {
		for (int i : {0, 1})
			for (int j : {0, 1})
				for (int k : {0, 1})
					smin(lft[u][0][i][i^j^k], (j?br[u]:0)+(k?br[anc[u][0]]:0)+(d[u][i^j]-d[anc[u][0]][i^j]));
		for (int i=1; i<19; ++i) {
			if (anc[u][i]==-1)
				break;
			for (int a : {0, 1})
				for (int b : {0, 1})
					for (int c : {0, 1})
						smin(lft[u][i][a][c], lft[u][i-1][a][b]+lft[anc[u][i-1]][i-1][b][c]);
		}
	}
	for (ar<ll, 3> v : adj[u])
		dfs2(v[0], mn);
}

int lca(int u, int v) {
	assert(dep[u]<=dep[v]);
	for (int i=18; ~i; --i)
		if (dep[v]-(1<<i)>=dep[u])
			v=anc[v][i];
	if (u==v)
		return u;
	for (int i=18; ~i; --i)
		if (anc[u][i]^anc[v][i])
			u=anc[u][i], v=anc[v][i];
	assert(u!=v&&anc[u][0]==anc[v][0]);
	return anc[u][0];
}

ar<ll, 2> mk(int u, int t) {
	return t==0?ar<ll, 2>{0, br[u]}:ar<ll, 2>{br[u], 0};
}

ar<ll, 2> solve(int u, int v, ar<ll, 2> s) { // lift v up to u
	//cout << s[0] << " " << s[1] << endl;
	for (int i=18; ~i; --i) {
		if (dep[v]-(1<<i)<dep[u])
			continue;
		ar<ll, 2> ns={INF, INF};
		for (int a : {0, 1})
			for (int b : {0, 1})
				smin(ns[b], s[a]+lft[v][i][a][b]);
		v=anc[v][i];
		swap(s, ns);
	}
	assert(u==v);
	return s;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> br[i];
	for (int i=1; i<n; ++i) {
		ll u, v, a, b;
		cin >> u >> v >> a >> b, --u, --v;
		adj[u].push_back({v, a, b});
		adj[v].push_back({u, a, b});
	}
	anc[0][0]=-1;
	memset(lft, 0x3f, sizeof(lft));
	dfs1();
	dfs2();
	//for (int i=0; i<n; ++i)
	//	cout << br[i] << endl;
	//cout << lft[3][0][0][1] << " " << lft[2][0][1][1] << " " << lft[3][1][0][1] << endl;
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v, --u, --v;
		int tu=u%2, tv=v%2;
		u/=2, v/=2;
		if (dep[u]>dep[v]) {
			swap(u, v);
			swap(tu, tv);
		}
		int uv=lca(u, v);
		ar<ll, 2> a=solve(uv, u, mk(u, tu));
		ar<ll, 2> b=solve(uv, v, mk(v, tv));
		//cout << u << " " << tu << " " << a[0] << " " << a[1] << " " << b[0] << " " << b[1] << endl;
		cout << min(a[0]+b[0], a[1]+b[1]) << "\n";
	}
	return 0;
}