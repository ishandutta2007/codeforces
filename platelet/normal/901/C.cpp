#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define upd(a, b) (a = max(a, b))

using namespace std;
const int N = 3e5 + 5;
typedef long long ll;
int n, m, K;
vector <int> G[N];
int Max[N], d[N], fa[N];
ll c[N], cc[N], ans[N];
vector <pair <int, int>> q[N];
void dfs(int u) {
	for(int v : G[u]) if(!d[v]) d[v] = d[fa[v] = u] + 1, dfs(v);
	else if(v ^ fa[u] && d[v] < d[u]) {
		int mi = 1e9, ma = 0;
		for(int i = u; d[i] >= d[v]; i = fa[i])
			mi = min(mi, i), ma = max(ma, i);
		upd(Max[ma], mi);
	}
}
void add(int i, int v) {
	for(int x = i * v; i <= n; i += i & -i)
		c[i] += v, cc[i] += x;
}
ll qry(int i, ll r = 0) {
	for(int x = i + 1; i; i &= i - 1) r += x * c[i] - cc[i];
	return r;
}

int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	for(int u, v; m--; scanf("%d%d", &u, &v), G[u].push_back(v), G[v].push_back(u));
	rep(i, 1, n) if(!d[i]) d[i] = 1, dfs(i);
	rep(i, 1, n) upd(Max[i], Max[i - 1]);
	cin >> K;
	int l, r;
	rep(i, 1, K) scanf("%d%d", &l, &r), q[r].push_back({ l, i });
	rep(i, 1, n) {
		add(Max[i] + 1, 1), add(i + 1, -1);
		for(auto [l, id] : q[i]) ans[id] = qry(i) - qry(l - 1);
	}
	rep(i, 1, K) printf("%lld\n", ans[i]);
	return 0;
}