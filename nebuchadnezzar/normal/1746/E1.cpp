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

vector<int> solv_tree = {1, 1, 2, 1, 2, 1, 1};
vector<int> finishes = {0, 7, 7, 7, 6, 7, 5, 3, 6, 6, 5, 3, 5, 5, 2, 3};

void solve() {
	int n;
	cin >> n;
	vector<int> left(n);
	iota(left.begin(), left.end(), 0);
	while (szof(left) > 2) {
		int q = szof(left);
		int x = q * 0.37;
		x = max(x, 1);
		if (x * 2 >= q) {
			x = (q - 1) / 2;
		}
		int y = q - x * 2;
		vector<vector<int>> parts;
		parts.push_back(vector<int>(left.begin(), left.begin() + y));
		parts.push_back(vector<int>(left.begin() + y, left.begin() + y + x));
		parts.push_back(vector<int>(left.begin() + y + x, left.end()));

		int v = 1;
		while (true) {
			if (__builtin_popcount(finishes[v]) <= 2) {
				break;
			}
			vector<int> to_ask;
			for (int i = 0; i < 3; ++i) {
				if (solv_tree[v - 1] & (1 << i)) {
					to_ask.insert(to_ask.end(), parts[i].begin(), parts[i].end());
				}
			}
			cout << "? " << szof(to_ask) << " ";
			for (int num : to_ask) {
				cout << num + 1 << " ";
			}
			cout << endl;
			string res;
			cin >> res;
			if (res == "NO") {
				v *= 2;
			} else {
				v = v * 2 + 1;
			}
		}

		left.clear();
		for (int i = 0; i < 3; ++i) {
			if (finishes[v] & (1 << i)) {
				left.insert(left.end(), parts[i].begin(), parts[i].end());
			}
		}
	}

	for (int num : left) {
		cout << "! " << num + 1 << endl;
		string res;
		cin >> res;
		if (res == ":)") {
			return;
		}
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