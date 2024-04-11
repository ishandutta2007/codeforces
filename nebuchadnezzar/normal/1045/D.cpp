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
	vector<double> arrp;
	for (int i = 0; i < n; ++i) {
		double p;
		cin >> p;
		arrp.push_back(p);
	}
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		// --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int> parent(n, -1);
	function<void(int, int)> dfs = [&](int v, int p) {
		parent[v] = p;
		for (int to : graph[v]) {
			if (to != p) {
				dfs(to, v);
			}
		}
	};

	dfs(0, -1);

	int q;
	cin >> q;
	double sum = 0;
	vector<double> sum_children(n);
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			sum += 1 - arrp[i];
		} else {
			sum += (1 - arrp[i]) * arrp[parent[i]];
		}

		if (parent[i] != -1) {
			sum_children[parent[i]] += 1 - arrp[i];
		}
	}

	for (int i = 0; i < q; ++i) {
		int v;
		double p;
		cin >> v >> p;
		// --v;
		if (v == 0) {
			sum -= 1 - arrp[v];
		} else {
			sum -= (1 - arrp[v]) * arrp[parent[v]];
			sum_children[parent[v]] -= 1 - arrp[v];
		}
		sum -= sum_children[v] * arrp[v];
		arrp[v] = p;
		
		if (v == 0) {
			sum += 1 - arrp[v];
		} else {
			sum += (1 - arrp[v]) * arrp[parent[v]];
			sum_children[parent[v]] += 1 - arrp[v];
		}
		sum += sum_children[v] * arrp[v];

		cout << sum << "\n";
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