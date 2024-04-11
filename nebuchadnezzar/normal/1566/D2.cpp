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
	map<int, vector<int>> by_val;
	for (int i = 0; i < n * m; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
		by_val[num].push_back(i);
	}

	vector<pii> where(n * m);

	{
		int x = 0, y = 0;
		for (auto& p : by_val) {
			int pos = 0;
			while (pos < szof(p.ss)) {
				int q = min(szof(p.ss) - pos, m - y);
				for (int j = 0; j < q; ++j) {
					where[p.ss[pos + q - 1 - j]] = {x, y};
					++y;
				}
				pos += q;
				if (y == m) {
					++x;
					y = 0;
				}
			}
		}
	}


	int ans = 0;
	vector<vector<int>> used(n, vector<int>(m));
	for (int i = 0; i < n * m; ++i) {
		auto [x, y] = where[i];
		ans += accumulate(used[x].begin(), used[x].begin() + y, 0);
		used[x][y] = 1;
	}

	cout << ans << "\n";
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