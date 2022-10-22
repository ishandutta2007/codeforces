#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define mid ((l + r) >> 1)
#define lch l, mid, o << 1
#define rch mid + 1, r, o << 1 | 1

using namespace std;
const int N = 1e5 + 5, MI = 1e6;
int read() {
	static streambuf* in = cin.rdbuf();
	#define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, MI), p1 == p2) ? -1 : *p1++)
	static char buf[MI], *p1, *p2;
	int c = gc, r = 0;
	while(c < 48) c = gc;
	while(c > 47) r = (r << 3) + (r << 1) + (c & 15), c = gc;
	return r;
}
void wrt(int x) {
	static streambuf* out = cout.rdbuf();
	#define pc out -> sputc
	static char ch[11]; int sz = 0;
	if(!x) pc(48);
	else {
		while(x) ch[++sz] = x % 10, x /= 10;
		while(sz) pc(ch[sz--] + 48);
	} pc(32);
}
int n, m, cnt, head[N], idx, dfn[N], rnk[N], suf[N], ans[N];
struct edge { int v, nxt; } e[N*2];
struct Opr { int l, r, w; }; vector <Opr> opr[N];
struct node {
	int v, cnt;
	node operator +(const node& b) {
		node c; c.v = min(v, b.v), c.cnt = 0;
		if(c.v == v) c.cnt += cnt;
		if(c.v == b.v) c.cnt += b.cnt;
		return c;
	}
} tr[N*4]; int lzy[N*4];
void add(int u, int v) {
	e[++cnt] = (edge){ v, head[u] };
	head[u] = cnt;
}
void pushup(int o) { tr[o] = tr[o<<1] + tr[o<<1|1]; }
void put(int o, int v) { tr[o].v += v, lzy[o] += v; }
void pushdown(int o) {
	put(o<<1, lzy[o]), put(o<<1|1, lzy[o]), lzy[o] = 0;
}
void bld(int l, int r, int o) {
	tr[o].cnt = r - l + 1;
	if(l == r) return;
	bld(lch), bld(rch);
}
void upd(int L, int R, int v, int l, int r, int o) {
	if(L <= l && r <= R) return put(o, v), void();
	pushdown(o);
	if(L <= mid) upd(L, R, v, lch);
	if(R > mid) upd(L, R, v, rch);
	pushup(o);
}
int qry(int p, int l, int r, int o) {
	if(l == r) return tr[o].v;
	pushdown(o);
	return p <= mid ? qry(p, lch) : qry(p, rch); 
}
void dfs(int u, int fa) {
	rnk[dfn[u] = ++idx] = u;
	for(int i = head[u], v; v = e[i].v; i = e[i].nxt)
	if(v ^ fa) dfs(v, u);
	suf[u] = idx;
}
void ins(int x, int l, int r, int w) {
	opr[x].push_back((Opr){ l, r, w });
}
int main() {
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	rep(i, 2, n) {
		int u = read(), v = read();
		add(u, v), add(v, u);
	}
	dfs(1, 0);
	while(m--) {
		int a = read(), b = read();
		ins(dfn[a], dfn[a], suf[a], 1), ins(suf[a] + 1, dfn[a], suf[a], -1);
		ins(dfn[a], dfn[b], suf[b], 1), ins(suf[a] + 1, dfn[b], suf[b], -1);
		ins(dfn[b], dfn[a], suf[a], 1), ins(suf[b] + 1, dfn[a], suf[a], -1);
		ins(dfn[b], dfn[b], suf[b], 1), ins(suf[b] + 1, dfn[b], suf[b], -1);
	}
	bld(1, n, 1);
	rep(i, 1, n) {
		rep(j, 0, (int)opr[i].size() - 1)
			upd(opr[i][j].l, opr[i][j].r, opr[i][j].w, 1, n, 1);
		ans[rnk[i]] = (tr[1].v ? n : n - tr[1].cnt) - (qry(i, 1, n, 1) > 0);	
	}
	rep(i, 1, n) wrt(ans[i]);
	return 0;
}