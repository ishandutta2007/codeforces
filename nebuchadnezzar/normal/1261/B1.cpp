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

#include "ext/pb_ds/assoc_container.hpp"
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
template <typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
	vector<int> arr;
	vector<int> vals;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
		vals.push_back(num);
	}
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for (int& num : arr) {
		num = lower_bound(vals.begin(), vals.end(), num) - vals.begin();
	}
	int m;
	cin >> m;
	vector<int> suff(szof(vals) + 1);
	for (int num : arr) {
		suff[num]++;
	}
	for (int i = szof(vals) - 2; i >= 0; --i) {
		suff[i] += suff[i + 1];
	}
	vector<vector<pii>> here(n);
	for (int i = 0; i < m; ++i) {
		int k, pos;
		cin >> k >> pos;
		--pos;
		here[k - 1].push_back({pos, i});
	}
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int a, int b) {
		if (arr[a] != arr[b]) {
			return arr[a] > arr[b];
		}
		return a < b;
	});
	vector<int> ans(m);
	ordered_set<int> have;
	for (int i = 0; i < n; ++i) {
		have.insert(order[i]);
		for (auto [pos, ind] : here[i]) {
			ans[ind] = *have.find_by_order(pos);
		}
	}

	for (int num : ans) {
		cout << vals[arr[num]] << "\n";
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