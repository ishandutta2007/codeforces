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
	vector<vector<int>> graph(n);
	vector<int> deg_in(n);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int ind;
			cin >> ind;
			--ind;
			graph[ind].push_back(i);
			++deg_in[i];
		}
	}

	vector<int> order;
	queue<int> qu;
	for (int i = 0; i < n; ++i) {
		if (deg_in[i] == 0) {
			qu.push(i);
		}
	}

	while (szof(qu)) {
		int v = qu.front();
		qu.pop();
		order.push_back(v);
		for (int to : graph[v]) {
			--deg_in[to];
			if (deg_in[to] == 0) {
				qu.push(to);
			}
		}
	}

	if (szof(order) != n) {
		cout << "-1\n";
		return;
	}

	vector<int> dp(n);
	for (int i = n - 1; i >= 0; --i) {
		int v = order[i];
		dp[v] = 1;
		for (int to : graph[v]) {
			if (to < v) {
				dp[v] = max(dp[v], dp[to] + 1);
			} else {
				dp[v] = max(dp[v], dp[to]);
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << "\n";
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