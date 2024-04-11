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
	int bal = 0;
	for (char c : s) {
		if (c == ')') {
			++bal;
		}
	}
	int center = -1;
	for (int i = 0; i < szof(s); ++i) {
		if (bal == 0) {
			center = i;
			break;
		}
		if (s[i] == '(') {
			--bal;
		} else {
			--bal;
		}
		if (bal == 0) {
			center = i + 1;
		}
	}
	assert(center != -1);
	vector<int> ans;
	for (int i = 0; i < szof(s); ++i) {
		if (i < center) {
			if (s[i] == '(') {
				ans.push_back(i);
			}
		} else {
			if (s[i] == ')') {
				ans.push_back(i);
			}
		}
	}
	if (!szof(ans)) {
		cout << "0\n";
	} else {
		cout << "1\n";
		cout << szof(ans) << "\n";
		for (int ind : ans) {
			cout << ind + 1 << " ";
		}
		cout << "\n";
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