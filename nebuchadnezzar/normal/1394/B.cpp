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

int get_ind(int a, int b) {
	return a * (a - 1) / 2 + b;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pii>> graph(n), rgraph(n);
	vector<int> weight;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		graph[u].push_back({v, i});
		rgraph[v].push_back({u, i});
		weight.push_back(i);
	}

	vector<int> ind(m);

	for (int i = 0; i < n; ++i) {
		sort(graph[i].begin(), graph[i].end(), [&](auto& a, auto& b) {
			return weight[a.ss] < weight[b.ss];
		});

		for (int j = 0; j < szof(graph[i]); ++j) {
			ind[graph[i][j].ss] = j;
		}
	}

	int tot = (k + 1) * k / 2;

	vector<ll> forb(tot);
	vector<bool> have(tot);
	vector<int> list_have;

	for (int i = 0; i < n; ++i) {
		fill(have.begin(), have.end(), 0);
		for (pii from : rgraph[i]) {
			int a = szof(graph[from.ff]);
			int b = ind[from.ss];
			int cur = get_ind(a, b);
			if (have[cur]) {
				forb[cur] |= 1ll << cur;
			}
			have[cur] = true;
		}
		list_have.clear();
		for (int j = 0; j < tot; ++j) {
			if (have[j]) {
				list_have.push_back(j);
			}
		}
		for (int j = 0; j < szof(list_have); ++j) {
			for (int q = j + 1; q < szof(list_have); ++q) {
				forb[list_have[j]] |= 1ll << list_have[q];
				forb[list_have[q]] |= 1ll << list_have[j];
			}
		}
	}

	ll mask = 0;

	int ans = 0;

	function<void(int)> rec = [&](int pos) {
		if (pos == k) {
			ans += 1;
			return;
		}
		for (int i = 0; i <= pos; ++i) {
			int cur = get_ind(pos + 1, i);
			mask ^= 1ll << cur;
			if (!(forb[cur] & mask)) {
				rec(pos + 1);
			}
			mask ^= 1ll << cur;
		}
	};

	rec(0);

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