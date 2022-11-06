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

int T, N, root, P[200005];
vector<int> adj[200005];
vector<ii> paths;

vector<int> get_path(int s, int e) {
	vector<int> curr_path;
	while (s != e) {
		curr_path.pb(e);
		e = P[e];
	}
	curr_path.pb(s);
	reverse(curr_path.begin(), curr_path.end());
	return curr_path;
}

int dfs(int n) {
	int ed = n;
	bool tk = 0;
	for (auto u : adj[n]) {
		if (!tk) ed = dfs(u), tk = 1;
		else paths.eb(u, dfs(u));
	}
	return ed;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> P[i];
			if (P[i] == i) root = i;
			else adj[P[i]].pb(i);
		}
		paths.eb(root, dfs(root));
		cout << paths.size() << '\n';
		for (auto i : paths) {
			auto curr = get_path(i.first, i.second);
			cout << curr.size() << '\n';
			for (auto j : curr) cout << j << ' ';
			cout << '\n';
		}
		for (int i = 1; i <= N; i++) adj[i].clear();
		paths.clear();
	}
}