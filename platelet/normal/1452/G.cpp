#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define upd(a, b) (a = max(a, b))

using namespace std;
const int N = 2e5 + 5;
int n, K, d[N], q[N], ma[N], as[N];
vector <int> G[N];
void dfs(int u, int r, int re) {
	if(ma[u] >= r) return;
	upd(as[u], re), upd(ma[u], r);
	for(int v : G[u]) dfs(v, r - 1, re);
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	mem(d, -1);
	cin >> n;
	int u, v;
	rep(i, 2, n) scanf("%d%d", &u, &v), G[u].pb(v), G[v].pb(u);
	cin >> K;
	int l = 1, r = 0;
	while(K--) scanf("%d", &u), q[++r] = u, d[u] = 0;
	while(l <= r) {
		int u = q[l++];
		for(int v : G[u]) if(!~d[v]) q[++r] = v, d[v] = d[u] + 1;
	}
	per(i, n, 1) dfs(q[i], d[q[i]], d[q[i]]);
	rep(i, 1, n) printf("%d ", as[i]);
	return 0;
}