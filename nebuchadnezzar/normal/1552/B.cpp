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
	vector<vector<int>> inp(5, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			int num;
			cin >> num;
			inp[j][i] = num;
		}
	}
	vector<vector<int>> order;
	vector<vector<int>> where;
	for (int i = 0; i < 5; ++i) {
		order.push_back(vector<int>(n));
		iota(order[i].begin(), order[i].end(), 0);
		sort(order[i].begin(), order[i].end(), [&](int a, int b) {
			return inp[i][a] < inp[i][b];
		});
		// for (int ind : order[i]) {
		// 	cerr << ind << " ";
		// }
		// cerr << endl;
		where.push_back(vector<int>(n));
		for (int j = 0; j < n; ++j) {
			where[i][order[i][j]] = j;
		}
	}

	vector<vector<ull>> masks(5, vector<ull>(n));
	vector<int> left, new_left;
	for (int i = 0; i < n; ++i) {
		left.push_back(i);
	}

	for (int q = 0; q < n; q += 64) {
		for (int i = 0; i < 5; ++i) {
			ull cur = 0;
			for (int j = 0; j < n; ++j) {
				masks[i][j] = cur;
				if (q <= order[i][j] && order[i][j] < q + 64) {
					cur |= 1ull << (order[i][j] - q);
				}
			}
		}
		new_left.clear();
		for (int who : left) {
			int p0 = where[0][who];
			int p1 = where[1][who];
			int p2 = where[2][who];
			int p3 = where[3][who];
			int p4 = where[4][who];
			// cerr << "check " << who << " " << p0 << " " << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
			if ((masks[0][p0] & masks[1][p1] & (masks[2][p2] | masks[3][p3] | masks[4][p4])) || 
				(masks[0][p0] & masks[2][p2] & (masks[3][p3] | masks[4][p4])) ||
				(masks[0][p0] & masks[3][p3] & masks[4][p4]) ||
				(masks[1][p1] & masks[2][p2] & (masks[3][p3] | masks[4][p4])) ||
				(masks[1][p1] & masks[3][p3] & masks[4][p4]) ||
				(masks[2][p2] & masks[3][p3] & masks[4][p4])) {

			} else {
				new_left.push_back(who);
			}
		}

		swap(new_left, left);
	}

	if (szof(left)) {
		cout << left.front() + 1 << "\n";
	} else {
		cout << "-1\n";
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