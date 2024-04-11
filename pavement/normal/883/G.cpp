#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
#define int long long
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, S, cnt, T[300005], dir[300005];
bool vis[300005];
vector<iii> adj[300005];

void dfs(int n) {
	if (vis[n]) return;
	cnt++;
	vis[n] = 1;
	for (auto u : adj[n])
		if (g0(u) != -1 && dir[g0(u)] == -1) {
			dir[g0(u)] = g1(u);
			dfs(g2(u));
		} else if (g0(u) == -1) dfs(g2(u));
}

void dfs2(int n) {
	if (vis[n]) return;
	cnt++;
	vis[n] = 1;
	for (auto u : adj[n])
		if (g0(u) != -1 && dir[g0(u)] == -1) dir[g0(u)] = !g1(u);
		else if (g0(u) == -1) dfs2(g2(u));
}

main() {
	memset(dir, -1, sizeof dir);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> S;
	for (int u, v, i = 1; i <= M; i++) {
		cin >> T[i] >> u >> v;
		if (T[i] == 1) adj[u].eb(-1, -1, v);
		else adj[u].eb(i, 0, v), adj[v].eb(i, 1, u);
	}
	dfs(S);
	cout << cnt << '\n';
	for (int i = 1; i <= M; i++)
		if (T[i] == 2) cout << (max(0ll, dir[i]) ? '-' : '+');
	cout << '\n';
	cnt = 0;
	memset(dir, -1, sizeof dir);
	memset(vis, 0, sizeof vis);
	dfs2(S);
	cout << cnt << '\n';
	for (int i = 1; i <= M; i++)
		if (T[i] == 2) cout << (max(0ll, dir[i]) ? '-' : '+');
	cout << '\n';
}