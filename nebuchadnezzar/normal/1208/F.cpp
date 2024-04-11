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

const int P = 21;

void upd(pii& p, int num) {
	if (p.ss < num) {
		p.ff = p.ss;
		p.ss = num;
	} else if (p.ff < num && num < p.ss) {
		p.ff = num;
	}
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

	vector<pii> maxs(1 << P);
	for (int i = 0; i < n; ++i) {
		upd(maxs[arr[i]], i);
	}

	for (int mask = (1 << P) - 1; mask >= 0; --mask) {
		for (int j = 0; j < P; ++j) {
			if (mask & (1 << j)) {
				int other = mask ^ (1 << j);
				upd(maxs[other], maxs[mask].ff);
				upd(maxs[other], maxs[mask].ss);
			}
		}
	}

	// cerr << maxs[4].ff << " " << maxs[4].ss << endl;

	int res = 0;
	for (int b = P - 1; b >= 0; --b) {
		res |= 1 << b;
		// cerr << res << endl;

		bool ok = false;

		for (int i = 0; i < n; ++i) {
			int need = res & (~arr[i]);
			// cerr << i << " " << need << endl;
			
			if (maxs[need].ff > i) {
				ok = true;
				break;
			}
		}

		if (!ok) {
			res ^= 1 << b;
		}
	}

	cout << res << "\n";
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