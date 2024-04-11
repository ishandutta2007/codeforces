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

const int MOD = 998244353;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> inp;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		inp.push_back(num);
	}

	vector<pii> d(201);
	d[0] = {1, 0};
	for (int i = 0; i < n; ++i) {
		vector<pii> next(201);
		if (inp[i] != -1) {
			add(next[inp[i]].ff, d[inp[i]].ff);
			add(next[inp[i]].ff, d[inp[i]].ss);
			for (int j = inp[i] + 1; j <= 200; ++j) {
				add(next[inp[i]].ff, d[j].ff);
			}
			for (int j = 0; j < inp[i]; ++j) {
				add(next[inp[i]].ss, d[j].ff);
				add(next[inp[i]].ss, d[j].ss);
			}
		} else {
			int curs = 0;
			add(curs, d[0].ff);
			add(curs, d[0].ss);
			
			for (int dig = 1; dig <= 200; ++dig) {
				add(next[dig].ff, d[dig].ff);
				add(next[dig].ff, d[dig].ss);
				add(next[dig].ss, curs);
				add(curs, d[dig].ff);
				add(curs, d[dig].ss);
			}

			curs = 0;


			for (int dig = 200; dig >= 1; --dig) {
				// for (int j = dig + 1; j <= 200; ++j) {
				// 	add(next[dig].ff, d[j].ff);
				// }

				add(next[dig].ff, curs);
				add(curs, d[dig].ff);
			}
		}

		swap(d, next);
	}

	int ans = 0;

	for (int i = 0; i <= 200; ++i) {
		add(ans, d[i].ff);
	}

	cout << ans << "\n";
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