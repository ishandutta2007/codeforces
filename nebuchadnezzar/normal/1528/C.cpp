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
	vector<vector<int>> tree1(n), tree2(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		tree1[p].push_back(i);
	}

	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		tree2[p].push_back(i);
	}

	vector<int> tin(n), tout(n);
	int tcnt = 0;

	function<void(int)> dfs_tree2 = [&](int v) {
		tin[v] = tcnt++;

		for (int to : tree2[v]) {
			dfs_tree2(to);
		}

		tout[v] = tcnt;
	};

	dfs_tree2(0);

	set<pii> segs;
	vector<pair<pii, bool>> events;

	auto add_node = [&](int v) {
		pii seg = {tin[v], tout[v]};
		auto it = segs.lower_bound(seg);
		if (it != segs.end() && it->ss <= seg.ss) {
			return;
		}
		if (it != segs.begin()) {
			--it;
			if (it->ss >= seg.ss) {
				events.push_back({*it, 0});
				segs.erase(it);
			}
		}
		events.push_back({seg, 1});
		segs.insert(seg);
	};

	int ans = 0;

	function<void(int)> dfs_tree1 = [&](int v) {
		int mem = szof(events);
		add_node(v);
		ans = max(ans, szof(segs));

		for (int to : tree1[v]) {
			dfs_tree1(to);
		}

		while (szof(events) > mem) {
			auto tmp = events.back();
			events.pop_back();
			if (tmp.ss == 0) {
				segs.insert(tmp.ff);
			} else {
				segs.erase(tmp.ff);
			}
		}
	};

	dfs_tree1(0);

	cout << ans << "\n";
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}