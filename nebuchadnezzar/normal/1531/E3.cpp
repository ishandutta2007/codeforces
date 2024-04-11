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
	string s;
	cin >> s;
	int l = 0, r = 100005;
	while (r - l > 1) {
		// cerr << l << " " << r << endl;
		int n = (l + r) / 2;
		int cnt = 0;
		vector<vector<int>> graph(n);
		vector<int> arr(n);
		iota(arr.begin(), arr.end(), 0);
		vector<int> tmp(n);

		function<bool(int, int)> rec = [&](int l, int r) {
			if (r - l <= 1) {
				return true;
			}
			int m = (l + r) / 2;
			if (!rec(l, m)) {
				return false;
			}
			if (!rec(m, r)) {
				return false;
			}
			
			int i = l, j = m, k = l;
			while (i < m && j < r) {
				if (cnt == szof(s)) {
					return false;
				}
				if (s[cnt++] == '0') {
					graph[arr[i]].push_back(arr[j]);
					tmp[k++] = arr[i++];
				} else {
					graph[arr[j]].push_back(arr[i]);
					tmp[k++] = arr[j++];
				}
			}
		    
		    while (i < m) {
		    	tmp[k++] = arr[i++];
		    }
		    while (j < r) {
		    	tmp[k++] = arr[j++];
		    }

		    for (int p = l; p < r; ++p) {
		    	arr[p] = tmp[p];
		    }

		    return true;
		};

		if (!rec(0, n)) {
			r = n;
			continue;
		}

		if (cnt < szof(s)) {
			l = n;
			continue;
		}

		vector<int> order;
		vector<bool> used(n);
		function<void(int)> dfs = [&](int v) {
			used[v] = true;
			for (int to : graph[v]) {
				if (!used[to]) {
					dfs(to);
				}
			}
			order.push_back(v);
		};

		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				dfs(i);
			}
		}

		reverse(order.begin(), order.end());

		vector<int> perm(n);
		for (int i = 0; i < n; ++i) {
			perm[order[i]] = i;
		}
		cout << n << "\n";
		for (int v : perm) {
			cout << v + 1 << " ";
		}
		cout << "\n";
		break;
	}
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