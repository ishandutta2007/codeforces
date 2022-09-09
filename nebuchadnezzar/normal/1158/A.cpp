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
	int n, m;
	cin >> n >> m;
	ll ans = 0;
	multiset<pii> have;
	int maxv = 0;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		maxv = max(maxv, num);
		ans += (ll) num * m;
		have.insert({num, m - 1});
	}

	for (int i = 0; i < m; ++i) {
		int num;
		cin >> num;
		if (num < maxv) {
			cout << "-1\n";
			return;
		}
		if (num == maxv) {
			continue;
		}
		while (szof(have) && (--have.end())->ss == 0) {
			have.erase(--have.end());
		}
		if (!szof(have)) {
			cout << "-1\n";
			return;
		}
		auto p = *--have.end();
		have.erase(--have.end());
		ans += num - p.ff;
		p.ss--;
		have.insert(p);
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