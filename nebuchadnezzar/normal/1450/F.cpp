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
		arr.push_back(num);
	}

	map<int, int> cnt;
	int tot = 2;
	cnt[arr[0]]++;
	cnt[arr[n - 1]]++;
	vector<bool> used(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		if (arr[i] == arr[i + 1]) {
			used[i] = true;
			cnt[arr[i]]++;
			cnt[arr[i + 1]]++;
			tot += 2;
		}
	}
	int bad = -1, sz_bad = -1;
	for (auto p : cnt) {
		if (p.ss > tot / 2 + 1) {
			bad = p.ff, sz_bad = p.ss;
			break;
		}
	}

	if (bad == -1) {
		cout << tot / 2 - 1 << "\n";
		return;
	}

	// cerr << bad << " " << sz_bad << endl;

	for (int i = 0; i < n - 1; ++i) {
		if (!used[i] && arr[i] != bad && arr[i + 1] != bad) {
			// cerr << i << endl;
			used[i] = true;
			tot += 2;
			if (sz_bad <= tot / 2 + 1) {
				break;
			}
		}
	}


	if (sz_bad <= tot / 2 + 1) {
		cout << tot / 2 - 1 << "\n";
		return;
	}

	for (int i = 0; i < n - 1; ++i) {
		if (!used[i] && (arr[i] != bad || arr[i + 1] != bad)) {
			used[i] = true;
			tot += 2;
			sz_bad += 1;
			if (sz_bad <= tot / 2 + 1) {
				break;
			}
		}
	}

	if (sz_bad <= tot / 2 + 1) {
		cout << tot / 2 - 1 << "\n";
	} else {
		cout << "-1\n";
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