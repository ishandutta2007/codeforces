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

int T, N, M, lnk[2000005], lnk_2[2000005], sz[2000005], sz_2[2000005];
vector<int> adj[2000005], adj_2[2000005];
vector<ii> bad, edges;
map<ii, bool> marked;

int find(int x) {
	if (x == lnk[x]) return x;
	return lnk[x] = find(lnk[x]);
}

int find_2(int x) {
	if (x == lnk_2[x]) return x;
	return lnk_2[x] = find_2(lnk_2[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	lnk[b] = a;
}

void unite_2(int a, int b) {
	a = find_2(a);
	b = find_2(b);
	if (a == b) return;
	if (sz_2[b] > sz_2[a]) swap(a, b);
	sz_2[a] += sz_2[b];
	lnk_2[b] = a;
}

bool mark(int u, int v, int e = -1) {
	//~ cout << "@ " << u << ' ' << v << '\n';
	if (u == v) return 1;
	for (auto x : adj_2[u]) if (x != e) {
		if (mark(x, v, u)) {
			marked[mp(u, x)] = 1;
			return 1;
		}
	}
	return 0;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		marked.clear();
		bad.clear();
		edges.clear();
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			lnk[i] = lnk_2[i] = i;
			sz[i] = sz_2[i] = 1;
			adj[i].clear();
			adj_2[i].clear();
		}
		for (int i = 1, u, v; i <= M; i++) {
			cin >> u >> v;
			edges.eb(u, v);
			adj[u].pb(v);
			adj[v].pb(u);
			if (find(u) != find(v)) {
				adj_2[u].pb(v);
				adj_2[v].pb(u);
				//~ cout << " + " << u << ' ' <<  v << '\n';
				unite(u, v);
			} else bad.eb(u, v);
		}
		//~ cout << '.' << endl;
		assert(bad.size() == M - (N - 1));
		if (bad.size() == 3) {
			//~ cout << bad[0].first << ' ' << bad[0].second << endl;
			mark(bad[0].first, bad[0].second);
			//~ cout << '.' << endl;
			bool inv = 0;
			for (auto [u, v] : bad) {
				if (find_2(u) == find_2(v)) inv = 1;
				else unite_2(u, v);
			}
			if (inv) {
				for (auto &[u, v] : bad)
					if (v == bad[0].first) swap(u, v);
				if (bad[1].first == bad[0].first) {}
				else swap(bad[1], bad[2]);
				assert(bad[2].first != bad[0].first);
				auto tmp_1 = bad[2], tmp_2 = mp(bad[2].second, bad[2].first);
				assert((tmp_1 == mp(bad[0].second, bad[1].second)) ^ (tmp_2 == mp(bad[0].second, bad[1].second)) == 1);
				bool found = 0;
				for (auto cand : adj[bad[0].first]) {
					if (marked[mp(bad[0].first, cand)] || marked[mp(cand, bad[0].first)]) {
						bad[0].second = cand;
						found = 1;
						break;
					}
				}
				assert(found);
			}
		}
		for (auto [u, v] : edges)
			if (find(bad.begin(), bad.end(), mp(u, v)) != bad.end() || find(bad.begin(), bad.end(), mp(v, u)) != bad.end()) cout << "1";
			else cout << "0";
		cout << '\n';
	}
}