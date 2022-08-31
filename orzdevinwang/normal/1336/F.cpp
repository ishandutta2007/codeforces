#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 3e5 + 7, M = N * 40;

template < int N > struct fenwt {
	using F = long long ;
	F a[N + 1];
	void add (int x, F w) {
		for (; x <= N; x += x & -x) a[x] += w;
	}
	F query (int x) {
		F ret = 0;
		for (; x; x -= x & -x) ret += a[x];
		return ret;
	}
	F get (int l, int r) {
		if(l > r) return 0;
		return query (r) - query (l - 1);
	}
} ;
fenwt < N > S;

ll ns;
 
struct ST {
	int tp;
	ll mn[20][N], cs[20][N];
	void mk() {
		L(i, 1, 19) L(j, 1, tp - (1 << i) + 1) 
			mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]), 
			cs[i][j] = mn[i][j] == mn[i - 1][j] ? cs[i - 1][j] : cs[i - 1][j + (1 << (i - 1))];
	}
} st;
int lg[N];

int n, m, k, fa[N], dep[N], idt, dfn[N], en[N], arr[N];
int su[N], sv[N], lc[N], up[20][N];
vi e[N], mp[N];
void dfs1 (int x) {
	++idt, dfn[x] = idt, arr[idt] = x;
	for (const int &v : e[x]) if(v != fa[x]) 
		fa[v] = x, up[0][v] = x, dep[v] = dep[x] + 1, dfs1 (v), arr[++idt] = x;
	en[x] = idt;
}
int lca (int u, int v) {
	int l = dfn[u], r = dfn[v], p;
	if(l > r) swap(l, r); 
	p = lg[r - l + 1];
	return st.mn[p][l] < st.mn[p][r - (1 << p) + 1] ? st.cs[p][l] : st.cs[p][r - (1 << p) + 1];
}
int geo (int x, int k) {
	L(i, 0, 18) if(k >> i & 1) x = up[i][x];
	return x;
}

// vitr
vi re[N];
int ord[N], ot, stk[N], tp;
int pt[N], all, vis[N];
void ins (int x) {
	if(!tp) return stk[++tp] = x, void ();
	int lc = lca(x, stk[tp]);
	if(lc == stk[tp]) return stk[++tp] = x, void () ;
	while (tp > 1 && dep[lc] <= dep[stk[tp - 1]]) re[stk[tp - 1]].push_back(stk[tp]), -- tp; 
	if(lc != stk[tp]) re[lc].push_back(stk[tp]), stk[tp] = lc; 
	stk[++tp] = x;
} 
int mrt, ifa[N], siz[N], hv[N], kl[N], kr[N];
vi vc[N];
void dfs2 (int x) {
	++all, pt[all] = x, kl[x] = all;
	siz[x] = sz(vc[x]) + 1, hv[x] = 0;
	for (const int &v : re[x]) {
		ifa[v] = x, dfs2 (v), siz[x] += siz[v];
		if(siz[v] > siz[hv[x]])	hv[x] = v;
	}
	kr[x] = all;
}

void weat (int u, int rk) {
	int upt = dep[u] - dep[mrt] - max(rk, 1);
	if(upt < 0) {
		if(rk <= 0) 
			ns += S.query(N - 1) * 2;
		return ;
	}
	int U = geo (u, upt), rc = S.query(en[U]) - S.query(dfn[U] - 1);
	if(rk <= 0) {
		int all = S.query(N - 1);
		ns += all * 2 - rc;
	} else ns += rc;
}

void dfs3 (int x, bool op) {
	for (const int &v : re[x]) if(v != hv[x]) 
		dfs3 (v, false);
	if(hv[x]) dfs3 (hv[x], true);
	int D = dep[x] - dep[mrt], rk = k - D;
	
	for (const int &v : re[x]) if(v != hv[x]) {
		if(x != mrt) {
			L(i, kl[v], kr[v]) for (const int &u : vc[pt[i]]) weat(u, rk);
		}
		L(i, kl[v], kr[v]) for (const int &u : vc[pt[i]]) S.add(dfn[u], 1);
	}
	for (const int &u : vc[x]) {
		if(x != mrt) weat (u, rk);
		S.add (dfn[u], 1);	
	}
	if(!op) L(i, kl[x], kr[x]) for (const int &u : vc[pt[i]]) S.add(dfn[u], -1);
}
void calc (int x) {
	mrt = x;
	ot = 0;
	for (const int &i : mp[x]) 
		ord[++ot] = su[i], ord[++ot] = sv[i];
	ord[++ot] = x;
	sort(ord + 1, ord + ot + 1, [&] (int x, int y) {
		return dfn[x] < dfn[y]; 
	});
	ot = unique(ord + 1, ord + ot + 1) - ord - 1;
	tp = 0;
	L(i, 1, ot) ins (ord[i]);
	while (tp > 1) re[stk[tp - 1]].push_back(stk[tp]), --tp;
	for (const int &i : mp[x]) 
		vc[su[i]].push_back(sv[i]), vc[sv[i]].push_back(su[i]);
	all = 0;
	dfs2 (x);
	dfs3 (x, false);
	L(i, 1, all) re[pt[i]].clear (), vc[pt[i]].clear ();  
}
int hd[N], sum[M], ch[M][2], tot, mak, ip;
int merge(int x, int y, int L, int R) {
	if(!x || !y) return x | y; 
	if(L == R && L <= mak) ns -= (ll) sum[x] * sum[y]; 
	int it = ++tot, mid = (L + R) >> 1;
	sum[it] = sum[x] + sum[y];
	ch[it][0] = merge(ch[x][0], ch[y][0], L, mid);
	ch[it][1] = merge(ch[x][1], ch[y][1], mid + 1, R);
	return it;
}
void add (int &x, int L, int R, int p, int w) {
	if(!x) x = ++tot;
	sum[x] += w;
	if(L == R) return ;
	int mid = (L + R) >> 1;
	if(p <= mid) add (ch[x][0], L, mid, p, w);
	else add (ch[x][1], mid + 1, R, p, w);
}
int query(int x, int L, int R, int l, int r) {
	if(l <= L && R <= r) return sum[x];
	int mid = (L + R) >> 1, ret = 0;
	if(l <= mid) ret += query(ch[x][0], L, mid, l, r);
	if(r > mid) ret += query(ch[x][1], mid + 1, R, l, r);
	return ret;
}
vi au[N];
void mg (int &x, int y, int d) {
	mak = d;
	if(mak >= 0) ns += (ll) query(x, 0, n, 0, d) * query(y, 0, n, 0, d);
	x = merge(x, y, 0, n);
}
void dfs4 (int x) {
	for (const int &v : au[x]) 
		ip = 0, add (ip, 0, n, v, 1), mg (hd[x], ip, dep[x] - k);
	for (const int &v : e[x]) if(v != fa[x]) 
		dfs4(v), mg(hd[x], hd[v], dep[x] - k);
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	L(i, 2, N - 1) lg[i] = lg[i >> 1] + 1;
	cin >> n >> m >> k;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v) ;
		e[v].push_back(u) ;
	}
	dfs1 (1);
	st.tp = idt;
	L(i, 1, 18) L(j, 1, n) up[i][j] = up[i - 1][up[i - 1][j]];
//	L(i, 1, idt) cout << arr[i] << " ";
//	cout << '\n'; 
	L(i, 1, idt) st.mn[0][i] = dep[arr[i]], st.cs[0][i] = arr[i];
	st.mk(); 
	L(i, 1, m) cin >> su[i] >> sv[i], lc[i] = lca(su[i], sv[i]), mp[lc[i]].push_back(i);
	L(i, 1, n) if(sz(mp[i])) calc (i);
	ns /= 2;
//	L(i, 1, m) cout << lc[i] << ' ';
//	cout << '\n';
	L(i, 1, m) au[su[i]].push_back(dep[lc[i]]), au[sv[i]].push_back(dep[lc[i]]);
	dfs4 (1);
	cout << ns << '\n';
	return 0;
}