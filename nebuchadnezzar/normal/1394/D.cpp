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
typedef pair<ll, ll> pll;
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
	vector<int> weight(n);
	for (int i = 0; i < n; ++i) {
		cin >> weight[i];
	}

	vector<int> height(n);
	map<int, vector<int>> have_heights;
	for (int i = 0; i < n; ++i) {
		cin >> height[i];
		have_heights[height[i]].push_back(i);
	}

	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	ll ans = 0;
	vector<pii> lg(n);
	for (int i = 0; i < n; ++i) {
		int less = 0, greater = 0;
		for (int to : graph[i]) {
			if (height[to] < height[i]) {
				++less;
			} else if (height[to] > height[i]) {
				++greater;
			}
		}
		// ans += (ll) min(less, greater) * weight[i];
		lg[i] = {less, greater};
	}

	vector<bool> used(n);

	function<pll(int, int)> dfs = [&](int v, int p) {
		used[v] = true;
		vector<ll> vals;
		ll cur_val = 0;
		for (int to : graph[v]) {
			if (!used[to] && height[to] == height[v]) {
				auto tmp = dfs(to, v);
				cur_val += tmp.ff;
				vals.push_back(tmp.ss - tmp.ff);
			}
		}
		sort(vals.begin(), vals.end());
		pll ret = {INFL, INFL};
		for (int i = 0; i <= szof(vals); ++i) {
			if (v == p) {
				auto tmp = lg[v];
				tmp.ff += i;
				tmp.ss += szof(vals) - i;
				ret.ff = min(ret.ff, (ll) max(tmp.ff, tmp.ss) * weight[v] + cur_val);
			} else {
				auto tmp = lg[v];
				tmp.ff += i;
				tmp.ss += szof(vals) - i;
				tmp.ff++;
				ret.ff = min(ret.ff, (ll) max(tmp.ff, tmp.ss) * weight[v] + cur_val);
				--tmp.ff;
				++tmp.ss;
				ret.ss = min(ret.ss, (ll) max(tmp.ff, tmp.ss) * weight[v] + cur_val);
			}
			if (i < szof(vals)) {
				cur_val += vals[i];
			}
		}
		// cerr << v + 1 << " " << ret.ff << " " << ret.ss << endl;
		return ret;
	};

	for (auto& p : have_heights) {
		// cerr << p.ff << endl;
		for (int v : p.ss) {
			if (!used[v]) {
				pll tmp = dfs(v, v);
				ans += tmp.ff;
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