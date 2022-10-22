#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

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
int n, m, q, ecnt = 1, head[N], tot, ccno[N];
struct edge { int v, nxt; } e[N*2];
int idx, cnt, dfn[N], bccno[N], stk[N*2], tp, clr[N];
int rnk[N], d[N], fa[N][20], w[N];
void add(int u, int v) {
	e[++ecnt] = (edge){ v, head[u] };
	head[u] = ecnt;
}
int chk(int u, int x) {
	for(int i = head[u], v; v = e[i].v; i = e[i].nxt) if(bccno[v] == x) {
		if(clr[u] == clr[v]) return 0;
		if(!clr[v]) {
			clr[v] = 3 - clr[u];
			if(!chk(v, x)) return 0;
		}
	}
	return 1;
}
int dfs(int u) {
	ccno[u] = tot;
	d[u] = d[fa[u][0]] + 1;
	rep(i, 1, 19) fa[u][i] = fa[fa[u][i-1]][i-1];
	int lowu = dfn[u] = ++idx;
	rnk[lowu] = u;
	for(int i = head[u], v; v = e[i].v; i = e[i].nxt)
	if(!dfn[v]) {
		stk[++tp] = i, fa[v][0] = u;
		int lowv = dfs(v), tmp = tp;
		lowu = min(lowu, lowv);
		if(lowv >= dfn[u]) {
			for(cnt++; stk[tp+1] ^ i; tp--) {
				int x = e[stk[tp]].v, y = e[stk[tp]^1].v;
				bccno[x] = bccno[y] = cnt;
				clr[x] = clr[y] = 0;
			}
			if(clr[u] = 1, !chk(u, cnt)) while(tmp > tp) {
				int x = e[stk[tmp]].v, y = e[stk[tmp--]^1].v;
				w[dfn[x] > dfn[y] ? x : y] = 1;
			}
		}
	} else if(v ^ fa[u][0] && dfn[v] < dfn[u])
		stk[++tp] = i, lowu = min(lowu, dfn[v]);
	return lowu;
}
int lca(int u, int v) {
	if(d[u] < d[v]) swap(u, v);
	per(i, 19, 0) if(d[u] - (1 << i) >= d[v]) u = fa[u][i];
	if(u == v) return u;
	per(i, 19, 0) if(fa[u][i] ^ fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
int main() {
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n>>m;
	rep(i, 1, m) {
		int u = read(), v = read();
		add(u, v), add(v, u);
	}
	rep(i, 1, n) if(!dfn[i]) tot++, dfs(i);
	rep(i, 1, n) w[rnk[i]] += w[fa[rnk[i]][0]];
	for(q = read(); q--;) {
		int u = read(), v = read();
		if(ccno[u] ^ ccno[v]) { puts("No"); continue; }
		if((d[u] ^ d[v]) & 1) { puts("Yes"); continue; }
		puts(w[u] + w[v] - 2 * w[lca(u, v)] ? "Yes" : "No");
	}
	return 0;
}