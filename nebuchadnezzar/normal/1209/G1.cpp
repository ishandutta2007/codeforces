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
	vector<int> arr;
	map<int, pii> where;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
		if (!where.count(num)) {
			where[num] = {i, i};
		} else {
			where[num].ss = i;
		}
	}

	vector<pii> segs;
	for (auto p : where) {
		segs.push_back(p.ss);
	}

	sort(segs.begin(), segs.end());
	vector<pii> ans_segs;
	for (auto p : segs) {
		if (szof(ans_segs) && p.ff <= ans_segs.back().ss) {
			ans_segs.back().ss = max(ans_segs.back().ss, p.ss);
		} else {
			ans_segs.push_back(p);
		}
	}
	int ans = 0;
	for (auto s : ans_segs) {
		map<int, int> cnt;
		for (int i = s.ff; i <= s.ss; ++i) {
			cnt[arr[i]]++;
		}
		int maxv = 0;
		for (auto p : cnt) {
			maxv = max(maxv, p.ss);
		}
		ans += s.ss - s.ff + 1 - maxv;
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