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
	int w, h;
	cin >> w >> h;
	set<int> ans;

	auto check = [&](int l) {
		for (int shift = 0; shift <= 1; ++shift) {
			int c = shift;
			bool ok = true;
			for (int side : {w, h, w, h}) {
				int left = side - c;
				int q = left / l;
				left -= q * l;
				if (left == 0) {
					c = 1;
				} else if (left == 1) {
					c = 0;
				} else {
					ok = false;
					break;
				}
			}
			if (ok && c == shift) {
				ans.insert(l);
			}
		}
	};

	for (int x : {w - 2, w - 1, w}) {
		if (x <= 0) {
			continue;
		}
		for (int l = 1; l * l <= x; ++l) {
			if (x % l == 0) {
				check(l);
				check(x / l);
			}
		}
	}

	cout << szof(ans) << " ";
	for (int l : ans) {
		cout << l << " ";
	}
	cout << "\n";
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