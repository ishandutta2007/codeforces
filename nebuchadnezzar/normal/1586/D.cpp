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

int ask(vector<int> arr) {
	cout << "? ";
	for (int num : arr) {
		cout << num << " ";
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	int cnt = 0;
	for (int i = n - 1; i >= 0; --i) {
		vector<int> arr(n, 2);
		arr[i] = 1;
		int pos = ask(arr);
		--pos;
		if (pos != -1 && pos != i) {
			graph[pos].push_back(i);
		}

		arr = vector<int>(n, 1);
		arr[i] = 2;
		pos = ask(arr);
		--pos;
		if (pos != -1 && pos != i) {
			graph[i].push_back(pos);
		}
	}

	vector<int> deg_in(n);
	for (int i = 0; i < n; ++i) {
		for (int to : graph[i]) {
			// cerr << i << " -> " << to << endl;
			++deg_in[to];
		}
	}

	int v = min_element(deg_in.begin(), deg_in.end()) - deg_in.begin();
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[v] = i + 1;
		if (i < n - 1) {
			v = graph[v][0];
		}
	}

	cout << "! ";
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