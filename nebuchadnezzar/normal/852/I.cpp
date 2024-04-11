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
	vector<int> type(n);
	for (int i = 0; i < n; ++i) {
		cin >> type[i];
	}
	vector<int> val(n);
	for (int i = 0; i < n; ++i) {
		cin >> val[i];
	}
	vector<int> unique_vals = val;
	sort(unique_vals.begin(), unique_vals.end());
	unique_vals.resize(unique(unique_vals.begin(), unique_vals.end()) - unique_vals.begin());

	for (int i = 0; i < n; ++i) {
		val[i] = lower_bound(unique_vals.begin(), unique_vals.end(), val[i]) - unique_vals.begin();
	}

	vector<vector<int>> graph(n);

	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int bp = 1;
	while (1 << bp <= n) {
		++bp;
	}

	vector<int> tin(n), tout(n);
	vector<vector<int>> binup(bp, vector<int>(n));
	vector<int> depth(n);
	int tcnt = 0;
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
		// cerr << "get lca " << a + 1 << " " << b + 1 << endl;
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

	auto get_dist = [&](int a, int b) {
		int lca = get_lca(a, b);
		return depth[a] + depth[b] - 2 * depth[lca];
	};


	vector<pair<pii, int>> reqs;

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if (tin[a] > tin[b]) {
			swap(a, b);
		}
		reqs.push_back({{a, b}, i});
	}

	const int SQRT = max((int) sqrt(n), 5);

	sort(reqs.begin(), reqs.end(), [&](auto& a, auto& b) {
		if (tin[a.ff.ff] / SQRT != tin[b.ff.ff] / SQRT) {
			return tin[a.ff.ff] / SQRT < tin[b.ff.ff] / SQRT;
		}
		return tin[a.ff.ss] < tin[b.ff.ss];
	});

	vector<vector<int>> cnt(2, vector<int>(szof(unique_vals)));
	ll res = 0;
	vector<ll> ans(q);
	deque<int> path;

	auto rem_node = [&](int v) {
		// cerr << "rem " << v + 1 << endl;
		res -= (ll) cnt[0][val[v]] * cnt[1][val[v]];
		cnt[type[v]][val[v]]--;
		res += (ll) cnt[0][val[v]] * cnt[1][val[v]];
	};

	auto add_node = [&](int v) {
		// cerr << "add " << v + 1 << endl;
		res -= (ll) cnt[0][val[v]] * cnt[1][val[v]];
		cnt[type[v]][val[v]]++;
		res += (ll) cnt[0][val[v]] * cnt[1][val[v]];
	};

	for (auto& p : reqs) {
		int lca = get_lca(p.ff.ff, p.ff.ss);
		// cerr << "lca " << lca + 1 << endl;
		auto on_path = [&](int v) {
			return is_parent(lca, v) && (is_parent(v, p.ff.ff) || is_parent(v, p.ff.ss));
		};
		while (szof(path) && !on_path(path.front())) {
			rem_node(path.front());
			path.pop_front();
		}
		while (szof(path) && !on_path(path.back())) {
			rem_node(path.back());
			path.pop_back();
		}
		if (!szof(path)) {
			int v = p.ff.ff;
			while (v != lca) {
				path.push_back(v);
				add_node(v);
				v = binup[0][v];
			}
			vector<int> tmp;
			v = p.ff.ss;
			while (true) {
				tmp.push_back(v);
				add_node(v);
				if (v == lca) {
					break;
				}
				v = binup[0][v];
			}
			reverse(tmp.begin(), tmp.end());
			for (int u : tmp) {
				path.push_back(u);
			}
		} else {
			if (get_dist(path.front(), p.ff.ff) > get_dist(path.back(), p.ff.ff)) {
				swap(p.ff.ff, p.ff.ss);
			}
			// cerr << path.front() + 1 << " " << path.back() + 1 << endl;
			vector<int> tmp;
			int v = p.ff.ff;
			while (v != path.front() && v != lca) {
				tmp.push_back(v);
				add_node(v);
				v = binup[0][v];
			}
			if (v != path.front()) {
				v = binup[0][path.front()];
				while (true) {
					add_node(v);
					path.push_front(v);
					if (v == lca) {
						break;
					}
					v = binup[0][v];
				}
			}
			reverse(tmp.begin(), tmp.end());
			for (int u : tmp) {
				path.push_front(u);
			}
			tmp.clear();

			v = p.ff.ss;
			while (v != path.back() && v != lca) {
				tmp.push_back(v);
				add_node(v);
				v = binup[0][v];
			}
			if (v != path.back()) {
				v = binup[0][path.back()];
				while (true) {
					add_node(v);
					path.push_back(v);
					if (v == lca) {
						break;
					}
					v = binup[0][v];
				}
			}
			reverse(tmp.begin(), tmp.end());
			for (int u : tmp) {
				path.push_back(u);
			}
		}
		// cerr << "req " << p.ss << endl;
		ans[p.ss] = res;
	}

	for (auto num : ans) {
		cout << num << "\n";
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