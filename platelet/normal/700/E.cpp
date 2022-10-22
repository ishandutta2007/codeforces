#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define mid ((l + r) / 2)
#define lch l, mid, ls[o]
#define rch mid + 1, r, rs[o]

using namespace std;

const int N = 4e5 + 5;

char s[N];
int n, sz = 1, nw = 1, f[N], len[N], ch[N][26], pos[N];
int fa[19][N], ls[N * 40], rs[N * 40], c[N * 40], T[N], dp[N], as;
vector<int> G[N];

void ins(int c, int ps) {
	int u = ++sz;
	len[u] = len[nw] + 1, pos[u] = ps;
	while(nw && !ch[nw][c]) ch[nw][c] = u, nw = f[nw];
	if(!nw) f[u] = 1;
	else {
		int v = ch[nw][c];
		if(len[v] > len[nw] + 1) {
			f[++sz] = f[v], pos[sz] = pos[v], memcpy(ch[sz], ch[v], sizeof ch[v]);
			f[v] = f[u] = sz, len[sz] = len[nw] + 1;
			for(int x = nw; ch[x][c] == v; x = f[x]) ch[x][c] = sz;
		} else f[u] = v;
	}
	nw = u;
}
void bld(int p, int l, int r, int& o) {
	c[o = ++sz] = p;
	if(l < r) p <= mid ? bld(p, lch) : bld(p, rch);
}
int mrg(int u, int v) {
	if(!u || !v) return u + v;
	int o = ++sz;
	c[o] = max(c[u], c[v]), ls[o] = mrg(ls[u], ls[v]), rs[o] = mrg(rs[u], rs[v]);
	return o;
}
int qry(int p, int l, int r, int o) {
	if(p <= 1) return 0;
	if(r < p) return c[o];
	return max(qry(p, lch), p - 1 > mid ? qry(p, rch) : 0);
}
void dfs(int u) {
	bld(pos[u], 1, n, T[u]);
	for(int v : G[u]) dfs(v), T[u] = mrg(T[u], T[v]);
}
void Dfs(int u) {
	int v = u, ps = pos[u];
	per(i, 18, 0) if(fa[i][v] > 1 && ps - qry(ps, 1, n, T[fa[i][v]]) + len[fa[i][v]] > len[u]) v = fa[i][v];
	as = max(as, dp[u] = dp[f[v]] + 1);
	for(int v : G[u]) Dfs(v);
}

int main() {
	scanf("%d%s", &n, s + 1);
	if(n <= 30000) {
		static int f[N], g[N];
		For(i, 0, n) {
			g[1] = 1;
			int k = 0;
			if(n - i <= as) break;
			rep(j, 2, n - i) {
				while(k && s[i + j] != s[i + k + 1]) k = f[k];
				if(s[i + j] == s[i + k + 1]) k++;
				as = max(as, g[j] = g[f[j] = k] + 1);
			}
		}
		cout << max(as, 1), exit(0);
	}
	rep(i, 1, n) ins(s[i] - 97, i);
	rep(i, 1, sz) G[f[i]].pb(i), fa[0][i] = f[i];
	rep(i, 1, 18) rep(j, 1, sz) fa[i][j] = fa[i - 1][fa[i - 1][j]];
	sz = 0, dfs(1), Dfs(1), cout << as - 1;
	return 0;
}