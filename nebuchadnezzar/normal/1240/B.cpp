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


void solve() {
	int n;
	cin >> n;
	vector<int> arr;
	vector<pii> lr(n, {INF, -INF});
	vector<int> not_zero(n);
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		--num;
		arr.push_back(num);
		not_zero[num] = 1;
		lr[num].ff = min(lr[num].ff, i);
		lr[num].ss = max(lr[num].ss, i + 1);
	}
	vector<int> have;
	for (int i = 0; i < n; ++i) {
		if (not_zero[i]) {
			have.push_back(i);
		}
	}
	int cnt = 0;
	int ans = INF;
	for (int i = 0; i < szof(have); ++i) {
		cnt = max(cnt, i);
		while (cnt < szof(have) - 1 && lr[have[cnt]].ss <= lr[have[cnt + 1]].ff) {
			++cnt;
		}
		ans = min(ans, i + szof(have) - 1 - cnt);
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}