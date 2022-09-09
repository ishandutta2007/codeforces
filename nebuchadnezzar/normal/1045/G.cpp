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
	int n, k;
	cin >> n >> k;
	map<int, vector<int>> by_iq;
	vector<tuple<int, int, int>> robots;
	for (int i = 0; i < n; ++i) {
		int x, r, q;
		cin >> x >> r >> q;
		robots.push_back({x, r, q});
		by_iq[q].push_back(i);
	}

	ll ans = 0;

	for (auto& p : by_iq) {
		vector<tuple<int, int, int>> events;
		for (int ind : p.ss) {
			auto [x, r, q] = robots[ind];
			events.push_back({x - r, 0, ind});
			events.push_back({x + r, 2, ind});
		}

		for (int iq = p.ff; iq <= p.ff + k; ++iq) {
			if (!by_iq.count(iq)) {
				continue;
			}
			for (int ind : by_iq[iq]) {
				auto [x, r, q] = robots[ind];
				events.push_back({x, 1, ind});
			}
		}
		sort(events.begin(), events.end());
		ordered_set<pii> have;
		// cerr << p.ff << endl;
		for (auto [cx, t, ind] : events) {
			// cerr << cx << " " << t << " " << ind << endl;
			auto [x, r, q] = robots[ind];
			if (t == 0) {
				have.insert({x, ind});
			} else if (t == 2) {
				have.erase({x, ind});
			} else {
				int lg = have.order_of_key({x - r, -1});
				int rg;
				if (q == p.ff) {
					rg = have.order_of_key({x, ind});
				} else {
					rg = have.order_of_key({x + r + 1, -1});
				}
				// cerr << lg << " " << rg << endl;
				// for (auto p : have) {
				// 	cerr << p.ff << " " << p.ss << endl;
				// }
				ans += rg - lg;
			}
		}
	}

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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}