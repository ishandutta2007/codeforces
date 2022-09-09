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
	int ans = 1;
	vector<pii> arrp;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			ans *= i;
			int cur = 0;
			while (n % i == 0) {
				++cur;
				n /= i;
			}
			int p = 0;
			while ((1 << p) < cur) {
				++p;
			}
			arrp.push_back({p, cur != (1 << p)});
		}
	}
	if (n > 1) {
		ans *= n;
		arrp.push_back({0, 0});
	}

	int maxp = 0;
	for (auto p : arrp) {
		maxp = max(maxp, p.ff);
	}
	int cnt = maxp;
	for (auto p : arrp) {
		if (p.ff < maxp || p.ss) {
			++cnt;
			break;
		}
	}

	cout << ans << " " << cnt << "\n";
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