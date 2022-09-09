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

const int MOD = 998244353;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

void solve() {
	int n;
	cin >> n;
	vector<int> dp(n);
	vector<pair<pii, int>> inp;
	vector<int> arrx;
	for (int i = 0; i < n; ++i) {
		int x, y, s;
		cin >> x >> y >> s;
		inp.push_back({{x, y}, s});
		arrx.push_back(x);
	}

	int bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}

	vector<int> segtree(bpv * 2);

	auto segtree_set = [&](int pos, int val) {
		pos += bpv;
		segtree[pos] = val;
		pos /= 2;
		while (pos) {
			segtree[pos] = sum(segtree[pos * 2], segtree[pos * 2 + 1]);
			pos /= 2;
		}
	};

	auto segtree_get = [&](int l, int r) {
		l += bpv; r += bpv;
		int ret = 0;
		while (l < r) {
			if (l & 1) {
				add(ret, segtree[l++]);
			}
			if (r & 1) {
				add(ret, segtree[--r]);
			}
			l /= 2; r /= 2;
		}
		return ret;
	};

	for (int i = 0; i < n; ++i) {
		dp[i] = (inp[i].ff.ff - inp[i].ff.ss) % MOD;
		int from = lower_bound(arrx.begin(), arrx.end(), inp[i].ff.ss) - arrx.begin();
		add(dp[i], segtree_get(from, i));
		segtree_set(i, dp[i]);
		// cerr << dp[i] << endl;
	}

	int ans = (arrx.back() + 1) % MOD;
	for (int i = 0; i < n; ++i) {
		if (inp[i].ss) {
			add(ans, dp[i]);
		}
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