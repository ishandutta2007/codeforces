#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, tcnt, vcnt, C[300005], cnt[300005], sub[300005];
bool out[300005];
vector<int> adj[300005];

int dfs(int n, int e = -1) {
	sub[n] = C[n];
	for (auto u : adj[n]) if (u != e) {
		if (C[u]) cnt[n]++;
		sub[n] += dfs(u, n);
	}
	if ((C[n] || cnt[n]) && sub[n] >= 2) vcnt++;
	return sub[n];
}

void reroot(int n, int e = -1) {
	out[n] = vcnt;
	for (auto u : adj[n]) if (u != e) {
		if ((C[n] || cnt[n]) && sub[n] >= 2) vcnt--;
		if ((C[u] || cnt[u]) && sub[u] >= 2) vcnt--;
		iiii tmp = mt(sub[n], cnt[n], sub[u], cnt[u]);
		sub[n] -= sub[u];
		if (C[u]) cnt[n]--;
		if (C[n]) cnt[u]++;
		sub[u] = tcnt;
		if ((C[n] || cnt[n]) && sub[n] >= 2) vcnt++;
		if ((C[u] || cnt[u]) && sub[u] >= 2) vcnt++;
		reroot(u, n);
		if ((C[n] || cnt[n]) && sub[n] >= 2) vcnt--;
		if ((C[u] || cnt[u]) && sub[u] >= 2) vcnt--;
		tie(sub[n], cnt[n], sub[u], cnt[u]) = tmp;
		if ((C[n] || cnt[n]) && sub[n] >= 2) vcnt++;
		if ((C[u] || cnt[u]) && sub[u] >= 2) vcnt++;
	}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> C[i];
		out[i] = C[i];
		tcnt += C[i];
	}
	for (int i = 1, u, v; i < N; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
		if (C[u]) out[v] = 1;
		if (C[v]) out[u] = 1;
	}
	dfs(1);
	reroot(1);
	for (int i = 1; i <= N; i++) cout << out[i] << ' ';
	cout << '\n';
}