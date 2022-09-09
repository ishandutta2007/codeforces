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

bool is_pal(string const& s) {
	auto tmp = s;
	reverse(tmp.begin(), tmp.end());
	return s == tmp;
}

void solve() {
	int n;
	cin >> n;
	vector<string> arr;
	set<string> have_rev;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		arr.push_back(s);
		auto tmp = s;
		reverse(tmp.begin(), tmp.end());
		have_rev.insert(tmp);
	}

	for (auto s : arr) {
		if (is_pal(s)) {
			cout << "YES\n";
			return;
		}
		if (have_rev.count(s)) {
			cout << "YES\n";
			return;
		}
	}

	set<string> have;
	for (int i = 0; i < n; ++i) {
		if (szof(arr[i]) == 3) {
			string tmp;
			tmp += arr[i][2];
			tmp += arr[i][1];
			if (have.count(tmp)) {
				cout << "YES\n";
				return;
			}
		} else if (szof(arr[i]) == 2) {
			have.insert(arr[i]);
		}
	}

	have.clear();

	for (int i = n - 1; i >= 0; --i) {
		if (szof(arr[i]) == 3) {
			string tmp;
			tmp += arr[i][1];
			tmp += arr[i][0];
			if (have.count(tmp)) {
				cout << "YES\n";
				return;
			}
		} else if (szof(arr[i]) == 2) {
			have.insert(arr[i]);
		}
	}

	cout << "NO\n";
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