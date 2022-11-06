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
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
using ordered_set = tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update>;

int N, M, pos[200005], st[200005], t[200005], u[200005], v[200005];
bool inv, col[200005], vis[200005];
vector<int> topo, adj[200005], adj2[200005];

void dfs(int n) {
	vis[n] = 1;
	for (auto u : adj[n])
		if (!vis[u]) {
			col[u] = col[n] ^ 1;
			dfs(u);
		} else if (col[u] == col[n]) inv = 1;
}

void dfs2(int n) {
	st[n] = 1;
	for (auto u : adj2[n])
		if (st[u] == 1) inv = 1;
		else if (st[u] == 0) dfs2(u);
	st[n] = 2;
	topo.pb(n);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> t[i] >> u[i] >> v[i];
		adj[u[i]].pb(v[i]);
		adj[v[i]].pb(u[i]);
	}
	for (int i = 1; i <= N; i++)
		if (!vis[i]) dfs(i);
	if (inv) return cout << "NO\n", 0;
	for (int i = 1; i <= M; i++) {
		if (t[i] == 1) {
			if (col[u[i]] == 0) adj2[v[i]].pb(u[i]);
			else adj2[u[i]].pb(v[i]);
		} else {
			if (col[u[i]] == 1) adj2[v[i]].pb(u[i]);
			else adj2[u[i]].pb(v[i]);
		}
	}
	for (int i = 1; i <= N; i++)
		if (st[i] == 0) dfs2(i);
	if (inv) cout << "NO\n";
	else {
		cout << "YES\n";
		for (int i = 0; i < topo.size(); i++)
			pos[topo[i]] = i + 1;
		for (int i = 1; i <= N; i++)
			cout << (col[i] ? 'R' : 'L') << ' ' << pos[i] << '\n';
	}
}