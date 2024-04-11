#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define upd(a, b) (a = min(a, b))

using namespace std;
const int N = 605;
int V, e, n, K, x[N], dis[N][N];
int vis[N], mch[N];
vector <int> G[N];
int dfs(int u, int s) {
	if(vis[u] == s) return 0;
	vis[u] = s;
	for(int v : G[u]) if(!mch[v] || dfs(mch[v], s)) return mch[v] = u, 1;
	return 0;
}
int chk(int mid, int res = 0) {
	rep(i, 1, n) {
		G[i].clear();
		rep(j, 1, V) if(dis[x[i]][j] <= mid) G[i].push_back(j);
	}
	mem(vis, 0), mem(mch, 0);
	rep(i, 1, n) if((res += dfs(i, i)) == K) return 1;
	return 0;
}
int main() {
	mem(dis, 63);
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> V >> e >> n >> K;
	rep(i, 1, n) scanf("%d", &x[i]);
	rep(i, 1, V) dis[i][i] = 0;
	for(int u, v, w; e--; scanf("%d%d%d", &u, &v, &w), upd(dis[u][v], w), upd(dis[v][u], w));
	rep(k, 1, V) rep(i, 1, V) rep(j, 1, V) upd(dis[i][j], dis[i][k] + dis[k][j]);
	if(!chk(0x3f3f3f3f - 1)) puts("-1"), exit(0);
	int l = 0, r = V * 10000, mid;
	while(l <= r) {
		mid = (l + r) / 2;
		if(chk(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << l;
	return 0;
}