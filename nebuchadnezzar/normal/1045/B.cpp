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
	int n, m;
	cin >> n >> m;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	vector<int> seq;
	for (int i = 0; i < n; ++i) {
		int next = (i + 1) % n;
		seq.push_back((arr[next] - arr[i] + m) % m);
	}
	vector<int> rev_seq = seq;
	reverse(rev_seq.begin(), rev_seq.end());
	vector<int> res = rev_seq;
	res.insert(res.end(), seq.begin(), seq.end());
	res.insert(res.end(), seq.begin(), seq.end());
	vector<int> z(n * 3);
	vector<int> ans;
	int l = 0, r = 0;
	for (int i = 1; i < n * 3; ++i) {
		if (i < r) {
			z[i] = min(r - i, z[i - l]);
		}
		while (i + z[i] < n * 3 && res[z[i]] == res[i + z[i]]) {
			++z[i];
		}

		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}

		if (n <= i && i < n * 2 && z[i] >= n) {
			ans.push_back((arr[0] + arr[i - n]) % m);
		}
	}
	sort(ans.begin(), ans.end());
	cout << szof(ans) << "\n";
	for (int num : ans) {
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