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

int ask(int w) {
	cout << "? " << w << endl;
	int res;
	cin >> res;
	if (res == 0) {
		return INF;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	int l = 0, r = n * 2001;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (ask(mid) == 1) {
			r = mid;
		} else {
			l = mid;
		}
	}

	int min_ans = r - (n - 1);
	int cur_ans = r;
	for (int h = 2; h <= n; ++h) {
		while (true) {
			int q = cur_ans;
			while (q % h || q >= cur_ans) {
				--q;
			}
			if (q < min_ans) {
				break;
			}
			int res = ask(q / h);
			if (res <= h) {
				cur_ans = q / h * res;
			} else {
				break;
			}
		}
	}

	cout << "! " << cur_ans << endl;
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