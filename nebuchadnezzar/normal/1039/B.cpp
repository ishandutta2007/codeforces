#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#  define _GLIBCXX_DEBUG_PEDANTIC
#endif

#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

bool ask(ll l, ll r) {
	cout << l + 1 << " " << r << endl;
	string s;
	cin >> s;
	if (s == "Bad") {
		exit(0);
	}
	if (s == "Yes") {
		if (l + 1 == r) {
			exit(0);
		}
		return 1;
	}
	return 0;
}

void solve() {
	ll n;
	int k;
	cin >> n >> k;
	ll l = 0, r = n;
	while (true) {
		if (r - l <= 42) {
			ll pos = rnd(l, r - 1);
			ask(pos, pos + 1);
			l = max(0ll, l - k);
			r = min(n, r + k);
			continue;
		}
		ll mid = (l + r) / 2;
		if (l < n - r) {
			bool res = ask(mid, r);
			if (res) {
				l = mid;
			} else {
				r = mid;
			}
		} else {
			bool res = ask(l, mid);
			if (res) {
				r = mid;
			} else {
				l = mid;
			}
		}
		l = max(0ll, l - k);
		r = min(n, r + k);
	}
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	// cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}