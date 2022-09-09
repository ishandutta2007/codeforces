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

const int MOD = 1'000'000'007;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

void solve() {
	int n, l, m;
	cin >> n >> l >> m;
	vector<vector<int>> cost(3, vector<int>(n));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> cost[i][j];
		}
	}

	vector<int> cnt(m);
	for (int i = 0; i < n; ++i) {
		cnt[cost[0][i] % m]++;
	}

	vector<int> go(m);
	for (int i = 0; i < n; ++i) {
		go[cost[1][i] % m]++;
	}

	vector<int> next(m);

	l -= 2;

	while (l) {
		if (l & 1) {
			fill(next.begin(), next.end(), 0);
			for (int x = 0; x < m; ++x) {
				for (int y = 0; y < m; ++y) {
					add(next[(x + y) % m], mult(cnt[x], go[y]));
				}
			}
			swap(next, cnt);
		}
		fill(next.begin(), next.end(), 0);
		for (int x = 0; x < m; ++x) {
			for (int y = 0; y < m; ++y) {
				add(next[(x + y) % m], mult(go[x], go[y]));
			}
		}
		swap(next, go);
		l /= 2;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int need = -cost[2][i] - cost[1][i];
		need = ((need % m) + m) % m;
		add(ans, cnt[need]);
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