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

int T, N, tmp, ret, k1, k2;
vector<int> x, y, adj[1005];

void dfs(int n, int e = -1) {
	if (binary_search(x.begin(), x.end(), n)) {
		ret = n;
		return;
	}
	for (auto u : adj[n]) if (u != e) dfs(u, n);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1, u, v; i < N; i++) {
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		cin >> k1;
		for (int i = 0; i < k1; i++) {
			cin >> tmp;
			x.pb(tmp);
		}
		cin >> k2;
		for (int i = 0; i < k2; i++) {
			cin >> tmp;
			y.pb(tmp);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		cout << "B " << y[0] << endl;
		cin >> tmp;
		dfs(tmp);
		cout << "A " << ret << endl;
		cin >> tmp;
		cout << "C ";
		if (binary_search(y.begin(), y.end(), tmp)) cout << ret << endl;
		else cout << "-1" << endl;
		for (int i = 1; i <= N; i++) adj[i].clear();
		x.clear();
		y.clear();
	}
}