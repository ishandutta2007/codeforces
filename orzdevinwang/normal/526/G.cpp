#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
int n, q, lst;
int ehd[N], ev[N], ew[N], enx[N], eid;
void eadd (int u, int v, int w) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ew[eid] = w, ehd[u] = eid;
}
struct tree {
	int rt, fa[N], hv[N], mxd[N], dis[N];
	void dfs (int x) {
		for(int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa[x]) {
			fa[ev[i]] = x, dis[ev[i]] = dis[x] + ew[i], dfs(ev[i]), mxd[ev[i]] += ew[i];
			if(mxd[x] < mxd[ev[i]]) mxd[x] = mxd[ev[i]], hv[x] = ev[i];
		}
	}
	int p[N], col[N], up[20][N], tp;
	ll ns[N];
	void init () {
		dfs (rt);
		L(i, 1, n) if(hv[fa[i]] != i) 
			p[++tp] = i;
		sort(p + 1, p + tp + 1, [&] (int x, int y) { return mxd[x] > mxd[y]; }) ;
		L(i, 1, tp) {
			ns[i] = ns[i - 1] + mxd[p[i]];
			for(int u = p[i]; u; u = hv[u]) col[u] = i;	
		}
		L(i, 1, n) up[0][i] = fa[i];
		L(i, 1, 19) L(j, 1, n) up[i][j] = up[i - 1][up[i - 1][j]];
	}
	int gv (int x, int k) { //  color <= k  
		R(i, 19, 0) if(col[up[i][x]] > k) x = up[i][x];
		return fa[x];
	} 
	int query (int x, int y) {
		y = y * 2 - 1;
		if(y > tp) return ns[tp];
		if(col[x] <= y) return ns[y];
		int z = p[col[gv (x, y)]];
		return max (ns[y - 1] + dis[x] + mxd[hv[x]] - dis[gv(x, y - 1)], ns[y] - mxd[z] + (dis[x] - dis[fa[z]] + mxd[hv[x]])); 
	}
} t1, t2;
int v1, v2, Dis[N];
int get () { 
	int mx = 0; 
	L(i, 1, n) mx = max(mx, Dis[i]); 
	L(i, 1, n) if(Dis[i] == mx) return i; 
}
void dfs (int x, int fa) { 
	for (int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa) Dis[ev[i]] = Dis[x] + ew[i], dfs (ev[i], x); 
} 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	L(i, 1, n - 1) {
		int u, v, w;
		cin >> u >> v >> w; 
		eadd (u, v, w), eadd (v, u, w);
	}
	dfs (1, 0), v1 = get ();
	dfs (v1, 0), v2 = get ();
	t1.rt = v1, t1.init ();
	t2.rt = v2, t2.init ();
	while (q--) {
		int x, y;
		cin >> x >> y;
		x = (x + lst - 1) % n + 1;
		y = (y + lst - 1) % n + 1;  
		lst = max (t1.query (x, y), t2.query (x, y));
		cout << lst << "\n";
	}
	return 0;
}