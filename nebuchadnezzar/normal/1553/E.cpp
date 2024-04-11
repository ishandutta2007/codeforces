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
	vector<int> perm;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		--num;
		perm.push_back(num);
	}

	map<int, int> shift_cnt;
	for (int i = 0; i < n; ++i) {
		int shift = (i - perm[i] + n) % n;
		shift_cnt[shift]++;
	}

	vector<int> tmp_perm(n);
	vector<int> used(n);
	vector<int> ans;
	for (auto p : shift_cnt) {
		if (p.ss >= n - m * 2) {
			// cerr << "check " << p.ff << endl;
			for (int i = 0; i < n; ++i) {
				tmp_perm[i] = perm[(i + p.ff + n) % n];
			}
			// for (int num : tmp_perm) {
			// 	cerr << num << " ";
			// }
			// cerr << endl;
			fill(used.begin(), used.end(), 0);
			int cycle = 0;
			for (int i = 0; i < n; ++i) {
				if (!used[i]) {
					++cycle;
					int v = i;
					while (!used[v]) {
						used[v] = true;
						v = tmp_perm[v];
					}
				}
			}
			// cerr << cycle << endl;
			if (cycle >= n - m) {
				ans.push_back(p.ff);
			}
		}
	}

	cout << szof(ans) << " ";
	sort(ans.begin(), ans.end());
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}