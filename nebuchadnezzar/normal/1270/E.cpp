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

ll sqr(ll num) {
	return num * num;
}

void solve() {
	int n;
	cin >> n;
	vector<pii> points;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		points.push_back({x, y});
	}

	vector<int> color(n);
	while (true) {
		bool has[2] = {false, false};
		for (int i = 0; i < n; ++i) {
			has[(points[i].ff + points[i].ss) & 1] = true;
		}
		if (has[0] && has[1]) {
			for (int i = 0; i < n; ++i) {
				color[i] = (points[i].ff + points[i].ss) & 1;
			}
			break;
		}
		if (!has[0]) {
			for (auto& p : points) {
				--p.ff;
			}
		}

		for (auto& p : points) {
			auto [x, y] = p;
			p = {(x + y) / 2, x - (x + y) / 2};
		}
	}

	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (color[i]) {
			ans.push_back(i);
		}
	}

	cout << szof(ans) << "\n";
	for (int ind : ans) {
		cout << ind + 1 << " ";
	}
	cout << "\n";

	// set<ll> dists1, dists2;

	// for (int i = 0; i < n; ++i) {
	// 	for (int j = i + 1; j < n; ++j) {
	// 		ll d = sqr(points[i].ff - points[j].ff) + sqr(points[i].ss - points[j].ss);
	// 		if (color[i] == color[j]) {
	// 			dists1.insert(d);
	// 		} else {
	// 			dists2.insert(d);
	// 		}
	// 	}
	// }

	// for (ll d : dists1) {
	// 	assert(!dists2.count(d));
	// }
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