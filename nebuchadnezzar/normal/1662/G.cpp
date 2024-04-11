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

const int MAXN = 1e6 + 5;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		graph[p].push_back(i);
		graph[i].push_back(p);
	}

	vector<int> subtr(n), largest(n);
	function<void(int, int)> dfs0 = [&](int v, int p) {
		subtr[v] = 1;
		for (int to : graph[v]) {
			if (to != p) {
				dfs0(to, v);
				subtr[v] += subtr[to];
				largest[v] = max(largest[v], subtr[to]);
			}
		}
	};

	dfs0(0, 0);

	vector<pii> all_nodes;
	for (int i = 0; i < n; ++i) {
		largest[i] = max(largest[i], n - subtr[i]);
		all_nodes.push_back({largest[i], i});
	}
	sort(all_nodes.begin(), all_nodes.end());

	function<pair<int, ll>(int, int)> dfs = [&](int v, int p) {
		int sz = 1;
		ll ret = 1;
		for (int to : graph[v]) {
			if (to != p) {
				auto tmp = dfs(to, v);
				sz += tmp.ff;
				ret += tmp.ss;
				ret += tmp.ff;
			}
		}
		return pair<int, ll>(sz, ret);
	};

	all_nodes.resize(min(n, 2));

	ll ans = 0;

	for (auto [tmp, i] : all_nodes) {
		map<int, int> cnt;
		ll cur = 0;
		for (int to : graph[i]) {
			auto tmp = dfs(to, i);
			cnt[tmp.ff]++;
			cur += tmp.ss;
		}

		vector<int> arr;
		for (auto p : cnt) {
			int left = p.ss;
			int x = 1;
			while (left) {
				int cur = min(left, x);
				left -= cur;
				arr.push_back(p.ff * cur);
				x *= 2;
			}
		}

		bitset<MAXN> bs;
		bs[0] = 1;
		for (int num : arr) {
			bs |= bs << num;
		}
		for (int i = 0; i < n; ++i) {
			if (bs[i]) {
				ans = max(ans, cur + (ll) (i + 1) * (n - i));
			}
		}
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