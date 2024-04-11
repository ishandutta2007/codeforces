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
	map<int, int> inds;
	inds[-1] = 0;
	auto get_ind = [&](int num) {
		if (!inds.count(num)) {
			int tmp = szof(inds);
			inds[num] = tmp;
		}
		return inds[num];
	};
	int n, m;
	cin >> n >> m;
	vector<pair<int, vector<int>>> arr(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int num;
			cin >> num;
			arr[i].ss.push_back(get_ind(num));
		}
		arr[i].ss.resize(5);
		cin >> arr[i].ff;
	}

	sort(arr.begin(), arr.end());

	// cerr << clock() * 1000 / CLOCKS_PER_SEC << endl;

	vector<ull> mask_by_val(szof(inds));
	vector<int> left(n), next_left;
	iota(left.begin(), left.end(), 0);
	ll ans = INFL;
	vector<bool> used(n);

	for (int i = 0; i < n; i += 64) {
		int from = i, to = min(n, from + 64);
		ull tot_mask = 0;
		for (int j = from; j < to; ++j) {
			tot_mask |= 1ull << (j - from);
			for (int q = 0; q < m; ++q) {
				mask_by_val[arr[j].ss[q]] |= 1ull << (j - from);
			}
		}

		// cerr << i << endl;
		// next_left.clear();
		// for (int ind : left) {
		for (int ind = from; ind < n; ++ind) {
			if (used[ind]) {
				continue;
			}
			// cerr << ind << endl;
			ull cmask = mask_by_val[arr[ind].ss[0]] | mask_by_val[arr[ind].ss[1]] | mask_by_val[arr[ind].ss[2]] | mask_by_val[arr[ind].ss[3]] | mask_by_val[arr[ind].ss[4]];
			// for (int q = 0; q < m; ++q) {
			// 	cmask |= mask_by_val[arr[ind].ss[q]];
			// }
			if (cmask != tot_mask) {
				used[ind] = true;
				// cerr << cmask << " " << tot_mask << endl;
				for (int b = 0; ; ++b) {
					if (!((cmask >> b) & 1)) {
						ans = min(ans, (ll) arr[ind].ff + arr[from + b].ff);
						break;
					}
				}
			}/* else {
				next_left.push_back(ind);
			}*/
		}
		// swap(left, next_left);

		for (int j = from; j < to; ++j) {
			for (int q = 0; q < m; ++q) {
				mask_by_val[arr[j].ss[q]] = 0;
			}
		}
	}

	if (ans == INFL) {
		cout << "-1\n";
	} else {
		cout << ans << "\n";
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