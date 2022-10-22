#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define add(u, v) G[u].pb({v, ++idx}), G[v].pb({u, idx}), d[u]++, d[v]++

using namespace std;
const int V = 1e5 + 5, E = V * 2;
int n, m, idx, d[V], vis[E + V];
vector <pair <int, int>> G[V], as;
void dfs(int u) {
	while(!G[u].empty()) {
		auto [v, w] = G[u].back(); G[u].pop_back();
		if(!vis[w]) vis[w] = 1, dfs(v), as.pb({u, v});
	}
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	int u, v;
	rep(i, 1, m) scanf("%d%d", &u, &v), add(u, v);
	int lst = 0;
	rep(i, 1, n) if(d[i] & 1) if(lst) add(lst, i), lst = 0; else lst = i;
	if(idx & 1) add(1, 1);
	dfs(1);
	cout << idx << endl;
	for(auto [u, v] : as) {
		if(lst) swap(u, v);
		printf("%d %d\n", u, v);
		lst ^= 1;
	}
	return 0;
}