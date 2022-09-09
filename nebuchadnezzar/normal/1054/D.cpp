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


void solve() {
	int n, k;
	cin >> n >> k;
	int mask = (1 << k) - 1;
	map<int, int> cnt;
	int cur = 0;
	cnt[cur]++;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		cur ^= num;
		cnt[cur]++;
	}

	ll ans = (ll) (n + 1) * n / 2;

	set<int> used;

	for (pii p : cnt) {
		int other = (~p.ff) & mask;
		if (!used.count(p.ff)) {
			used.insert(p.ff);
			used.insert(other);
			int sum = p.ss;
			if (cnt.count(other)) {
				sum += cnt[other];
			}
			int part1 = sum / 2;
			int part2 = sum - part1;
			// cerr << p.ff << " " << part1 << " " << part2 << endl;
			ans -= (ll) part1 * (part1 - 1) / 2;
			ans -= (ll) part2 * (part2 - 1) / 2;
		}
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