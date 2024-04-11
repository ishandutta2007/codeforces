#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, M=1e9+7;
int n, s[mxN], rg[mxN];
vector<int> qry[mxN], adj[mxN];
bool dead[mxN], vis[mxN];
int ans, cur;
ar<int, 2> dp1[mxN]; // {sum of inv, sum of d/inv}
vector<ar<int, 2>> dp2[mxN];
vector<ar<int, 3>> pars[mxN]; // {centroid parent, which child of parent, distance to parent}

int add(int a, int b) { if ((a+=b)>=M) a-=M; return a; }
int sub(int a, int b) { if ((a-=b)<0) a+=M; return a; }
int mul(int a, int b) { return (ll)a*b%M; }

int bp(int b, int p=M-2) {
	int r=1;
	for (; p; p>>=1, b=mul(b, b))
		if (p&1)
			r=mul(r, b);
	return r;
}

int gc(int src) {
	function<int(int, int)> dfs1=[&](int u, int p) {
		s[u]=1;
		for (int v : adj[u])
			if (v^p&&!dead[v])
				s[u]+=dfs1(v, u);
		return s[u];
	};
	int ts=dfs1(src, -1);
	function<int(int, int)> dfs2=[&](int u, int p) {
		for (int v : adj[u])
			if (v^p&&!dead[v]&&2*s[v]>ts)
				return dfs2(v, u);
		return u;
	};
	return dfs2(src, -1);
}

void cd(int u=0) { // centroid decomp
	u=gc(u);
	pars[u].push_back({u, -1, 0});
	int d=1;
	function<void(int, int)> dfs=[&](int u2, int p) {
		pars[u2].push_back({u, (int)dp2[u].size(), d});
		for (int v : adj[u2])
			if (v^p&&!dead[v])
				++d, dfs(v, u2), --d;
	};
	for (int v : adj[u])
		if (!dead[v]) {
			dfs(v, u);
			dp2[u].push_back({});
		}
	dead[u]=1;
	for (int v : adj[u])
		if (!dead[v])
			cd(v);
	dead[u]=0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		int l, r;
		cin >> l >> r, --l, --r;
		rg[i]=r-l+1;
		qry[l].push_back(i);
		if (r+1<mxN)
			qry[r+1].push_back(i);
	}
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cd();
	for (int i=0; i<mxN; ++i) {
		for (int u : qry[i]) {
			int inc=vis[u]?M-1:1;
			int inv=bp(rg[u]);
			for (ar<int, 3> x : pars[u]) {
				int p=x[0], c=x[1], d=x[2];
				int dinv=mul(d, inv);
				cur=add(cur, mul(inc, add(mul(inv, dp1[p][1]), mul(dinv, dp1[p][0]))));
				dp1[p][0]=add(dp1[p][0], mul(inc, inv));
				dp1[p][1]=add(dp1[p][1], mul(inc, dinv));
				if (c^-1) {
					cur=sub(cur, mul(inc, add(mul(inv, dp2[p][c][1]), mul(dinv, dp2[p][c][0]))));
					dp2[p][c][0]=add(dp2[p][c][0], mul(inc, inv));
					dp2[p][c][1]=add(dp2[p][c][1], mul(inc, dinv));
				}
			}
			vis[u]^=1;
		}
		ans=add(ans, cur);
	}
	for (int i=0; i<n; ++i)
		ans=mul(ans, rg[i]);
	cout << ans;
	return 0;
}