#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 2e5 + 5;

int T, n, a[N], d[N], fa[N], ma;
vector <int> G[N];

void dfs(int u, int ls, int& nw) {
	if(!a[nw] || d[u] > ma) nw = u, ma = d[u];
	for(int v : G[u]) if(v ^ fa[u]) {
		fa[v] = u, d[v] = d[u] + (a[v] + ls == 3);
		dfs(v, a[v] ? a[v] : ls, nw);
	}
}

int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]), G[i].clear();
		int u, v;
		rep(i, 2, n) scanf("%d%d", &u, &v), G[u].pb(v), G[v].pb(u);
		d[1] = 1, fa[1] = ma = 0, dfs(1, a[1], u);
		d[u] = 1, fa[u] = ma = 0, dfs(u, a[u], v);
		printf("%d\n", d[v] / 2 + 1);
	}
	return 0;
}