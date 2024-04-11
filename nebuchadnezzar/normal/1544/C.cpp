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

ll get_score(vector<int> const& cnt, int n) {
	ll ret = 0;
	for (int i = 0; i <= 100; ++i) {
		ret += (ll) i * cnt[i];
	}
	int left = n / 4;
	for (int i = 0; left; ++i) {
		int tmp = min(left, cnt[i]);
		left -= tmp;
		ret -= (ll) tmp * i;
	}
	return ret;
}

void solve() {
	int n;
	cin >> n;
	vector<int> cnt_a(101), cnt_b(101);

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		cnt_a[num]++;
	}
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		cnt_b[num]++;
	}

	for (int i = n; ; ++i) {
		// cerr << i << endl;
		if (get_score(cnt_a, i) >= get_score(cnt_b, i)) {
			cout << i - n << "\n";
			return;
		}
		cnt_a[100]++;
		cnt_b[0]++;
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}