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
// #  define cerr __get_ce
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

vector<int> real_arr;
int m;

pii ask(vector<int> positions) {
#ifdef TEST
	sort(positions.begin(), positions.end());
	assert(unique(positions.begin(), positions.end()) == positions.end());
	vector<pii> cur;
	for (int ind : positions) {
		cur.push_back({real_arr[ind], ind});
	}
	sort(cur.begin(), cur.end());
	return {cur[m].ss, cur[m].ff};
#else
	cout << "? ";
	for (int ind : positions) {
		cout << ind + 1 << " ";
	}
	cout << endl;
	int pos, val;
	cin >> pos >> val;
	--pos;
	return {pos, val};
#endif
}

void answer(int num) {
#ifdef TEST
	if (num != m) {
		cerr << num + 1 << " instead of " << m + 1 << endl;
	}
	assert(num == m);
#else
	cout << "! " << num + 1 << endl;
#endif
}

void solve(int n, int k) {
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	shuffle(order.begin(), order.end(), tw);
	vector<int> where(n);
	for (int i = 0; i < n; ++i) {
		where[order[i]] = i;
	}
	n = k + 1;
	order.resize(n);
	vector<int> arr(n, -1);
	vector<pii> ans;
	for (int i = 0; i < n; ++i) {
		vector<int> positions;
		for (int j = 0; j < n; ++j) {
			if (j != i) {
				positions.push_back(order[j]);
			}
		}
		auto [pos, val] = ask(positions);
		pos = where[pos];
		arr[pos] = val;
		ans.push_back({i, pos});
	}

	// sort(ans.begin(), ans.end(), [&](auto a, auto b) {
	// 	return arr[a.ss] > arr[b.ss];
	// });


	// cerr << "order:" << endl;
	// for (auto p : ans) {
	// 	cerr << p.ff << " " << p.ss << endl;
	// }

	// int val = -INF;
	// for (auto p : ans) {
	// 	if (arr[p.ff] == -1) {
	// 		arr[p.ff] = val;
	// 		++val;
	// 	} else {
	// 		val = arr[p.ff] + 1;
	// 	}
	// }

	int l = 0, r = k;
	for (int ind = 0; ind < n; ++ind) {
		int less = 0, more = 0;
		for (int i = 0; i < n; ++i) {
			if (i != ans[ind].ff) {
				if (arr[ans[i].ss] > arr[ans[ans[ind].ss].ss]) {
					less++;
				} else if (arr[ans[i].ss] < arr[ans[ans[ind].ss].ss]) {
					more++;
				}
			}
		}
		// cerr << ind << " " << less << " " << more << endl;
		l = max(l, less);
		r = min(r, k - more);
	}
	assert(l < r);
	answer(rnd(l, r - 1));
}

const int maxv = 1000000000;

void stress() {
	for (int i = 1; i <= 1000; ++i) {
		cerr << "test #" << i << endl;
		int n = rnd(2, 500);
		int k = rnd(1, n - 1);
		m = rnd(0, k - 1);
		set<int> tmp;
		while (szof(tmp) < n) {
			tmp.insert(rnd(0, maxv));
		}
		real_arr = vector<int>(tmp.begin(), tmp.end());
		shuffle(real_arr.begin(), real_arr.end(), tw);
		cerr << "k = " << k << endl;
		// for (int num : real_arr) {
		// 	cerr << num << " ";
		// }
		// cerr << endl;
		cerr << "m = " << m + 1 << endl;
		solve(n, k);
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

#ifdef TEST
	stress();
	return 0;
#endif

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		int n, k;
		cin >> n >> k;
		solve(n, k);
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}