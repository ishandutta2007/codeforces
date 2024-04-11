#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back
#define upd(a, b) (a = min(a, b))

using namespace std;

typedef long long ll;
const int N = 2e5 + 5;

int n, m, q;
vector <pair <int, int>> G[N];
int idx, dfn[N], scc[N], stk[N], tp, sid;
ll g[N], d[N], gg[N];

int dfs(int u) {
	int low = dfn[u] = ++idx; stk[++tp] = u;
	for(auto vw : G[u]) {
		int v = vw.first, w = vw.second;
		if(!dfn[v]) d[v] = d[u] + w, upd(low, dfs(v));
		else if(!scc[v]) upd(low, dfn[v]), g[u] = __gcd(g[u], d[u] - d[v] + w);
	}
	if(low == dfn[u]) for(int v = (sid++, 0); v ^ u;)
		v = stk[tp--], scc[v] = sid, gg[sid] = __gcd(gg[sid], g[v]);
	return low;
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	int u, v, w;
	rep(i, 1, m) scanf("%d%d%d", &u, &v, &w), G[u].eb(v, w);
	rep(i, 1, n) if(!dfn[i]) dfs(i);
	for(cin >> q; q--; puts(v % __gcd(gg[scc[u]], (ll)w) ? "NO" : "YES"))
		scanf("%d%d%d", &u, &v, &w);
	return 0;
}