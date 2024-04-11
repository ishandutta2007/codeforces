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
	int n;
	cin >> n;
	vector<int> perm;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		--num;
		perm.push_back(num);
	}

	vector<int> where(n);
	for (int i = 0; i < n; ++i) {
		where[perm[i]] = i;
	}

	ll invs = 0;

	ordered_set<int> have;

	int bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}

	vector<ll> segtree(bpv * 2);

	auto segtree_set = [&](int pos, ll val) {
		pos += bpv;
		segtree[pos] = val;
		pos /= 2;
		while (pos) {
			segtree[pos] = segtree[pos * 2] + segtree[pos * 2 + 1];
			pos /= 2;
		}
	};

	auto segtree_get = [&](int l, int r) {
		l += bpv; r += bpv;
		ll ret = 0;
		while (l < r) {
			if (l & 1) {
				ret += segtree[l++];
			}
			if (r & 1) {
				ret += segtree[--r];
			}
			l /= 2; r /= 2;
		}
		return ret;
	};

	for (int k = 0; k < n; ++k) {
		invs += k - have.order_of_key(where[k]);
		// cerr << "cur invs " << invs << endl;
		have.insert(where[k]);
		segtree_set(where[k], where[k]);

		int center = *have.find_by_order((k + 1) / 2);
		int to_left = (k + 1) / 2;
		int to_right = k - to_left;

		ll sum_to_left = segtree_get(0, center);
		ll sum_to_right = segtree_get(center + 1, n);

		ll res = sum_to_right - (ll) (center + 1 + center + to_right) * to_right / 2 + 
				(ll) (center - 1 + center - to_left) * to_left / 2 - sum_to_left + 
				invs;
		cout << res << " ";
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