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
	int v, e, n, k;
	cin >> v >> e >> n >> k;
	vector<int> sts;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		sts.push_back(x);
	}

	vector<vector<int>> dist(v, vector<int>(v, INF));
	for (int i = 0; i < v; ++i) {
		dist[i][i] = 0;
	}
	for (int i = 0; i < e; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		--a; --b;
		dist[a][b] = min(dist[a][b], w);
		dist[b][a] = min(dist[b][a], w);
	}

	for (int i = 0; i < v; ++i) {
		for (int j = 0; j < v; ++j) {
			for (int q = 0; q < v; ++q) {
				dist[j][q] = min(dist[j][q], dist[j][i] + dist[i][q]);
			}
		}
	}

	const int MAXV = 20000 * 600 + 123;
	int l = -1, r = MAXV;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		// cerr << "mid " << mid << endl;
		vector<vector<int>> graph(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < v; ++j) {
				if (dist[sts[i]][j] <= mid) {
					// cerr << i << " " << j << endl;
					graph[i].push_back(j);
				}
			}
		}
		vector<int> lr(n, -1);
		vector<int> rl(v, -1);
		vector<bool> used(n);

		function<bool(int)> dfs = [&](int cur) {
			used[cur] = true;
			for (int to : graph[cur]) {
				if (rl[to] == -1 || (!used[rl[to]] && dfs(rl[to]))) {
					rl[to] = cur;
					lr[cur] = to;
					return true;
				}
			}
			return false;
		};
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			fill(used.begin(), used.end(), false);
			cnt += dfs(i);
			if (cnt == k) {
				break;
			}
		}
		// cerr << mid << " " << cnt << endl;
		if (cnt == k) {
			r = mid;
		} else {
			l = mid;
		}
	}

	if (r == MAXV) {
		cout << "-1\n";
		return;
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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}