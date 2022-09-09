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
	vector<int> arr;
	set<int> odd, can_op;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
		if (1 <= i && i < n - 1) {
			if (num % 2) {
				odd.insert(i);
			}
			if (num >= 2) {
				can_op.insert(i);
			}
		}
	}

	ll ans = 0;

	while (szof(can_op)) {
		int i = *can_op.begin();
		can_op.erase(can_op.begin());
		int val = arr[i] / 2;
		ans += val;
		while (val) {
			bool fl = false;
			auto it = odd.upper_bound(i);
			if (it != odd.end()) {
				arr[*it]++;
				can_op.insert(*it);
				odd.erase(it);
				fl = true;
			}
			it = odd.lower_bound(i);
			if (it != odd.begin()) {
				--it;
				arr[*it]++;
				can_op.insert(*it);
				odd.erase(*it);
				fl = true;
			}

			if (fl) {
				--val;
			} else {
				break;
			}
		}

		arr[i] %= 2;
	}

	if (szof(odd)) {
		cout << "-1\n";
	} else {
		cout << ans << "\n";
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}