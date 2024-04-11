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

int calc(vector<int> arr) {
	set<int> have(arr.begin(), arr.end());
	int ans = 0;
	for (int i = 0; i < szof(arr); ++i) {
		for (int j = i + 1; j < szof(arr); ++j) {
			ans += have.count(arr[i] + arr[j]);
		}
	}
	return ans;
}

void solve() {
	int n, m;
	cin >> n >> m;
	if ((n - 1) * (n - 1) / 4 < m) {
		cout << "-1\n";
		return;
	}

	int l = 0, r = n;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		vector<int> tmp(mid);
		iota(tmp.begin(), tmp.end(), 1);
		if ((mid - 1) * (mid - 1) / 4 < m) {
			l = mid;
		} else {
			r = mid;
		}
	}

	int sz = r;
	// cerr << sz << endl;
	vector<int> ans(sz);
	iota(ans.begin(), ans.end(), 1);

	const int MAXV = 1'000'000'000;
	l = ans.back() - 1, r = ans.back() + n * 2 + 2;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		ans.back() = mid;
		int val = (sz - 2) * (sz - 2) / 4;
		for (int i = 0; i < sz - 1 && i + 1 < mid - i - 1; ++i) {
			if (mid - i - 1 <= sz - 1) {
				++val;
			}
		}
		if (val == m) {
			while (szof(ans) < n) {
				ans.push_back(MAXV + (-n + szof(ans) + 1) * (n * 2 + 123));
			}
			for (int num : ans) {
				cout << num << " ";
			}
			cout << "\n";
			cout.flush();
			// assert(calc(ans) == m);
			return;
		}
		if (val > m) {
			l = mid;
		} else {
			r = mid;
		}
	}
	assert(false);
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