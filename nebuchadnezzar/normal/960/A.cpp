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


void solve() {
	string s;
	cin >> s;
	int a = 0, b = 0, c = 0, pos = 0;
	while (pos < szof(s) && s[pos] == 'a') {
		++a;
		++pos;
	}

	while (pos < szof(s) && s[pos] == 'b') {
		++b;
		++pos;
	}

	while (pos < szof(s) && s[pos] == 'c') {
		++c;
		++pos;
	}

	if (pos == szof(s) && a && b && (c == a || c == b)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
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