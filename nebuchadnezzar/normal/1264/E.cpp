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

uniform_real_distribution<double> double_distr;

double rnd() {
	return double_distr(tw);
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> res(n, vector<int>(n));
	vector<vector<bool>> inp(n, vector<bool>(n));
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		res[u][v] = 1;
		res[v][u] = 0;
		inp[u][v] = inp[v][u] = true;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (!inp[i][j]) {
				res[i][j] = rnd(0, 1);
				res[j][i] = !res[i][j];
			}
		}
	}
	vector<int> deg(n);
	int val = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			deg[i] += res[i][j];
		}
		val += deg[i] * deg[i];
	}
	double t = 1000;
	int best = val;
	auto ans = res;
	while (clock() < 0.8 * CLOCKS_PER_SEC) {
		int a, b;
		while (true) {
			a = rnd(0, n - 1);
			b = rnd(0, n - 1);
			if (a < b && !inp[a][b]) {
				break;
			}
			if (clock() > 0.8 * CLOCKS_PER_SEC) {
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						cout << ans[i][j];
					}
					cout << "\n";
				}
				return;
			}
		}
		int mem = val;
		val -= deg[a] * deg[a] + deg[b] * deg[b];
		deg[a] -= res[a][b];
		deg[b] -= res[b][a];
		res[a][b] ^= 1;
		res[b][a] ^= 1;
		deg[a] += res[a][b];
		deg[b] += res[b][a];
		val += deg[a] * deg[a] + deg[b] * deg[b];
		if (val < mem || rnd() < exp((mem - val) / t)) {
			// ok
			if (best > val) {
				best = val;
				ans = res;
			}
		} else {
			val -= deg[a] * deg[a] + deg[b] * deg[b];
			deg[a] -= res[a][b];
			deg[b] -= res[b][a];
			res[a][b] ^= 1;
			res[b][a] ^= 1;
			deg[a] += res[a][b];
			deg[b] += res[b][a];
			val += deg[a] * deg[a] + deg[b] * deg[b];
		}
		t *= 0.9999;
	}

	// cerr << t << endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ans[i][j];
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