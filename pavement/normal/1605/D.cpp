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

int T, N, out[200005];
bool col[200005];
vector<int> to[2], adj[200005], vec[35];

void dfs(int n, int e = -1) {
	to[col[n]].pb(n);
	for (auto u : adj[n])
		if (u != e) {
			col[u] = !col[n];
			dfs(u, n);
		}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < 30; i++) vec[i].clear();
		for (int i = 1; i <= N; i++) adj[i].clear();
		to[0].clear();
		to[1].clear();
		for (int i = 1; i <= N; i++) {
			int cur = -1;
			for (int j = 0; j < 30; j++)
				if (i & (1 << j)) cur = j;
			vec[cur].pb(i);
		}
		for (int i = 1, u, v; i < N; i++) {
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1);
		if (to[0].size() > to[1].size()) swap(to[0], to[1]);
		int x = to[0].size(), cnt = 0, cnt2 = 0;
		for (int i = 0; i < 30; i++)
			if (x & (1ll << i)) for (int j : vec[i]) out[to[0][cnt++]] = j;
			else for (int j : vec[i]) out[to[1][cnt2++]] = j;
		assert(cnt == to[0].size() && cnt2 == to[1].size());
		for (int i = 1; i <= N; i++) cout << out[i] << ' ';
		cout << '\n';
	}
}