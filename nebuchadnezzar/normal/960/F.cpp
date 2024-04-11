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
	int n, m;
	cin >> n >> m;
	vector<set<pii>> have(n);
	for (int i = 0; i < n; ++i) {
		have[i].insert({-INF, 0});
	}
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		--a; --b;
		//cerr << a << " " << b << endl;
		auto it = have[a].lower_bound({w, -INF});
		if (it == have[a].begin()) {
			continue;
		}
		--it;
		int val = it->ss + 1;
		while (true) {
			it = have[b].lower_bound({w, -INF});
			if (it != have[b].end() && it->ss <= val) {
				have[b].erase(it);
			} else {
				break;
			}
		}
		it = have[b].lower_bound({w, -INF});
		if (it != have[b].begin()) {
			--it;
			if (it->ss >= val) {
				continue;
			}
		}
		have[b].insert({w, val});
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (szof(have[i])) {
			ans = max(ans, (--have[i].end())->ss);
		}
	}
	cout << ans << "\n";
}


int main() {
	//freopen("in", "r", stdin);
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