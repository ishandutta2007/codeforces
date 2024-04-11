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

void add(ll& a, ll b, ll mod) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

ll mult(ll a, ll b, ll mod) {
	ll ret = 0;
	while (b) {
		if (b & 1) {
			add(ret, a, mod);
		}
		add(a, a, mod);
		b >>= 1;
	}
	return ret;
}

void solve() {
	ll p, q, b;
	cin >> p >> q >> b;

	p %= q;

	if (p == 0) {
		cout << "Finite\n";
		return;
	}

	ll tmp = __gcd(p, q);
	p /= tmp;
	q /= tmp;

	ll val = b % q;
	for (int i = 0; i < 7; ++i) {
		val = mult(val, val, q);
	}

	if (val == 0) {
		cout << "Finite\n";
	} else {
		cout << "Infinite\n";
	}
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}