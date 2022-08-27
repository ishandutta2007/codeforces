#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7, inf = 1e9 + 7;
vector<int> e[N], E[N];
bool vis[N];
int n, m, q, stk[N], stot, dfn[N], low[N], idtot, cnt;
multiset<int> mt[N];
void dfs(int u) {
	vis[u] = true, low[u] = dfn[u] = ++idtot, stk[++stot] = u;
	for(int v : e[u]) {
		if(!dfn[v]) {
			dfs(v), low[u] = min(low[u], low[v]);
			if(low[v] == dfn[u]) {
				++cnt;
				for(int x = 0; x != v; )	
					x = stk[stot--], vis[x] = 0, E[cnt].push_back(x), E[x].push_back(cnt);
				E[cnt].push_back(u), E[u].push_back(cnt);
			}
		}
		if(vis[u]) low[u] = min(low[u], dfn[v]);
	}
}
int ch[N][2], fa[N], mn[N] = {inf}, w[N], flag[N];
void upd(int x) {
	mn[x] = min(w[x], min(mn[ch[x][0]], mn[ch[x][1]]));
}
bool get(int x) {
	return ch[fa[x]][0] == x || ch[fa[x]][1] == x;
}
void flip(int x) {
	if(x) flag[x] ^= 1, swap(ch[x][0], ch[x][1]);
} 
void pushdown(int x) {
	if(flag[x]) flip(ch[x][0]), flip(ch[x][1]), flag[x] ^= 1;
}
void rotate(int x) {
	int y = fa[x], z = fa[y], fson = (ch[y][1] == x), ano = ch[x][fson ^ 1];
	if(get(y)) ch[z][ch[z][1] == y] = x;
	if(ano) fa[ano] = y;
	fa[y] = x, fa[x] = z, ch[x][fson ^ 1] = y, ch[y][fson] = ano;
	upd(y), upd(x);
}
int f[N], ftot, fx;
void Splay(int x) {
	f[++ftot] = fx = x;
	while(get(fx)) fx = f[++ftot] = fa[fx];
	while(ftot) pushdown(f[ftot--]);
	while(get(x)) {
		int y = fa[x], z = fa[y];
		if(get(y)) rotate((ch[y][1] == x) ^ (ch[z][1] == y) ? x : y);
		rotate(x);
	}
}
void access(int x) {
	for(int y = 0; x; y = x, x = fa[x]) Splay(x), ch[x][1] = y, upd(x);
}
void makeroot(int x) {
	access(x), Splay(x), flip(x);
}
void split(int x, int y) {
	makeroot(x), access(y), Splay(y);
}
multiset< int > st[N];
int Fa[N], dep[N], up[20][N];
int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	R(i, 18, 0) if(dep[x] - dep[y] >= (1 << i)) x = up[i][x];
	if(x == y) return x;
	R(i, 18, 0) if(up[i][x] ^ up[i][y]) x = up[i][x], y = up[i][y];
	return Fa[x];
}
void DFS(int u) {
	for(int v : E[u]) if(Fa[u] ^ v) dep[v] = dep[u] + 1, Fa[v] = u, DFS(v);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> q, cnt = n;
	L(i, 1, n) cin >> w[i];
	L(i, 1, m) {
		int u, v; cin >> u >> v;
		e[u].push_back(v), e[v].push_back(u);
	}
	dfs(1), DFS(1);
	L(i, 1, cnt) up[0][i] = Fa[i];
	L(i, 1, 18) L(j, 1, cnt) up[i][j] = up[i - 1][up[i - 1][j]];
	L(i, 1, n) if(Fa[i]) mt[Fa[i]].insert(w[i]);
	L(i, n + 1, cnt) w[i] = * mt[i].begin();
	L(i, 1, cnt) upd(i), fa[i] = Fa[i];
	while(q--) {
		char opt[100]; int u, v; 
		cin >> opt >> u >> v;
		if(opt[0] == 'C') {
			if(Fa[u]) mt[Fa[u]].erase(mt[Fa[u]].lower_bound(w[u]));
			split(u, u), w[u] = v;
			if(Fa[u]) mt[Fa[u]].insert(w[u]), split(Fa[u], Fa[u]), w[Fa[u]] = mn[Fa[u]] = *mt[Fa[u]].begin();
		}
		else {
			split(u, v);
			int LCA = lca(u, v), ans = mn[v];
			if(LCA > n && Fa[LCA]) ans = min(ans, w[Fa[LCA]]);
			cout << ans << "\n";
		}
	} 
	return 0;
}