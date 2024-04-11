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

const int MAXN = 1e6 + 5;
int sieve[MAXN], maxp[MAXN];

void solve() {
	int n;
	cin >> n;
	int from = n, to = n;
	for (int i = 2; i < MAXN; ++i) {
		if (!sieve[i]) {
			//cerr << i << " " << (n - 1) / i * i + 1 << endl;
			if (n % i == 0) {
				from = min(from, (n - 1) / i * i + 1);
			}
			for (int j = i * 2; j < MAXN; j += i) {
				sieve[j] = true;
				maxp[j] = max(maxp[j], i);
			}
		}
	}
	//cerr << from << endl;
	int ans = from;
	for (int i = from; i <= to; ++i) {
		ans = min(ans, i - maxp[i] + 1);
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