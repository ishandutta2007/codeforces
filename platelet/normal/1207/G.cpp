#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 4e5 + 5;
int n, m, sz = 1, ch[N*2][26], f[N*2];
char s[N]; int id[N], c[N*2], q[N*2];
vector <int> G[N*2]; vector <pair <int, int> > Q[N*2];
int idx, dfn[N*2], suf[N*2], ans[N*2];
int& son(int o, int c) {
	int& r = ch[o][c]; if(!r) f[r = ++sz] = o;
	return r;
}
void add(int i, int v) { for(; i <= sz; i += i & -i) c[i] += v; }
int qry(int i, int r = 0) { for(; i; i &= i - 1) r += c[i]; return r; }
void dfs(int u) { dfn[u] = ++idx; for(int v : G[u]) dfs(v); suf[u] = idx; }
void Dfs(int u) {
	add(dfn[u], 1);
	for(auto [ed, i] : Q[u]) ans[i] = qry(suf[ed]) - qry(dfn[ed] - 1);
	rep(i, 0, 25) if(ch[u][i]) Dfs(ch[u][i]);
	add(dfn[u], -1);
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	int op, x; char c[2];
	rep(i, 1, n) {
		scanf("%d", &op);
		if(op == 1) scanf("%s", c), id[i] = son(1, c[0] - 97);
		else scanf("%d%s", &x, c), id[i] = son(id[x], c[0] - 97);
	}
	cin >> m;
	rep(i, 1, m) {
		scanf("%d%s", &x, s);
		int o = 1;
		for(char* j = s; *j; j++) o = son(o, *j - 97);
		Q[id[x]].push_back(make_pair(o, i));
	}
	int l = 1, r = 0;
	rep(i, 0, 25) if(ch[1][i]) G[1].push_back(q[++r] = ch[1][i]);
	for(; l <= r; l++) rep(i, 0, 25) {
		int o = ch[q[l]][i];
		if(!o) continue;
		int& j = f[q[++r] = o] = f[f[o]];
		while(j > 1 && !ch[j][i]) j = f[j];
		if(ch[j][i]) j = ch[j][i];
		G[j].push_back(o);
	}
	dfs(1), Dfs(1);
	rep(i, 1, m) printf("%d\n", ans[i]);
	return 0; 
}