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
	vector<int> arrh;
	for (int i = 0; i < n; ++i) {
		int h;
		cin >> h;
		arrh.push_back(h);
	}

	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int root = max_element(arrh.begin(), arrh.end()) - arrh.begin();
	vector<ll> dp(n);
	vector<int> max_subtree(n);
	function<void(int, int)> dfs = [&](int v, int p) {
		for (auto to : graph[v]) {
			if (to != p) {
				dfs(to, v);
				max_subtree[v] = max(max_subtree[v], max_subtree[to]);
				dp[v] += dp[to];
			}
		}

		int val = max(0, arrh[v] - max_subtree[v]);
		dp[v] += val;
		max_subtree[v] += val;
	};

	dfs(root, -1);

	if (szof(graph[root]) == 1) {
		cout << dp[root] + arrh[root] << "\n";
		return;
	}

	ll ans = INFL;
	multiset<int> max_subtrees;
	ll sum_dp = 0;
	for (int to : graph[root]) {
		max_subtrees.insert(max_subtree[to]);
		sum_dp += dp[to];
	}

	for (int to : graph[root]) {
		max_subtrees.erase(max_subtrees.find(max_subtree[to]));
		ll val = sum_dp + max(0, arrh[root] - *--max_subtrees.end()) + max(0, arrh[root] - max_subtree[to]);
		ans = min(ans, val);
		max_subtrees.insert(max_subtree[to]);
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