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

const int MAXV = 3e5 + 5;

void solve() {
	int n;
	cin >> n;
	vector<int> arr;
	int bpv = 1;
	while (bpv < MAXV) {
		bpv *= 2;
	}
	vector<pair<ll, int>> segtree(bpv * 2);

	auto segtree_add = [&](int pos) {
		int val = pos;
		pos += bpv;
		segtree[pos] = {val, 1};
		pos /= 2;
		while (pos) {
			segtree[pos].ff = segtree[pos * 2].ff + segtree[pos * 2 + 1].ff;
			segtree[pos].ss = segtree[pos * 2].ss + segtree[pos * 2 + 1].ss;
			pos /= 2;
		}
	};

	auto segtree_get = [&](int l, int r) {
		pair<ll, int> ret = {0, 0};
		l += bpv;
		r += bpv;
		while (r - l) {
			if (l & 1) {
				ret.ff += segtree[l].ff;
				ret.ss += segtree[l].ss;
				l++;
			}
			if (r & 1) {
				--r;
				ret.ff += segtree[r].ff;
				ret.ss += segtree[r].ss;
			}
			l /= 2; r /= 2;
		}
		return ret;
	};

	ll sum = 0;
	set<int> have;

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		have.insert(num);
		arr.push_back(num);
		for (int j = 0; j < MAXV; j += num) {
			auto tmp = segtree_get(j, min(j + num, bpv));
			sum += tmp.ff;
			sum -= (ll) tmp.ss * j;
		}
		// cerr << sum << endl;
		sum += (ll) segtree_get(num, bpv).ss * num;
		int to = num;
		for (int k = 1; to > k * 10; ++k) {
			int from = num / (k + 1) + 1;
			auto tmp = segtree_get(from, to);
			sum += (ll) num * tmp.ss - tmp.ff * k;
			to = from;
		}

		for (int x : have) {
			if (x >= to) {
				break;
			}
			sum += num % x;
		}

		cout << sum << " ";
		segtree_add(num);
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