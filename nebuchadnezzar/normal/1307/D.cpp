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
	vector<int> fields;
	for (int i = 0; i < k; ++i) {
		int v;
		cin >> v;
		--v;
		fields.push_back(v);
	}
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	auto calc_dists = [&](int s) {
		vector<int> dist(n, INF);
		dist[s] = 0;
		queue<int> qu;
		qu.push(s);
		while (szof(qu)) {
			int v = qu.front();
			qu.pop();
			for (int to : graph[v]) {
				if (dist[to] > dist[v] + 1) {
					dist[to] = dist[v] + 1;
					qu.push(to);
				}
			}
		}
		return dist;
	};

	vector<int> dist1 = calc_dists(0);
	vector<int> distn = calc_dists(n - 1);

	vector<pii> arr;
	for (int v : fields) {
		arr.push_back({dist1[v] - distn[v], distn[v]});
	}

	sort(arr.begin(), arr.end());
	int maxy = -INF;
	int ans = 0;
	for (int i = szof(arr) - 1; i >= 0; --i) {
		ans = max(ans, maxy + arr[i].ss + arr[i].ff + 1);

		maxy = max(maxy, arr[i].ss);
	}

	ans = min(ans, dist1[n - 1]);

	cout << ans << "\n";
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