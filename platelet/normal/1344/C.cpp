#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define repe(u) for(int i = head[u], v; v = e[i].v, i; i = e[i].nxt) 

using namespace std;
const int N = 2e5 + 5;
int n, m, cnt, head[N], vis[N], in[N], u, v, ans, op[N];
int idx, dfn[N], g[N], f[N]; 
struct edge { int v, nxt; } e[N];
void add(int u, int v) {
	e[++cnt] = (edge){ v, head[u] };
	head[u] = cnt;
}
int dfs(int u) {
	vis[u] = in[u] = 1;
	repe(u) if(in[v] || (!vis[v] && !dfs(v))) return 0;
	return in[dfn[++idx] = u] = 0, 1;
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	rep(i, 1, m) scanf("%d%d", &u, &v), add(u, v);
	rep(i, 1, n) if(!vis[i] && !dfs(i)) return puts("-1"), 0;
	mem(g, 0x3f), mem(f, 0x3f);
	rep(j, 1, n) repe(dfn[j]) g[dfn[j]] = min(g[dfn[j]], min(v, g[v]));
	per(j, n, 1) repe(dfn[j]) f[v] = min(f[v], min(dfn[j], f[dfn[j]]));
	rep(i, 1, n) if(min(g[i], f[i]) > i) ans++, op[i] = 1;
	cout << ans << endl;
	rep(i, 1, n) putchar(op[i] ? 'A' : 'E'); 
	return 0;
}