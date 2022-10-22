#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back

using namespace std;
const int N = 2e5 + 5;

int n, m, a0[N], a1[N], b0[N], b1[N];
int vis[N], K[N], in[N], tp, stk[N];
vector <pair <int, int>> G[N];
void Dfs(int u) {
	for(auto [v, w] : G[u]) if(!vis[v])
		K[w] = a0[w] == v ? a1[w] : b1[w], vis[v] = 1, Dfs(v);
}
int dfs(int u, int lst) {
	stk[++tp] = u, in[u] = 1;
	for(auto [v, w] : G[u]) if(!vis[v] && w ^ lst) if(in[v]) {
		K[w] = a0[w] == v ? a1[w] : b1[w];
		int p = find(stk + 1, stk + tp + 1, v) - stk;
		rep(i, p, tp) vis[stk[i]] = 1;
		rep(i, p, tp) Dfs(stk[i]);
		return tp--, in[u] = 0, 1;
	} else {
		K[w] = a0[w] == v ? a1[w] : b1[w];
		if(dfs(v, w)) return tp--, in[u] = 0, 1;
	}
	return tp--, in[u] = 0;
}

int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	int k, x, y;
	rep(i, 1, n) for(scanf("%d", &k); k--;) {
		scanf("%d", &x), y = x > 0, x = abs(x);
		if(a0[x]) b0[x] = i, b1[x] = y;
		else a0[x] = i, a1[x] = y;
	}
	rep(i, 1, m) if(b0[i] && a1[i] ^ b1[i])
		G[a0[i]].eb(b0[i], i), G[b0[i]].eb(a0[i], i);
	else K[i] = a1[i], vis[a0[i]] = vis[b0[i]] = 1;
	rep(i, 1, n) if(vis[i]) Dfs(i);
	rep(i, 1, n) if(!vis[i] && !dfs(i, 0)) puts("NO"), exit(0);
	puts("YES");
	rep(i, 1, m) printf("%d", K[i]); 
	return 0;
}