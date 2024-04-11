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

int const INF = (int)1e9 + 1e5;
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
	vector<vector<pii>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
	}

	vector<int> dist(n);
	vector<bool> used(n);
	for (int i = 0; i < n; ++i) {
		// cerr << "i: " << i << endl;
		fill(dist.begin(), dist.end(), INF);
		fill(used.begin(), used.end(), 0);
		dist[i] = 0;
		for (int j = 0; j < n; ++j) {
			int v = -1;
			for (int k = 0; k < n; ++k) {
				if (!used[k] && (v == -1 || dist[k] < dist[v])) {
					v = k;
				}
			}

			used[v] = true;


			int curt = dist[v];
			// cerr << v << " " << curt << endl;
			for (auto e : graph[v]) {
				// cerr << v << " " << e.ff << " " << e.ss << endl;
				int to = (e.ff + curt) % n;
				int val = curt + e.ss;
				if (to == i) {
					to = (to + 1) % n;
					++val;
				}
				// cerr << "go " << to << " " << val << endl;
				dist[to] = min(dist[to], val);
			}

			if (v != i) {
				int to = (v + 1) % n;
				int val = dist[v] + 1;
				if (to == i) {
					to = (to + 1) % n;
					++val;
				}
				dist[to] = min(dist[to], val);
			}
		}

		for (int j = 0; j < n; ++j) {
			cout << dist[j] << " ";
		}
		cout << "\n";
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