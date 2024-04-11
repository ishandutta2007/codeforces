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
	vector<int> order;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		--num;
		order.push_back(num);
	}

	vector<int> ans(n, -1);
	vector<int> cnt(24);

	for (int i = 1; i <= 24; ++i) {
		vector<int> cur(n, 0);
		vector<pii> edges;
		for (int j = 0; j < n; ++j) {
			if (ans[order[j]] == -1) {
				int pos = order[j] - 1;
				while (pos >= 0 && cur[pos] != -1) {
					--pos;
				}
				if (pos >= 0) {
					edges.push_back({pos, order[j]});
				}
				pos = order[j] + 1;
				while (pos < n && cur[pos] != -1) {
					++pos;
				}
				if (pos < n) {
					edges.push_back({order[j], pos});
				}
				cur[order[j]] = -1;
			}
		}

		vector<vector<int>> graph(n);
		for (auto e : edges) {
			// cerr << e.ff << " " << e.ss << endl;
			graph[e.ff].push_back(e.ss);
			graph[e.ss].push_back(e.ff);
		}

		vector<int> nodes_order(n);
		iota(nodes_order.begin(), nodes_order.end(), 0);

		sort(nodes_order.begin(), nodes_order.end(), [&](int a, int b) {
			return szof(graph[a]) < szof(graph[b]);
		});

		for (int v : nodes_order) {
			if (ans[v] == -1) {
				bool ok = true;
				for (int to : graph[v]) {
					if (ans[to] == i) {
						ok = false;
						break;
					}
				}
				if (ok) {
					ans[v] = i;
				}
			}
		}

		// for (int num : ans) {
		// 	cerr << num << " ";
		// }
		// cerr << '\n';
	}

	// assert(*min_element(ans.begin(), ans.end()) != -1);
	for (int num : ans) {
		cout << num << " ";
	}
	cout << "\n";
	// cout.flush();

	// vector<int> cur(n, 0);
	// for (int i = 0; i < n; ++i) {
	// 	cur[order[i]] = ans[order[i]];

	// 	vector<int> arr;
	// 	for (int num : cur) {
	// 		if (num) {
	// 			arr.push_back(num);
	// 		}
	// 	}

	// 	for (int num : arr) {
	// 		cerr << num << " ";
	// 	}
	// 	cerr << endl;

	// 	for (int j = 0; j < szof(arr); ++j) {
	// 		set<int> have_unique;
	// 		set<int> have_not_unique;
	// 		for (int k = j; k < szof(arr); ++k) {
	// 			if (have_unique.count(arr[k])) {
	// 				have_unique.erase(arr[k]);
	// 				have_not_unique.insert(arr[k]);
	// 			} else if (!have_not_unique.count(arr[k])) {
	// 				have_unique.insert(arr[k]);
	// 			}
	// 			assert(szof(have_unique));
	// 		}
	// 	}
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}