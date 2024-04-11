#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define upd(a, b) (a = min(a, b))

using namespace std;
const int N = 605;
typedef long long ll;
const ll Inf = 0x3f3f3f3f3f3f3f3f;
int n, m, q, u[N * N], v[N * N], w[N * N];
ll dis[N][N], Dis[N][N];

int main() {
	mem(dis, 63), mem(Dis, 63);
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	rep(i, 1, m) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		upd(dis[u[i]][v[i]], (ll)w[i]);
		upd(dis[v[i]][u[i]], (ll)w[i]);
	}
	int uu, vv, ww;
	cin >> q;
	while(q--) {
		scanf("%d%d%d", &uu, &vv, &ww);
		upd(Dis[uu][vv], -(ll)ww);
		upd(Dis[vv][uu], -(ll)ww);
	}
	rep(k, 1, n) rep(i, 1, n) rep(j, 1, n)
		upd(dis[i][j], dis[i][k] + dis[k][j]);
	rep(k, 1, n) rep(i, 1, n) rep(j, 1, n)
		upd(Dis[i][j], min(Dis[i][k] + dis[k][j], dis[i][k] + Dis[k][j]));
	int ans = 0;
	rep(i, 1, m) if(Dis[u[i]][v[i]] + w[i] <= 0) ans++;
	cout << ans;
	return 0;
}