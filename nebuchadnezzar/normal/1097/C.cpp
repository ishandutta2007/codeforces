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
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n;
	cin >> n;
	map<int, int> left, right;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int bal = 0;
		bool fail = false;
		for (char c : s) {
			if (c == '(') {
				++bal;
			} else {
				--bal;
				if (bal < 0) {
					fail = true;
				}
			}
		}
		if (!fail) {
			left[bal]++;
		}
		reverse(s.begin(), s.end());
		bal = 0;
		fail = false;
		for (char c : s) {
			if (c == ')') {
				++bal;
			} else {
				--bal;
				if (bal < 0) {
					fail = true;
				}
			}
		}
		if (!fail) {
			right[bal]++;
		}
	}

	int ans = 0;

	ans += left[0] / 2;
	left.erase(0);

	for (auto p : left) {
		ans += min(p.ss, right[p.ff]);
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