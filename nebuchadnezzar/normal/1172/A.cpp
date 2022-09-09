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
	int n;
	cin >> n;
	multiset<int> in_hand;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		in_hand.insert(num);
	}
	vector<int> st;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		st.push_back(num);
	}

	int have = 0;
	for (int i = 0; i < n; ++i) {
		if (st[i] == 1) {
			bool ok = true;
			for (int j = i; j < n; ++j) {
				if (st[j] != j - i + 1) {
					ok = false;
					break;
				}
			}
			if (ok) {
				have = n - i;
			}
		}
	}

	int ans1 = 0;
	for (int i = 0; i < n; ++i) {
		if (st[i]) {
			ans1 = max(ans1, i - st[i] + 2);
		}
	}


	if (have) {
		int ans2 = -have;
		for (int i = 0; i < n - have; ++i) {
			if (st[i]) {
				ans2 = max(ans2, i - st[i] + 2);
			}
		}
		if (ans2 == -have) {
			ans1 = min(ans1, ans2);
		}
	}

	cout << ans1 + n << "\n";

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