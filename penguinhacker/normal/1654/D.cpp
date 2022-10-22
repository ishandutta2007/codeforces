#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, M=998244353;
int n, tin[mxN], tout[mxN], tt, ft[2*mxN+1];
vector<ar<int, 3>> adj[mxN];
vector<ar<int, 2>> pf[mxN+1], oc[mxN+1];
ll s, ans, iv[mxN+1];

void dfs1(int u=0, int p=-1) {
	tin[u]=tt++;
	for (ar<int, 3> v : adj[u]) {
		if (v[0]==p)
			continue;
		dfs1(v[0], u);
		for (ar<int, 2> x : pf[v[1]])
			oc[x[0]].push_back({v[0], -x[1]});
		for (ar<int, 2> x : pf[v[2]])
			oc[x[0]].push_back({v[0], x[1]});
	}
	tout[u]=tt++;
}

void upd(int i, int x) {
	for (++i; i<=2*n; i+=i&-i)
		ft[i]+=x;
}

int qry(int i) {
	int r=0;
	for (++i; i; i-=i&-i)
		r+=ft[i];
	return r;
}

void dfs2(int u=0, int p=-1, ll x=s) {
	ans=(ans+x)%M;
	for (ar<int, 3> v : adj[u])
		if (v[0]!=p)
			dfs2(v[0], u, x*v[1]%M*iv[v[2]]%M);
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		adj[i].clear();
	for (int i=1; i<n; ++i) {
		int u, v, a, b;
		cin >> u >> v >> a >> b, --u, --v;
		adj[u].push_back({v, b, a});
		adj[v].push_back({u, a, b});
	}
	for (int i=1; i<=n; ++i)
		oc[i].clear();
	tt=0;
	dfs1();
	s=1;
	for (int i=2; i<=n; ++i) {
		if (oc[i].empty())
			continue;
		sort(oc[i].begin(), oc[i].end(), [&](ar<int, 2>& a, ar<int, 2>& b) { return tin[a[0]]<tin[b[0]]; });
		int mx=0;
		for (int j=0; j<oc[i].size(); ++j) {
			int u=oc[i][j][0], x=oc[i][j][1];
			//cout << i << " " << u << " " << x << endl;
			upd(tin[u], x);
			upd(tout[u], -x);
			if (j==oc[i].size()-1||u!=oc[i][j+1][0])
				mx=max(mx, qry(tin[u]));
		}
		while(mx--)
			s=s*i%M;
		for (ar<int, 2> x : oc[i]) {
			upd(tin[x[0]], -x[1]);
			upd(tout[x[0]], x[1]);
		}
	}
	ans=0;
	dfs2();
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i=2; i<=mxN; ++i) {
		if (pf[i].empty()) {
			for (int j=i; j<=mxN; j+=i) {
				int x=j, c=0;
				while(x%i==0) {
					++c;
					x/=i;
				}
				pf[j].push_back({i, c});
			}
		}
	}
	iv[1]=1;
	for (int i=2; i<=mxN; ++i)
		iv[i]=M-M/i*iv[M%i]%M;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}