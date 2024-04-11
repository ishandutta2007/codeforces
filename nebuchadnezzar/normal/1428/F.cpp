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
	string s;
	cin >> s;

	vector<int> to_left(n), to_right(n);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			to_left[i] = 0;
		} else {
			to_left[i] = 1 + (i == 0 ? 0 : to_left[i - 1]);
		}
	}


	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == '0') {
			to_right[i] = 0;
		} else {
			to_right[i] = 1 + (i == n - 1 ? 0 : to_right[i + 1]);
		}
	}

	const int bp = 20;
	vector<vector<int>> sparse_left = {to_left}, sparse_right = {to_right};
	for (int i = 1; i < bp; ++i) {
		sparse_left.push_back({});
		// sparse_left.back().reserve(n - (1 << i));
		sparse_right.push_back({});
		// sparse_right.back().reserve(n - (1 << i));
		for (int j = 0; j + (1 << i) <= n; ++j) {
			sparse_left.back().push_back(max(sparse_left[i - 1][j], sparse_left[i - 1][j + (1 << (i - 1))]));
			sparse_right.back().push_back(max(sparse_right[i - 1][j], sparse_right[i - 1][j + (1 << (i - 1))]));
		}
	}

	vector<int> max_bp(n + 5);
	for (int i = 2; i < szof(max_bp); ++i) {
		max_bp[i] = max_bp[i / 2] + 1;
	}

	auto get_max = [&](vector<vector<int>> const& sparse, int l, int r) {
		if (r == l) {
			return -INF;
		}
		int q = max_bp[r - l];
		return max(sparse[q][l], sparse[q][r - (1 << q)]);
	};

	auto find_most_left = [&](int from, int val) {
		int l = from, r = n + 1;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (get_max(sparse_left, from, mid) >= val) {
				r = mid;
			} else {
				l = mid;
			}
		}
		return l;
	};

	auto find_most_right = [&](int to, int val) {
		int l = -1, r = to;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (get_max(sparse_right, mid, to) >= val) {
				l = mid;
			} else {
				r = mid;
			}
		}
		return l;
	};

	ll ans = 0;
	int from = 0;
	vector<pii> segs;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			if (from < i) {
				segs.push_back({from, i});
			}
			from = i + 1;
		}
	}

	if (from < n) {
		segs.push_back({from, n});
	}

	for (auto seg : segs) {
		auto [l, r] = seg;
		for (int i = l + 1; i < r; ++i) {
			int len = r - i;
			int pos = find_most_left(r, len + 1);
			// cerr << i << " " << r << " " << pos << endl;
			ans += (ll) len * (pos - r + 1);
		}
		for (int i = l + 1; i < r; ++i) {
			int len = i - l;
			int pos = find_most_right(l, len);
			// cerr << l << " " << i << " " << pos << endl;
			ans += (ll) len * (l - pos);
		}

		for (int len = 1; len <= r - l - 2; ++len) {
			ans += (ll) len * (r - l - 1 - len);
		}

		int len = r - l;
		int posl = find_most_right(l, len);
		int posr = find_most_left(r, len + 1);
		// cerr << l << " " << r << " " << posl << " " << posr << endl;
		ans += (ll) len * (l - posl) * (posr - r + 1);
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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}