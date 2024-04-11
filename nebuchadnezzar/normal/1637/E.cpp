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
	int n, m;
	cin >> n >> m;
	vector<int> arr;
	map<int, int> cnt;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
		cnt[num]++;
	}

	set<pii> forb;

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		forb.insert({x, y});
	}

	map<int, vector<int>> vals_by_cnt;
	for (auto p : cnt) {
		vals_by_cnt[p.ss].push_back(p.ff);
	}

	vector<int> cnt_arr;
	vector<vector<int>> vals_arr;
	for (auto& p : vals_by_cnt) {
		cnt_arr.push_back(p.ff);
		vals_arr.push_back(p.ss);
	}

	set<pair<ll, pair<pii, pii>>> have;

	auto calc = [&](int c1, int p1, int c2, int p2) {
		return (ll) (cnt_arr[c1] + cnt_arr[c2]) * (vals_arr[c1][p1] + vals_arr[c2][p2]);
	};

	for (int i = 0; i < szof(cnt_arr); ++i) {
		for (int j = i; j < szof(cnt_arr); ++j) {
			ll val = (ll) (cnt_arr[i] + cnt_arr[j]) * (vals_arr[i].back() + vals_arr[j].back());
			have.insert({val, {{i, szof(vals_arr[i]) - 1}, {j, szof(vals_arr[j]) - 1}}});
		}
	}

	while (true) {
		auto p = *--have.end();
		have.erase(--have.end());
		auto [c1, p1] = p.ss.ff;
		auto [c2, p2] = p.ss.ss;
		if (vals_arr[c1][p1] != vals_arr[c2][p2]) {
			int x = vals_arr[c1][p1];
			int y = vals_arr[c2][p2];
			if (x > y) {
				swap(x, y);
			}
			if (!forb.count({x, y})) {
				cout << p.ff << "\n";
				return;
			}
		}

		if (c1 < c2) {
			if (p1) {
				have.insert({calc(c1, p1 - 1, c2, p2), {{c1, p1 - 1}, {c2, p2}}});
			}
			if (p2) {
				have.insert({calc(c1, p1, c2, p2 - 1), {{c1, p1}, {c2, p2 - 1}}});
			}
		} else {
			if (p1) {
				have.insert({calc(c1, p1 - 1, c2, p2), {{c1, p1 - 1}, {c2, p2}}});
			}
			if (p1 < p2) {
				have.insert({calc(c1, p1, c2, p2 - 1), {{c1, p1}, {c2, p2 - 1}}});
			}
		}
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}