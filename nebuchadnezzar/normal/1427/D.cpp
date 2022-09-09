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
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		--num;
		arr.push_back(num);
	}

	vector<vector<int>> outp;
	for (int i = 0; i < n - 1; ++i) {
		vector<int> cur;
		if (i % 2 == 1) {
			for (int j = 0; j < i; ++j) {
				cur.push_back(1);
			}
			cur.push_back(find(arr.begin(), arr.end(), i) - arr.begin() + 1 - i);
			cur.push_back(n - accumulate(cur.begin(), cur.end(), 0));
		} else {
			cur.push_back(find(arr.begin(), arr.end(), i) - arr.begin());
			cur.push_back(n - i - cur[0]);
			for (int j = 0; j < i; ++j) {
				cur.push_back(1);
			}
		}

		vector<int> tmp;
		for (int num : cur) {
			if (num) {
				tmp.push_back(num);
			}
		}

		if (szof(tmp) > 1) {
			outp.push_back(tmp);
		}
		vector<int> next;
		int cnt = 0;
		for (int num : tmp) {
			next.insert(next.begin(), arr.begin() + cnt, arr.begin() + cnt + num);
			cnt += num;
		}

		swap(next, arr);
	}


	if (n % 2 == 1) {
		if (n > 1) {
			outp.push_back(vector<int>(n, 1));
		}
		reverse(arr.begin(), arr.end());
	}

	assert(is_sorted(arr.begin(), arr.end()));

	cout << szof(outp) << "\n";
	for (auto& v : outp) {
		cout << szof(v) << " ";
		for (int num : v) {
			cout << num << " ";
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