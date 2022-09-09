// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
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
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

ll calc_no2(vector<ll> const& g) {
	int n = szof(g);
	ll ret = 0;
	int part1 = n / 2;
	int part2 = n - part1;
	vector<vector<ll>> dp(part2 + 1, vector<ll>(1 << part2));
	for (int mask = 0; mask < 1 << part1; ++mask) {
		bool ok = true;
		int forb = 0;
		for (int i = 0; i < part1; ++i) {
			if ((mask & (1 << i)) && (mask & g[i])) {
				ok = false;
				break;
			}
			if (mask & (1 << i)) {
				forb |= g[i] >> part1;
			}
		}
		if (ok) {
			// cerr << mask << " " << forb << endl;
			dp[0][(~forb) & ((1 << part2) - 1)]++;
		}
	}
	for (int mask = (1 << part2) - 1; mask >= 0; --mask) {
		ll sum = 0;
		for (int i = 0; i < part2; ++i) {
			sum += dp[i][mask];
			if (mask & (1 << i)) {
				dp[i + 1][mask ^ (1 << i)] += sum;
			}
		}
		sum += dp[part2][mask];
		// cerr << mask << " " << sum << endl;
		bool ok = true;
		for (int i = 0; i < part2; ++i) {
			if ((mask & (1 << i)) && (mask & (g[i + part1] >> part1))) {
				ok = false;
				break;
			}
		}
		if (ok) {
			// cerr << mask << endl;
			ret += sum;
		}
	}
	return ret;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<ll> matr_graph(n);
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		matr_graph[a] |= 1ll << b;
		matr_graph[b] |= 1ll << a;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	ll ans = 1ll << n;
	ans -= calc_no2(matr_graph) * 2;
	
	vector<bool> used(n);
	vector<int> color(n);
	function<void(int, int)> dfs = [&](int v, int col) {
		color[v] = col;
		used[v] = true;
		for (int to : graph[v]) {
			if (!used[to]) {
				dfs(to, 1 - col);
			}
		}
	};

	int cnt_comps = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			++cnt_comps;
			dfs(i, 0);
		}
	}

	ans -= 1ll << cnt_comps;

	int cnt_no_edges = 0;
	for (int i = 0; i < n; ++i) {
		if (!szof(graph[i])) {
			++cnt_no_edges;
		}
	}

	ans += (1ll << cnt_no_edges) * 2;

	bool is_bipartite = true;
	for (int i = 0; i < n; ++i) {
		for (int to : graph[i]) {
			if (color[to] == color[i]) {
				is_bipartite = false;
				break;
			}
		}
		if (!is_bipartite) {
			break;
		}
	}

	if (is_bipartite) {
		ans += 1ll << cnt_comps;
	}

	if (m == 0) {
		ans -= 1ll << n;
	}

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