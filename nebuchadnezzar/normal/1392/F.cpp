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
	vector<ll> arr;
	ll s = 0;
	for (int i = 0; i < n; ++i) {
		ll num;
		cin >> num;
		s += num;
		arr.push_back(num);
	}
	if (n == 1) {
		for (ll num : arr) {
			cout << num << " ";
		}
		cout << "\n";
		return;
	}
	if (n == 2) {
		ll tmp = arr[1] - arr[0];
		arr[0] += tmp / 2;
		arr[1] -= tmp / 2;
		for (ll num : arr) {
			cout << num << " ";
		}
		cout << "\n";
		return;
	}
	vector<ll> diffs;
	for (int i = 0; i < n - 1; ++i) {
		diffs.push_back(arr[i + 1] - arr[i]);
	}

	diffs[1] += diffs[0] / 2;
	diffs[0] %= 2;
	vector<int> zeroes;
	if (diffs[0] == 0) {
		zeroes.push_back(0);
	}
	for (int i = 1; i < szof(diffs); ++i) {
		// cerr << i << " " << diffs[i] << endl;
		ll add = 0;
		while (szof(zeroes) > 1 && diffs[i] > 1) {
			if (zeroes.back() == i - 1) {
				diffs[i] -= 2;
				add++;
				zeroes.pop_back();
				continue;
			}
			ll tmp = diffs[i] / 2;
			ll actions = i - zeroes.back() - 1;
			ll q = min(tmp, actions);
			diffs[i] -= q;
			add += q;
			zeroes.back() += q;
		}
		while (diffs[i] > 1) {
			if (!szof(zeroes)) {
				int cycle = i + 1;
				int per_cycle = cycle + 1;
				ll tmp = diffs[i] / 2 / per_cycle;
				if (tmp) {
					diffs[i] -= tmp * per_cycle;
					add += tmp * cycle;
					// cerr << "here " << diffs[i] << " " << szof(zeroes) << endl;
					continue;
				}
			}
			if (szof(zeroes)) {
				if (zeroes.back() == i - 1) {
					diffs[i] -= 2;
					add++;
					zeroes.pop_back();
					continue;
				}
				ll tmp = diffs[i] / 2;
				ll actions = i - zeroes.back() - 1;
				ll q = min(tmp, actions);
				diffs[i] -= q;
				add += q;
				zeroes.back() += q;
			} else {
				zeroes.push_back(0);
				diffs[i]--;
				add++;
			}
		}

		if (i < szof(diffs) - 1) {
			diffs[i + 1] += add;
		}

		if (diffs[i] == 0) {
			zeroes.push_back(i);
		}
		// cerr << "after " << i << endl;
		// cerr << "add " << add << endl;
		// cerr << "zeroes: " << endl;
		// for (int pos : zeroes) {
		// 	cerr << pos << " ";
		// }
		// cerr << endl;
	}

	fill(diffs.begin(), diffs.end(), 1);
	for (int pos : zeroes) {
		diffs[pos] = 0;
	}

	// for (int num : diffs) {
	// 	cerr << num << " ";
	// }
	// cerr << endl;

	ll tot = 0;
	ll pref = 0;
	for (ll num : diffs) {
		pref += num;
		tot += pref;
	}

	assert((s - tot) % n == 0);
	vector<ll> outp = {(s - tot) / n};
	for (ll num : diffs) {
		outp.push_back(outp.back() + num);
	}

	for (ll num : outp) {
		cout << num << " ";
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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}