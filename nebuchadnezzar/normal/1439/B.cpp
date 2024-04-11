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
	int n, m, k;
	cin >> n >> m >> k;
	vector<gp_hash_table<int, bool>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].insert({b, false});
		graph[b].insert({a, false});
	}

	auto check_clique = [&](int v) {
		if ((ll) k * (k - 1) / 2 > m) {
			return false;
		}
		for (auto to : graph[v]) {
			if (szof(graph[to.ff]) < k - 1) {
				return false;
			}
		}
		vector<pair<int, bool>> nodes(graph[v].begin(), graph[v].end());
		for (int i = 0; i < szof(nodes); ++i) {
			for (int j = i + 1; j < szof(nodes); ++j) {
				if (graph[nodes[i].ff].find(nodes[j].ff) == graph[nodes[i].ff].end()) {
					return false;
				}
			}
		}
		return true;
	};

	vector<bool> used(n);
	queue<int> qu;
	for (int i = 0; i < n; ++i) {
		if (szof(graph[i]) < k - 1) {
			qu.push(i);
			used[i] = true;
		} else if (szof(graph[i]) == k - 1) {
			if (check_clique(i)) {
				cout << "2\n";
				cout << i + 1 << " ";
				for (auto to : graph[i]) {
					cout << to.ff + 1 << " ";
				}
				cout << "\n";
				return;
			}
			qu.push(i);
			used[i] = true;
			for (auto to : graph[i]) {
				if (szof(graph[to.ff]) == k - 1 && !used[to.ff]) {
					qu.push(to.ff);
					used[to.ff] = true;
				}
			}
		}
	}

	vector<bool> erased(n);

	while (szof(qu)) {
		int v = qu.front();
		qu.pop();
		erased[v] = true;
		for (auto qwe : graph[v]) {
			int to = qwe.ff;
			graph[to].erase(v);
			if (szof(graph[to]) < k - 1) {
				if (!used[to]) {
					qu.push(to);
				}
			} else if (szof(graph[to]) == k - 1) {
				if (!used[to]) {
					if (check_clique(to)) {
						cout << "2\n";
						cout << to + 1 << " ";
						for (auto to2 : graph[to]) {
							cout << to2.ff + 1 << " ";
						}
						cout << "\n";
						return;
					}
					qu.push(to);
					used[to] = true;
					for (auto to2 : graph[to]) {
						if (szof(graph[to2.ff]) == k - 1 && !used[to2.ff]) {
							qu.push(to2.ff);
							used[to2.ff] = true;
						}
					}
				}
			}
		}
	}

	vector<int> outp;
	for (int i = 0; i < n; ++i) {
		if (!erased[i]) {
			outp.push_back(i);
		}
	}

	if (szof(outp)) {
		cout << "1 " << szof(outp) << "\n";
		for (int v : outp) {
			cout << v + 1 << " ";
		}
		cout << "\n";
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