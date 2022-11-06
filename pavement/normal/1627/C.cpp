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

int T, N, st, curr, lab[300005];
vector<ii> adj[100005];

void dfs(int n, int e = -1) {
	st = n;
	for (auto u : adj[n]) if (u.first != e) dfs(u.first, n);
}

void dfs2(int n, int e = -1) {
	for (auto u : adj[n]) if (u.first != e) {
		if (curr & 1) lab[u.second] = 2;
		else lab[u.second] = 3;
		curr++;
		dfs2(u.first, n);
	}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) adj[i].clear();
		for (int i = 1, u, v; i < N; i++) {
			cin >> u >> v;
			adj[u].eb(v, i);
			adj[v].eb(u, i);
		}
		bool cannot = 0;
		for (int i = 1; i <= N; i++)
			if (adj[i].size() > 2) cannot = 1;
		if (cannot) {
			cout << "-1\n";
			continue;
		}
		dfs(1);
		dfs2(st);
		for (int i = 1; i < N; i++) cout << lab[i] << ' ';
		cout << '\n';
	}
}