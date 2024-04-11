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

const int SZ = 30;

void solve() {
	int n;
	cin >> n;
	vector<pii> segs;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		segs.push_back({l, r});
	}

	vector<pair<int, int>> events, events1, events2;
	vector<int> arr_ans(SZ);
	for (int i = 0; i < 30; ++i) {
		int s = 1 << i;
		events1.clear();
		for (int j = 0; j < n; ++j) {
			auto [l, r] = segs[j];
			int q = l / s;
			l -= q * s;
			r -= q * s;
			events1.push_back({l, j * 2 + 0});
			events1.push_back({r, j * 2 + 1});
		}
		sort(events1.begin(), events1.end());

		events2.clear();
		for (auto p : events1) {
			events2.push_back({p.ff + s, p.ss});
		}

		events.resize(szof(events1) + szof(events2));
		merge(events1.begin(), events1.end(), events2.begin(), events2.end(), events.begin());
		int bal = 0;
		vector<int> cnt(n);
		int prevx = 0;
		int ans = 0;
		for (auto [x, tmp] : events) {
			int ind = tmp / 2;
			int t = tmp % 2;
			if (prevx < x) {
				ans = max(ans, bal);
			}
			prevx = x;
			bal -= cnt[ind] > 0;
			cnt[ind] += t == 0 ? 1 : -1;
			bal += cnt[ind] > 0;
		}

		arr_ans[i] = ans;
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int num;
		cin >> num;
		int tmp = __builtin_ctz(num);
		cout << arr_ans[tmp] << "\n";
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