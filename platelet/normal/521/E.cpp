#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 2e5 + 5;
typedef vector <int> vi;
int n, m; vi G[N];
int idx, dfn[N], fa[N], ma;
struct node {
	int u, fa, U, Fa;
	node(int uu) { u = fa = U = Fa = uu; }
	void upd(int uu, int ffa) {
		if(dfn[ffa] < dfn[fa]) U = u, Fa = fa, u = uu, fa = ffa;
		else if(dfn[ffa] < dfn[Fa]) U = uu, Fa = ffa;
	}
} as(0);
node dfs(int u) {
	dfn[u] = ++idx; node lowu(u);
	for(int v : G[u]) if(!dfn[v]) {
		fa[v] = u;
		node lowv = dfs(v);
		lowu.upd(lowv.u, lowv.fa), lowu.upd(lowv.U, lowv.Fa);
	} else if(dfn[v] < dfn[u] && v ^ fa[u]) lowu.upd(u, v);
	if(!ma && dfn[lowu.Fa] < dfn[u]) as = lowu, ma = u;
	return lowu;
}
vi find(int s, int t) {
	vi p;
	while(s ^ t) p.pb(s), s = fa[s];
	p.pb(t);
	return p;
}
vi p;
void print() {
	printf("%llu ", p.size());
	for(int u : p) printf("%d ", u);
	puts("");
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	int u, v;
	rep(i, 1, m) scanf("%d%d", &u, &v), G[u].pb(v), G[v].pb(u);
	rep(i, 1, n) if(!ma && !dfn[i]) dfs(i);
	if(ma) {
		puts("YES");
		p = find(ma, as.Fa), print();
		p = find(as.U, ma), reverse(p.begin(), p.end());
		p.pb(as.Fa), print();
		p = find(as.Fa, as.fa); vi t = find(as.u, ma);
		p.insert(p.end(), t.begin(), t.end());
		reverse(p.begin(), p.end()), print();
	} else puts("NO");
	return 0;
}