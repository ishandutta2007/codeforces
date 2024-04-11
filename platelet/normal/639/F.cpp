#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
int read() {
	const int M = 1e6;
	static streambuf* in = cin.rdbuf();
	#define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, M), p1 == p2) ? -1 : *p1++)
	static char buf[M], *p1, *p2;
	int c = gc, r = 0;
	while(c < 48) c = gc;
	while(c > 47) r = (r << 3) + (r << 1) + (c & 15), c = gc;
	return r;
}
const int N = 3e5 + 5;
int n, m, q, idx, dfn[N];
int tp, stk[N], sid, sccno[N], cid, ccno[N];
vector <pair <int, int>> G[N], cut;
vector <int> T[N];
int nrt[N], d[N], fa[19][N], V[N * 4], Eu[N], Ev[N];
int Dfn[N], in[N];
void add(int u, int v, int w) { G[u].pb({v, w}), G[v].pb({u, w}); }
int dfs(int u, int f) {
	int lowu = dfn[u] = ++idx; stk[++tp] = u;
	for(auto [v, w] : G[u]) if(!dfn[v]) {
		int lowv = dfs(v, w);
		lowu = min(lowu, lowv);
		if(lowv == dfn[v]) {
			cut.pb({u, v}), ccno[++sid] = cid;
			while(stk[tp + 1] ^ v) sccno[stk[tp--]] = sid;
		}
	} else if(w ^ f) lowu = min(lowu, dfn[v]);
	return lowu;
}
void Dfs(int u) {
	dfn[u] = ++idx;
	rep(i, 1, 18) fa[i][u] = fa[i - 1][fa[i - 1][u]];
	for(int v : T[u]) fa[0][v] = u, d[v] = d[u] + 1, Dfs(v);
}
int lca(int u, int v) {
	if(d[u] < d[v]) swap(u, v);
	per(i, 18, 0) if(d[u] - (1 << i) >= d[v]) u = fa[i][u];
	if(u == v) return u;
	per(i, 18, 0) if(fa[i][u] ^ fa[i][v]) u = fa[i][u], v = fa[i][v];
	return fa[0][u];
}
int DFS(int u, int f) {
	int lowu = Dfn[u] = ++idx; stk[++tp] = u;
	for(auto [v, w] : G[u]) if(!Dfn[v]) {
		int lowv = DFS(v, w);
		lowu = min(lowu, lowv);
		if(lowv == Dfn[v]) while(stk[tp--] ^ v);
	} else if(w ^ f) lowu = min(lowu, Dfn[v]);
	return lowu;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m >> q;
	rep(i, 1, m) add(read(), read(), i);
	rep(i, 1, n) if(!dfn[i]) {
		cid++, dfs(i, 0);
		for(ccno[++sid] = cid; tp; sccno[stk[tp--]] = sid);
	}
	for(auto [u, v] : cut) T[sccno[u]].pb(v = sccno[v]), nrt[v] = 1;
	mem(dfn, 0), idx = 0;
	rep(i, 1, sid) if(!nrt[i]) Dfs(i);
	rep(i, 1, n) G[i].clear();
	int R = 0, ni, mi;
	rep(kase, 1, q) {
		int j = 0;
		ni = read(), mi = read();
		vector <int> key;
		rep(i, 1, ni) key.pb(V[++j] = sccno[(read() + R - 1) % n + 1]);
		rep(i, 1, mi) add(V[++j] = sccno[(read() + R - 1) % n + 1], V[++j] = sccno[(read() + R - 1) % n + 1], i);
		sort(V + 1, V + j + 1, [](int a, int b){ return dfn[a] < dfn[b]; });
		j = unique(V + 1, V + j + 1) - V - 1;
		vector <int> nds;
		rep(i, 1, j) {
			if(tp) {
				if(ccno[V[i]] ^ ccno[stk[tp]]) while(--tp) add(stk[tp], stk[tp + 1], ++mi);
				else {
					int l = lca(V[i], stk[tp]);
					if(l ^ stk[tp]) {
						while(tp > 1 && dfn[l] < dfn[stk[tp - 1]]) add(stk[--tp], stk[tp], ++mi);
						if(tp == 1 || dfn[l] > dfn[stk[tp - 1]]) add(l, stk[tp], ++mi), nds.pb(stk[tp] = l);
						else if(tp) add(l, stk[tp--], ++mi);
					}
				}
			}
			nds.pb(stk[++tp] = V[i]);
		}
		while(--tp) add(stk[tp], stk[tp + 1], ++mi);
		idx = 0, DFS(key[0], 0);
		int as = 1;
		for(int u : nds) G[u].clear(), Dfn[u] = 0;
		rep(i, 1, tp) in[stk[i]] = 1;
		for(int u : key) as &= in[u];
		while(tp) in[stk[tp--]] = 0;
		puts(as ? "YES" : "NO"), R = (R + as * kase) % n;
	}
	return 0;
}