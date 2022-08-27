#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int N = 6e5 + 7;

int tag[N * 4], ns;
void push(int id) {
	if(tag[id]) tag[id << 1] = tag[id << 1 | 1] = tag[id], tag[id] = 0; 
}
void add(int id, int l, int r, int w, int L, int R) {
	if(l <= L && R <= r) return tag[id] = w, void(); 
	int mid = (L + R) >> 1;
	push(id);
	if(l <= mid) add(id * 2, l, r, w, L, mid);
	if(r > mid) add(id * 2 + 1, l, r, w, mid + 1, R);
} 
int query(int id, int p, int L, int R) {
	if(L == R) return tag[id];
	push(id);
	int mid = (L + R) >> 1;
	if(p <= mid) return query(id * 2, p, L, mid);
	else return query(id * 2 + 1, p, mid + 1, R);
}

int n;

struct fwt {
	int f[N];
	void add(int p, int w) {
		for(; p <= n; p += (p & -p)) f[p] += w;
	} 
	int get(int p) {
		int res = 0;
		for(; p; p -= (p & -p)) res += f[p];
		return res;
	}
} qa, qb;

int ev[N * 4], enx[N * 4], eid;
int ahd[N], bhd[N];
void eadd(int u, int v, bool op) {
	if(op == 0) ++eid, enx[eid] = ahd[u], ahd[u] = eid, ev[eid] = v;
	else ++eid, enx[eid] = bhd[u], bhd[u] = eid, ev[eid] = v;
}

int pa[N], pb[N], v[N];
int dfn[N], en[N], idtot, siz[N];
void dfsb(int x, int fa) {
	dfn[x] = ++idtot;
	for(int i = bhd[x]; i; i = enx[i]) if(ev[i] != fa) 
		dfsb(ev[i], x); 
	en[x] = idtot;
}

int Siz;

void Mdf(int x, int w) {
	v[x] += w, qa.add(dfn[x], w), qb.add(dfn[x], w), qb.add(en[x] + 1, -w);
} 
int GG(int x) {
	if(qa.get(en[x]) == qa.get(dfn[x] - 1)) {
		int z = qb.get(dfn[x]);
		if(z > 0) z = query(1, dfn[x], 1, n), Mdf(z, -1), --Siz; 
		add(1, dfn[x], en[x], x, 1, n), Mdf(x, 1), ++Siz, ns = max(ns, Siz);
		return z;
	}
	return -1;
}
void dfsa(int x, int fa) {
	int t = GG(x);
	for(int i = ahd[x]; i; i = enx[i]) if(ev[i] != fa) 
		dfsa(ev[i], x);
	if(v[x]) Mdf(x, -1), Siz--;
	if(t > 0) GG(t);
}
void Main() {
	cin >> n, eid = ns = idtot = 0;
	L(i, 1, n) ahd[i] = bhd[i] = 0;
	
	L(i, 2, n) cin >> pa[i], eadd(pa[i], i, 0);
	L(i, 2, n) cin >> pb[i], eadd(pb[i], i, 1);
	dfsb(1, -1), dfsa(1, -1); 
	cout << ns << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}