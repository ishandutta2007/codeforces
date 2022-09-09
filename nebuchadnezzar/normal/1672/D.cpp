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
	vector<pii> arra;
	vector<pii> arrb;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		if (!szof(arra) || arra.back().ff != num) {
			arra.push_back({num, 1});
		} else {
			arra.back().ss++;
		}
	}
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		if (!szof(arrb) || arrb.back().ff != num) {
			arrb.push_back({num, 1});
		} else {
			arrb.back().ss++;
		}
	}

	map<int, int> bal;
	int cnt = szof(arrb) - 1;
	for (int i = szof(arra) - 1; i >= 0; --i) {
		if (cnt >= 0 && arrb[cnt].ff == arra[i].ff) {
			bal[arrb[cnt].ff] += arrb[cnt].ss;
			--cnt;
		}
		bal[arra[i].ff] -= arra[i].ss;
		if (bal[arra[i].ff] < 0) {
			cout << "NO\n";
			return;
		}
	}
	if (cnt >= 0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
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