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

const int MOD = 1000000007;

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	vector<pii> acts;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		acts.push_back({l, 1});
		acts.push_back({r, -1});
	}
	sort(acts.begin(), acts.end());
	int bal = 0;

	vector<vector<pii>> segs(n + 1);

	for (auto p : acts) {
		if (p.ss < 0) {
			segs[bal].back().ss = p.ff;
			--bal;
		} else {
			++bal;
			segs[bal].push_back({p.ff, -1});
		}
	}

	ll ans = 0;
	for (auto& v : segs) {
		if (!szof(v)) {
			continue;
		}
		ans += x - y + (ll) y * (v[0].ss - v[0].ff);
		ans %= MOD;
		int prev = v[0].ss;
		for (int i = 1; i < szof(v); ++i) {
			pii p = v[i];
			if ((ll) (p.ff - prev) * y < x - y) {
				ans += (p.ff - prev) * y;
			} else {
				ans += x - y;
			}
			ans += (ll) y * (p.ss - p.ff);
			ans %= MOD;
			prev = p.ss;
		}
	}

	cout << ans % MOD << "\n";
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