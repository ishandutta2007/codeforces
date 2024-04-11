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

int N, E, A, dp[200005];
ordered_set<ii> adj[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> E;
	for (int i = 1, u, v, w; i <= E; i++) {
		cin >> u >> v >> w;
		int lo = 0, hi = (int)adj[u].size() - 1, ans = 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (adj[u].find_by_order(mid)->first < w) ans = adj[u].find_by_order(mid)->second + 1, lo = mid + 1;
			else hi = mid - 1;
		}
		dp[i] = ans;
		bool inv = 0;
		auto it = adj[v].lower_bound(mp(w, -1ll));
		if (it != adj[v].begin()) {
			--it;
			if (it->second >= dp[i]) inv = 1;
			++it;
		}
		if (!inv) {
			vector<ordered_set<ii>::iterator> to_del;
			while (it != adj[v].end() && it->second <= dp[i]) {
				to_del.pb(it);
				++it;
			}
			for (auto j : to_del) adj[v].erase(j);
			adj[v].insert(mp(w, dp[i]));
		}
		A = max(A, dp[i]);
	}
	cout << A << '\n';
}