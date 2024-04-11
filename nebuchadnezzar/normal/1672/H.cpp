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
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> arrpos, arrval;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == s[i + 1]) {
			arrpos.push_back(i);
			arrval.push_back(s[i] - '0');
		}
	}

	vector<pii> pref = {{0, 0}};
	for (int num : arrval) {
		pref.push_back(pref.back());
		if (num == 0) {
			pref.back().ff++;
		} else {
			pref.back().ss++;
		}
	}

	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		int nl = lower_bound(arrpos.begin(), arrpos.end(), l) - arrpos.begin();
		int nr = lower_bound(arrpos.begin(), arrpos.end(), r - 1) - arrpos.begin();
		if (nl == nr) {
			cout << "1\n";
			continue;
		}
		if (nl + 1 == nr) {
			cout << "2\n";
			continue;
		}
		int cnt0 = pref[nr].ff - pref[nl].ff;
		int cnt1 = pref[nr].ss - pref[nl].ss;
		int res = min(cnt0, cnt1);
		int left = max(cnt0, cnt1) - min(cnt0, cnt1);
		cout << res + left + 1 << "\n";
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