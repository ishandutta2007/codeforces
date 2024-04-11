#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 5005;
int n, m, idx, co[N], pre[N][N];
int n1, n2, n3, ans[N];
vector <int> G[N], f[N][2];
int dfs(int u) {
	f[idx][co[u] - 1].push_back(u);
	for(int v : G[u])
	if(co[u] == co[v] || (!co[v] && !dfs((co[v] = 3 - co[u], v)))) return 0;
	return 1;
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m >> n1 >> n2 >> n3;
	for(int u, v; m--;) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
	}
	pre[0][0] = -1;
	rep(i, 1, n) if(!co[i]) {
		idx++, co[i] = 1;
		if(!dfs(i)) puts("NO"), exit(0);
		rep(j, 0, n) {
			int j0 = j - f[idx][0].size(), j1 = j - f[idx][1].size();
			if(j0 >= 0) if(pre[idx - 1][j0]) pre[idx][j] = 1;
			if(j1 >= 0) if(pre[idx - 1][j1]) pre[idx][j] = 2;
		}
	}
	if(pre[idx][n2]) {
		puts("YES");
		per(i, idx, 1) {
			if(pre[i][n2] == -1) continue;
			int b = pre[i][n2] - 1;
			for(int x : f[i][b]) ans[x] = 2;
			n2 -= f[i][b].size();
		}
		int j = 1;
		while(n1--) { while(ans[j]) j++; ans[j] = 1; }
		while(n3--) { while(ans[j]) j++; ans[j] = 3; }
		rep(i, 1, n) printf("%d", ans[i]);
	} else puts("NO");
}