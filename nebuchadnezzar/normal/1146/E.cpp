// Created by Nikolay Budin

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
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
	int n, q;
	cin >> n >> q;
	vector<tuple<int, int, int>> actions;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		actions.push_back({num, 0, i});
	}

	int cnt = 0;

	vector<bool> is_good(q);

	for (int i = 0; i < q; ++i) {
		char c;
		int num;
		cin >> c >> num;
		if (c == '<') {
			if (num <= 0) {
				actions.push_back({num - 1, -1, i});
			} else {
				actions.push_back({num, -1, i});
				++cnt;
				is_good[i] = true;
			}
		} else {
			if (num >= 0) {
				actions.push_back({num + 1, -2, i});
			} else {
				actions.push_back({num, -2, i});
				++cnt;
				is_good[i] = true;
			}
		}
	}

	sort(actions.begin(), actions.end(), [&](auto const& p1, auto const& p2) {
		if (abs(get<0>(p1)) != abs(get<0>(p2))) {
			return abs(get<0>(p1)) < abs(get<0>(p2));
		}
		return get<1>(p1) < get<1>(p2);
	});
	int last = -1, type = -1;
	vector<int> ans(n);
	vector<bool> used(q);
	for (auto p : actions) {
		if (get<1>(p) == 0) {
			if (last == -1) {
				ans[get<2>(p)] = get<0>(p);
				if (cnt % 2) {
					ans[get<2>(p)] *= -1;
				}
			} else {
				if (type == -1) {
					ans[get<2>(p)] = abs(get<0>(p));
				} else {
					ans[get<2>(p)] = -abs(get<0>(p));
				}
				if (cnt % 2) {
					ans[get<2>(p)] *= -1;
				}
			}
		} else {
			if (last < get<2>(p)) {
				last = max(last, 0);
				while (last <= get<2>(p)) {
					if (!used[last]) {
						used[last] = true;
						cnt -= is_good[last];
					}
					last++;
				}
				last = get<2>(p);
				type = get<1>(p);
			}
			if (!used[get<2>(p)]) {
				used[get<2>(p)] = true;
				cnt -= is_good[get<2>(p)];
			}
		}
	}

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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}