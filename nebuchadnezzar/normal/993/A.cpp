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

int cross(int x1, int y1, int x2, int y2) {
	return x1 * y2 - y1 * x2;
}

bool inside(int x, int y, vector<pii> poly) {
	int s1 = 0, s2 = 0;
	for (int i = 0; i < szof(poly); ++i) {
		int next = (i + 1) % szof(poly);
		int tmp = cross(poly[i].ff - x, poly[i].ss - y, poly[next].ff - x, poly[next].ss - y);
		s1 += tmp;
		s2 += abs(tmp);
	}

	return abs(s1) == s2;
}

void solve() {
	vector<pii> poly[2];
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 4; ++j) {
			int x, y;
			cin >> x >> y;
			poly[i].push_back({x, y});
		}
	}

	for (int x = -150; x <= 150; ++x) {
		for (int y = -150; y <= 150; ++y) {
			if (inside(x, y, poly[0]) && inside(x, y, poly[1])) {
				cout << "YES\n";
				return;
			}
		}
	}

	cout << "NO\n";
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