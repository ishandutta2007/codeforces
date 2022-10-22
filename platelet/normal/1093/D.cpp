#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 3e5 + 5, P = 998244353;
int T, n, m, co[N], sz[3];
vector <int> G[N];
int calc(int x, int r = 1) { while(x--) r = r * 2 % P; return r; }
int dfs(int u) {
	sz[co[u]]++;
	for(int v : G[u]) if(co[u] == co[v]) return 0;
	else if(!co[v] && (co[v] = 3 - co[u], !dfs(v))) return 0;
	return 1;
}
int solve() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) co[i] = 0, G[i].clear();
	for(int u, v; m--; scanf("%d%d", &u, &v), G[u].push_back(v), G[v].push_back(u));
	int ans = 1;
	rep(i, 1, n) if(!co[i]) {
		co[i] = 1, sz[1] = sz[2] = 0;
		if(!dfs(i)) return 0;
		ans = 1ll * ans * (calc(sz[1]) + calc(sz[2])) % P;
	}
	return ans;
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--; printf("%d\n", solve()));
	return 0;
}