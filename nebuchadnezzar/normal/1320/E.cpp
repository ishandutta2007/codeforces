// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int bp = 1;

	while (1 << bp < n) {
		++bp;
	}

	vector<int> depth(n), tin(n), tout(n);
	int tcnt = 0;
	vector<vector<int>> binup(bp, vector<int>(n));

	function<void(int, int, int)> dfs = [&](int v, int p, int d) {
		tin[v] = tcnt++;
		depth[v] = d;
		binup[0][v] = p;
		for (int i = 1; i < bp; ++i) {
			binup[i][v] = binup[i - 1][binup[i - 1][v]];
		}

		for (int to : graph[v]) {
			if (to != p) {
				dfs(to, v, d + 1);
			}
		}

		tout[v] = tcnt;
	};

	dfs(0, 0, 0);

	auto get_lca = [&](int a, int b) {
		if (depth[a] > depth[b]) {
			swap(a, b);
		}
		for (int i = bp - 1; i >= 0; --i) {
			if (depth[a] <= depth[b] - (1 << i)) {
				b = binup[i][b];
			}
		}
		if (a == b) {
			return a;
		}
		for (int i = bp - 1; i >= 0; --i) {
			if (binup[i][a] != binup[i][b]) {
				a = binup[i][a];
				b = binup[i][b];
			}
		}
		return binup[0][a];
	};

	auto is_parent = [&](int p, int v) {
		return tin[p] <= tin[v] && tout[v] <= tout[p];
	};

	int q;
	cin >> q;
	for (int tn = 0; tn < q; ++tn) {
		int k, m;
		cin >> k >> m;
		vector<pii> viruses;
		vector<int> nodes;
		for (int i = 0; i < k; ++i) {
			int v, s;
			cin >> v >> s;
			--v;
			viruses.push_back({v, s});
			nodes.push_back(v);
		}

		auto choose = [&](int a, int la, int b, int lb) {
			if (a == -1 || lb == 0) {
				return pii(b, lb);
			}
			if (b == -1 || la == 0) {
				return pii(a, la);
			}

			int turna = (la - 1) / viruses[a].ss;
			int turnb = (lb - 1) / viruses[b].ss;
			if (turna < turnb || (turna == turnb && a < b)) {
				return pii(a, la);
			}
			return pii(b, lb);
		};

		vector<int> cities;
		for (int i = 0; i < m; ++i) {
			int v;
			cin >> v;
			--v;
			cities.push_back(v);
			nodes.push_back(v);
		}
		sort(nodes.begin(), nodes.end(), [&](int a, int b) {
			return tin[a] < tin[b];
		});
		int mem = szof(nodes);
		for (int i = 0; i < mem - 1; ++i) {
			nodes.push_back(get_lca(nodes[i], nodes[i + 1]));
		}
		sort(nodes.begin(), nodes.end());
		nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
		auto sorted_nodes = nodes;
		sort(nodes.begin(), nodes.end(), [&](int a, int b) {
			return tin[a] < tin[b];
		});
		vector<vector<pii>> cur_graph(szof(nodes));
		vector<pii> st;
		for (int v : nodes) {
			int ind = lower_bound(sorted_nodes.begin(), sorted_nodes.end(), v) - sorted_nodes.begin();
			while (szof(st) && !is_parent(st.back().ff, v)) {
				st.pop_back();
			}
			if (szof(st)) {
				int d = depth[v] - depth[st.back().ff];
				cur_graph[st.back().ss].push_back({ind, d});
			}
			st.push_back({v, ind});
		}

		vector<pii> dp(szof(nodes), {-1, INF});

		vector<int> virus_here(szof(nodes), -1);

		for (int i = 0; i < k; ++i) {
			int ind = lower_bound(sorted_nodes.begin(), sorted_nodes.end(), viruses[i].ff) - sorted_nodes.begin();
			dp[ind] = {i, 0};
			virus_here[ind] = i;
		}

		function<void(int)> dfs1 = [&](int v) {
			for (auto to : cur_graph[v]) {
				dfs1(to.ff);
				dp[v] = choose(dp[v].ff, dp[v].ss, dp[to.ff].ff, dp[to.ff].ss + to.ss);
			}
		};
		dfs1(st.front().ss);

		function<void(int, pii const&)> dfs2 = [&](int v, pii from_up) {
			dp[v] = choose(dp[v].ff, dp[v].ss, from_up.ff, from_up.ss);
			if (virus_here[v] != -1) {
				from_up = {virus_here[v], 0};
			}
			vector<pii> pref = {from_up}, suff = {from_up};
			for (int i = 0; i < szof(cur_graph[v]); ++i) {
				auto to = cur_graph[v][i];
				pref.push_back(choose(pref.back().ff, pref.back().ss, dp[to.ff].ff, dp[to.ff].ss + to.ss));
				to = cur_graph[v][szof(cur_graph[v]) - 1 - i];
				suff.push_back(choose(suff.back().ff, suff.back().ss, dp[to.ff].ff, dp[to.ff].ss + to.ss));
			}
			for (int i = 0; i < szof(cur_graph[v]); ++i) {
				auto& to = cur_graph[v][i];
				auto cur = choose(pref[i].ff, pref[i].ss, suff[szof(cur_graph[v]) - i - 1].ff, suff[szof(cur_graph[v]) - i - 1].ss);
				cur.ss += to.ss;
				dfs2(to.ff, cur);
			}
		};
		dfs2(st.front().ss, {-1, INF});

		for (int i = 0; i < m; ++i) {
			int ind = lower_bound(sorted_nodes.begin(), sorted_nodes.end(), cities[i]) - sorted_nodes.begin();
			cout << dp[ind].ff + 1 << " ";
		}
		cout << "\n";
	}
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}