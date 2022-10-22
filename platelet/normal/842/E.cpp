#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 3e5 + 5;
int n, dfn[N], rk[N], idx, d[N], fa[19][N];
vector <int> G[N];
void dfs(int u) {
	dfn[u] = ++idx, rk[idx] = u;
	rep(i, 1, 18) fa[i][u] = fa[i - 1][fa[i - 1][u]];
	for(int v : G[u]) d[v] = d[u] + 1, fa[0][v] = u, dfs(v);
}
int dis(int u, int v) {
	u = rk[u], v = rk[v];
	if(d[u] < d[v]) swap(u, v);
	int re = d[u] - d[v];
	per(i, 18, 0) if(d[u] - (1 << i) >= d[v]) u = fa[i][u];
	if(u == v) return re;
	per(i, 18, 0) if(fa[i][u] ^ fa[i][v])
		u = fa[i][u], v = fa[i][v], re += 2 << i;
	return re + 2;
}

int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n, n++;
	int f;
	rep(i, 2, n) scanf("%d", &f), G[f].pb(i);
	dfs(1);
	int u = 1, v = 1, D = 0;
	set <int> s = {1};
	rep(k, 2, n) {
		int i = dfn[k];
		if(dis(i, u) > D) v = i, D++;
		if(dis(i, v) > D) u = i, D++;
		if(dis(i, u) == D || dis(i, v) == D) s.insert(i);
		auto chk = [&](int x) {
			if(dis(x, u) < D && dis(x, v) < D) return s.erase(x), 1;
			return 0;
		};
		while(chk(i < *s.rbegin() ? *s.upper_bound(i) : *s.begin()));
		while(chk(i > *s.begin() ? *--s.lower_bound(i) : *s.rbegin()));
		printf("%llu\n", s.size());
	}
	return 0;
}