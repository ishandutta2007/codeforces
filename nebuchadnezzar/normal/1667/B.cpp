// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
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
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

int sign(ll num) {
	return num < 0 ? -1 : (num > 0 ? 1 : 0);
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	ll pref = 0;
	vector<int> dp(n + 1, -INF);
	map<ll, int> max_dp_by_pref;
	max_dp_by_pref[0] = 0;
	dp[0] = 0;
	set<pair<ll, int>> have;
	have.insert({0, 0});
	for (int i = 0; i < n; ++i) {
		pref += arr[i];
		dp[i + 1] = max(dp[i + 1], dp[i] + sign(arr[i]));
		if (max_dp_by_pref.count(pref)) {
			dp[i + 1] = max(dp[i + 1], max_dp_by_pref[pref]);
		}
		
		auto it = have.lower_bound({pref, -INF});
		if (it != have.begin()) {
			--it;
			dp[i + 1] = max(dp[i + 1], it->ss + i + 1);
		}

		if (max_dp_by_pref.count(pref)) {
			max_dp_by_pref[pref] = max(max_dp_by_pref[pref], dp[i + 1]);
		} else {
			max_dp_by_pref[pref] = dp[i + 1];
		}

		pair<ll, int> p(pref, dp[i + 1] - (i + 1));
		while (true) {
			auto it = have.lower_bound({pref, -INF});
			if (it != have.end() && it->ss <= p.ss) {
				have.erase(it);
			} else {
				break;
			}
		}
		it = have.lower_bound({pref, INF});
		if (it != have.begin()) {
			--it;
			if (it->ss >= p.ss) {
				continue;
			}
		}
		have.insert(p);
	}

	cout << dp[n] << "\n";
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