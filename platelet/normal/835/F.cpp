#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define eb emplace_back
#define fi first
#define se second

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, m, cyc[N];
ll d[N], L[2][N], R[2][N], mx[2][N];
vector<pair<int, int>> G[N];
bool on[N];

bool find(int u, int fa, int tp) {
	if(on[u]) {
		int ls = find(cyc + 1, cyc + tp, u) - cyc;
		mem(on, 0);
		For(i, ls, tp) on[cyc[++m] = cyc[i]] = 1;
		return 1;
	}
	on[cyc[tp] = u] = 1;
	for(auto [v, w] : G[u]) if(v != fa && find(v, u, tp + 1)) return 1;
	return on[u] = 0;
}
pair<ll, int> dfs(int u, int fa) {
	pair<ll, int> res(0, u);
	for(auto [v, w] : G[u]) if(v != fa && !on[v]) {
		auto tmp = dfs(v, u);
		tmp.fi += w, res = max(res, tmp);
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int u, v, w;
	rep(i, 1, n) cin >> u >> v >> w, G[u].eb(v, w), G[v].eb(u, w);
	find(1, 0, 1);
	ll D = 0;
	rep(i, 1, m) on[cyc[i]] = 0, tie(d[i], u) = dfs(cyc[i], 0), D = max(D, dfs(u, 0).fi), on[cyc[i]] = 1;
	rep(k, 0, 1) {
		if(k) L[k][1] = d[1];
		R[k][1] = d[1];
		ll len = 0;
		rep(i, 2, m) for(auto [v, w] : G[cyc[i]]) if(v == cyc[i - 1]) {
			L[k][i] = max(L[k][i - 1], (len += w) + d[i]);
			R[k][i] = max(R[k][i - 1] + w, d[i]);
			mx[k][i] = max(mx[k][i - 1], R[k][i - 1] + w + d[i]);
		}
		if(!k) reverse(cyc + 2, cyc + m + 1), reverse(d + 2, d + m + 1);
	}
	ll ans = 1e18;
	rep(i, 1, m) ans = min(ans, max({mx[0][i], mx[1][m + 1 - i], L[0][i] + L[1][m + 1 - i]}));
	cout << max(ans, D);
}