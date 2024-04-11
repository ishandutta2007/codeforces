#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, B=400;
int n, m, type[mxN], a[mxN], t, tin[mxN], tout[mxN], id[2*mxN], dep[mxN], anc[mxN][17];
ll cur, ans[mxN], cnt[mxN][2];
vector<int> adj[mxN];
bool vis[mxN];

struct Query {
	int l, r, lc, ind;
	bool operator<(const Query& o) const {
		return l/B^o.l/B?l/B<o.l/B:r<o.r;
	}
} qry[mxN];

void dfs(int u=0, int p=-1) {
	id[t]=u, tin[u]=t++;
	for (int i=1; i<17; ++i)
		anc[u][i]=anc[anc[u][i-1]][i-1];
	for (int v : adj[u]) {
		if (v==p)
			continue;
		dep[v]=dep[u]+1, anc[v][0]=u;
		dfs(v, u);
	}
	id[t]=u, tout[u]=t++;
}

int lca(int u, int v) {
	if (dep[u]>dep[v])
		swap(u, v);
	for (int i=16; ~i; --i)
		if (dep[u]<=dep[v]-(1<<i))
			v=anc[v][i];
	if (u==v)
		return u;
	for (int i=16; ~i; --i)
		if (anc[u][i]^anc[v][i])
			u=anc[u][i], v=anc[v][i];
	return anc[u][0];
}

void upd(int i) {
	int x=a[i];
	cur-=cnt[x][0]*cnt[x][1];
	cnt[x][type[i]]+=vis[i]?-1:1;
	cur+=cnt[x][0]*cnt[x][1];
	vis[i]^=1;
}

void mos() {
	int l=qry[0].l, r=qry[0].l;
	for (int i=0; i<m; ++i) {
		int ql=qry[i].l, qr=qry[i].r;
		while(l>ql) upd(id[--l]);
		while(r<=qr) upd(id[r++]);
		while(l<ql) upd(id[l++]);
		while(r>qr+1) upd(id[--r]);
		bool b=qry[i].lc!=id[qry[i].l];
		if (b) upd(qry[i].lc);
		//cout << cnt[1][0] << " " << cnt[1][1] << endl;
		ans[qry[i].ind]=cur;
		if (b) upd(qry[i].lc);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> type[i];
	for (int i=0; i<n; ++i)
		cin >> a[i];
	vector<int> d(a, a+n);
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());
	for (int i=0; i<n; ++i)
		a[i]=lower_bound(d.begin(), d.end(), a[i])-d.begin();
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	/*for (int i=0; i<2*n; ++i)
		cout << id[i] << " ";
	cout << endl;*/
	cin >> m;
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		if (tin[u]>tin[v])
			swap(u, v);
		//cout << u << " " << v << endl;
		qry[i].ind=i, qry[i].lc=lca(u, v);
		if (qry[i].lc==u)
			qry[i].l=tin[u], qry[i].r=tin[v];
		else
			qry[i].l=tout[u], qry[i].r=tin[v];
		//cout << qry[i].l << " " << qry[i].r << endl;
	}
	sort(qry, qry+m);
	mos();
	for (int i=0; i<m; ++i)
		cout << ans[i] << "\n";
	return 0;
}