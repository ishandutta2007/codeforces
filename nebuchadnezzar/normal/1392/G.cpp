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
	string init, target;
	cin >> init >> target;
	vector<pii> ops;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		ops.push_back({a, b});
	}
	vector<vector<int>> order(1, vector<int>(k));
	iota(order[0].begin(), order[0].end(), 0);
	for (int i = 0; i < n; ++i) {
		order.push_back(order.back());
		swap(order[i + 1][ops[i].ff], order[i + 1][ops[i].ss]);
	}

	vector<int> where(k), what(k);
	iota(where.begin(), where.end(), 0);
	iota(what.begin(), what.end(), 0);
	for (int i = n - m - 1; i >= 0; --i) {
		int a = what[ops[i].ff];
		int b = what[ops[i].ss];
		swap(what[ops[i].ff], what[ops[i].ss]);
		swap(where[a], where[b]);
	}

	int best = INF;
	pii ans = {0, 0};

	vector<pii> min_dist(1 << k, {INF, -1});
	queue<int> qu;
	auto add_val = [&](int val, int ind) {
		if (min_dist[val].ff == 0) {
			return;
		}
		min_dist[val] = {0, ind};
		qu.push(val);
		while (szof(qu)) {
			int num = qu.front();
			qu.pop();
			for (int i = 0; i < k; ++i) {
				if (min_dist[num ^ (1 << i)].ff > min_dist[num].ff + 1) {
					min_dist[num ^ (1 << i)] = {min_dist[num].ff + 1, ind};
					qu.push(num ^ (1 << i));
				}
			}
		}
	};
	
	for (int i = n; i >= m; --i) {
		int val = 0;
		for (int j = 0; j < k; ++j) {
			val |= (target[j] - '0') << order[i][j];
		}
		add_val(val, i);

		int pref_val = 0;
		for (int j = 0; j < k; ++j) {
			pref_val |= (init[j] - '0') << where[j];
		}

		pii tmp = min_dist[pref_val];
		if (tmp.ff < best) {
			best = tmp.ff;
			ans = {i - m, tmp.ss};
		}

		if (i - m - 1 >= 0) {
			swap(where[ops[i - m - 1].ff], where[ops[i - m - 1].ss]);
			int p1 = where[ops[i - m - 1].ff];
			int p2 = where[ops[i - m - 1].ss];
			swap(what[p1], what[p2]);
		}
	}

	cout << k - best << "\n";
	cout << ans.ff + 1 << " " << ans.ss << "\n";
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