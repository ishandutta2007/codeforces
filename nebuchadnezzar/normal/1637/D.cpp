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

const int MAXV = 1e4 + 5;

void solve() {
	int n;
	cin >> n;
	vector<int> arra(n);
	for (int& num : arra) {
		cin >> num;
	}
	vector<int> arrb(n);
	for (int& num : arrb) {
		cin >> num;
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += arra[i] * arra[i] * (n - 2);
		ans += arrb[i] * arrb[i] * (n - 2);
	}

	bitset<MAXV> dp;
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		dp = (dp << arra[i]) | (dp << arrb[i]);
	}

	int sum = accumulate(arra.begin(), arra.end(), 0ll) + accumulate(arrb.begin(), arrb.end(), 0ll);
	int best = INF;
	int mem = -1;
	for (int i = 0; i < MAXV; ++i) {
		if (dp[i]) {
			int val = abs(i - (sum - i));
			if (val < best) {
				best = val;
				mem = i;
			}
		}
	}

	cout << (ll) mem * mem + (ll) (sum - mem) * (sum - mem) + ans << "\n";
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