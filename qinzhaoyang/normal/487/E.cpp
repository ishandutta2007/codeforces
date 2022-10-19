#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int S = 300;
const int inf = 0x3f3f3f3f;

void ckmin(int &x, int y) {x = min(x, y);}

int first[N << 1], cur;
struct Edge {
	int nxt, to;
}	e[N << 2];
void con(int x, int y) {
	e[++cur] = (Edge){first[x], y};
	first[x] = cur;
}

vector <int> G[N << 1], att[N << 1], hav[N << 1];

int n, m, q, a[N], dfn[N], low[N], cnt, sta[N], pot, num;

void Con(int x, int y) {
	G[x].push_back(y);
	G[y].push_back(x);
	att[y].push_back(x);
	hav[x].push_back(y);
}

void tarjan(int x, int fa) {
	dfn[x] = low[x] = ++cnt;
	sta[++pot] = x;
	for (int i = first[x]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (!dfn[v]) {
			tarjan(v, x), low[x] = min(low[x], low[v]);
			if (dfn[x] <= low[v]) {
				++num;
				while (sta[pot] != v)
					Con(num, sta[pot--]);
				Con(num, sta[pot--]);
				Con(num, x);
			}
		}
		else if(v != fa) low[x] = min(low[x], dfn[v]);
	}
}

struct BIT {
	int a[N << 1];
	void Mdf(int x, int v) {for (; x <= num; x += x & (-x)) a[x] += v;}
	int Qry(int x) {int r = 0; for (; x; x -= x & (-x)) r += a[x]; return r;}
}	st;

struct SegT {
	int mn[N << 3];
	SegT() {memset(mn, 0x3f, sizeof mn);}
	void Mdf(int p, int l, int r, int x, int v) {
		if (l == r) return mn[p] = v, void();
		int mid = (l + r) >> 1;
		if (x <= mid) Mdf(p << 1, l, mid, x, v);
		if (x > mid) Mdf(p << 1 | 1, mid + 1, r, x, v);
		mn[p] = min(mn[p << 1], mn[p << 1 | 1]);
	}
	int Qry(int p, int l, int r, int tl, int tr) {
		if (tl <= l && r <= tr) return mn[p];
		int mid = (l + r) >> 1, ret = inf;
		if (tl <= mid) ckmin(ret, Qry(p << 1, l, mid, tl, tr));
		if (tr > mid) ckmin(ret, Qry(p << 1 | 1, mid + 1, r, tl, tr));
		return ret;
	}
}	sg;

int dep[N << 1], fa[N << 1], top[N << 1], L[N << 1], R[N << 1], cnt_dfn, son[N << 1], siz[N << 1];

void dfs1(int x, int Fa) {
	dep[x] = dep[Fa] + 1, fa[x] = Fa;
	siz[x] = 1; int mx = 0;
	for (int v : G[x]) {
		if (v == Fa) continue;
		dfs1(v, x), siz[x] += siz[v];
		if (siz[v] > mx) mx = siz[v], son[x] = v;
	}
}

void dfs2(int x, int tp) {
	top[x] = tp, L[x] = ++cnt_dfn;
	if (son[x]) dfs2(son[x], tp);
	for (int v : G[x]) {
		if (v == fa[x] || v == son[x]) continue;
		dfs2(v, v);
	}
	R[x] = cnt_dfn;
}

int Lca(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	return x;
}

int Query(int u, int v) {
	int ret = inf;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		ckmin(ret, sg.Qry(1, 1, num, L[top[u]], L[u]));
		u = fa[top[u]];
	}
	if (dep[u] > dep[v]) swap(u, v);
	return min(ret, sg.Qry(1, 1, num, L[u], L[v]));
}

struct Operation {
	int op;
	int x, w;
	int u, v, lca;
}	Op[N];
vector <int> Mak[N];

multiset <int> Set[N << 1];

int main() {
	//freopen("paoshang.in", "r", stdin);
	//freopen("paoshang.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q), num = n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		con(u, v), con(v, u);
	}
	for (int i = 1; i <= q; i++) {
		char op; scanf(" %c", &op);
		if (op == 'C') Op[i].op = 1;
		else Op[i].op = 2;
		if (op == 'C') scanf("%d%d", &Op[i].x, &Op[i].w);
		else scanf("%d%d", &Op[i].u, &Op[i].v);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i, 0);
	dfs1(1, 0), dfs2(1, 1);
	for (int i = 1; i <= q; i++) if (Op[i].op == 2)
		Op[i].lca = Lca(Op[i].u, Op[i].v);
	for (int i = 1; i <= n; i++) if ((int)att[i].size() > S) {
		for (int v : att[i]) st.Mdf(L[v], 1), st.Mdf(R[v] + 1, -1);
		for (int j = 1; j <= q; j++) {
			if (Op[j].op == 2) {
				int u = Op[j].u, v = Op[j].v, lca = Op[j].lca;
				int s = st.Qry(L[u]) + st.Qry(L[v]) - st.Qry(L[lca]) - st.Qry(L[fa[lca]]);
				if (s > 0) Mak[j].push_back(i);
			}
		}
		for (int v : att[i]) st.Mdf(L[v], -1), st.Mdf(R[v] + 1, 1);
	}
	for (int i = 1; i <= n; i++) if ((int)att[i].size() <= S)
		for (int v : att[i]) Set[v].insert(a[i]);
	for (int i = n + 1; i <= num; i++)
		if (Set[i].size())
			sg.Mdf(1, 1, num, L[i], *Set[i].begin());
	for (int o = 1; o <= q; o++) {
		int op = Op[o].op;
		if (op == 1) {
			int x = Op[o].x, w = Op[o].w;
			if ((int)att[x].size() <= S) {
				for (int v : att[x]) {
					Set[v].erase(Set[v].find(a[x]));
					Set[v].insert(w);
					sg.Mdf(1, 1, num, L[v], *Set[v].begin());
				}
			}
			a[x] = w;
		}
		else {
			int u = Op[o].u, v = Op[o].v, lca = Op[o].lca, ans = inf;
			if (u == v) {
				printf("%d\n", a[u]);
				continue;
			}
			ans = Query(u, v);
			for (int x : Mak[o])
				ckmin(ans, a[x]);
			printf("%d\n", ans);
		}
	}
	return 0;
}