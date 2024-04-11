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
	vector<int> need(n), add(n);
	for (int i = 1; i < n; ++i) {
		cin >> need[i];
		++need[i];
	}
	for (int i = 1; i < n; ++i) {
		cin >> add[i];
	}

	vector<vector<pii>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back({b, i * 2});
		graph[b].push_back({a, i * 2 + 1});
	}

	vector<int> visited(n);
	vector<int> used(m * 2);
	auto check = [&](ll st) {
		// cerr << "check " << st << endl;
		fill(visited.begin(), visited.end(), 0);
		visited[0] = 1;

		vector<int> path;
		function<bool(int, int, ll)> dfs = [&](int v, int e, ll bal) {
			bal += add[v];
			used[e] = 1;
			path.push_back(v);

			for (auto to : graph[v]) {
				if ((to.ss ^ e) == 1) {
					continue;
				}
				if (visited[to.ff]) {
					return true;
				}

				if (used[to.ss] == 1) {
					return true;
				}
			}

			for (auto to : graph[v]) {
				if ((to.ss ^ e) == 1) {
					continue;
				}
				if (!used[to.ss] && bal >= need[to.ff]) {
					if (dfs(to.ff, to.ss, bal)) {
						return true;
					}
				}
			}

			path.pop_back();
			used[e] = 2;

			return false;
		};

		while (*min_element(visited.begin(), visited.end()) == 0) {
			fill(used.begin(), used.end(), 0);
			bool found = false;
			for (int i = 0; i < n; ++i) {
				if (visited[i]) {
					for (auto to : graph[i]) {
						if (!visited[to.ff] && !used[to.ss] && st >= need[to.ff]) {
							path.clear();
							if (dfs(to.ff, to.ss, st)) {
								found = true;
								break;
							}
						}
					}
					if (found) {
						break;
					}
				}
			}

			if (!found) {
				// cerr << "didn't find" << endl;
				return false;
			}

			// cerr << "found" << endl;
			for (int v : path) {
				// cerr << v + 1 << " ";
				if (!visited[v]) {
					st += add[v];
				}
				visited[v] = true;
			}
			// cerr << endl;
		}

		return true;
	};

	int l = 0, r = INF;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}

	cout << r << "\n";
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