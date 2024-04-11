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
typedef pair<ll, ll> pll;

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
	int from = 0;
	vector<pii> outp;

	function<void(int, int)> rec_do = [&](int l, int r) {
		if (l + 1 == r) {
			return;
		}
		int mid = (l + r) / 2;
		rec_do(l, mid);
		rec_do(mid, r);
		for (int i = 0; i < mid - l; ++i) {
			outp.push_back({l + i, mid + i});
		}
	};

	vector<vector<int>> parts;
	for (int i = 0; i < 20; ++i) {
		if (n & (1 << i)) {
			rec_do(from, from + (1 << i));
			vector<int> cur(1 << i);
			iota(cur.begin(), cur.end(), from);
			parts.push_back(cur);
			from += (1 << i);
		}
	}

	while (szof(parts) > 2) {
		if (szof(parts[0]) == szof(parts[1])) {
			for (int i = 0; i < szof(parts[0]); ++i) {
				outp.push_back({parts[0][i], parts[1][i]});
			}
			parts[1].insert(parts[1].end(), parts[0].begin(), parts[0].end());
			parts.erase(parts.begin());
		} else {
			int sz = szof(parts[0]);
			for (int i = 0; i < sz; ++i) {
				outp.push_back({parts[0][i], parts.back().back()});
				parts[0].push_back(parts.back().back());
				parts.back().pop_back();
			}
		}
	}

	cout << szof(outp) << "\n";
	for (auto p : outp) {
		cout << p.ff + 1 << " " << p.ss + 1 << "\n";
	}

	// map<pll, ll> dict;
	// ll cnt_dict = n;
	// auto f = [&](ll a, ll b) {
	// 	if (!dict.count({a, b})) {
	// 		dict[{a, b}] = cnt_dict++;
	// 	}
	// 	return dict[{a, b}];
	// };

	// vector<ll> arr(n);
	// iota(arr.begin(), arr.end(), 0);
	// for (auto p : outp) {
	// 	ll val = f(arr[p.ff], arr[p.ss]);
	// 	arr[p.ff] = arr[p.ss] = val;
	// }

	// assert(szof(set<ll>(arr.begin(), arr.end())) <= 2);
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