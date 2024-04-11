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
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int T, N, sz[300005];
vector<int> adj[300005];

int init(int n, int e = -1) {
	sz[n] = 1;
	for (auto u : adj[n]) if (u != e)
		sz[n] += init(u, n);
	return sz[n];
}

int dp(int n, int e = -1) {
	vector<int> vec;
	for (auto u : adj[n]) if (u != e)
		vec.pb(u);
	if (vec.size() == 1) return sz[vec[0]] - 1;
	else if (vec.empty()) return 0;
	else return max(dp(vec[1], n) + sz[vec[0]] - 1, dp(vec[0], n) + sz[vec[1]] - 1);
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
			adj[u].pb(v);
			adj[v].pb(u);
		}
		init(1);
		cout << dp(1) << '\n';
	}
}