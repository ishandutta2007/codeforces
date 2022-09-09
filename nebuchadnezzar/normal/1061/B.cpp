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
	int n, m;
	cin >> n >> m;
	int maxval = 0;
	ll sum = 0;
	vector<int> all;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		all.push_back(a);
		sum += a;
		maxval = max(maxval, a);
	}

	sort(all.begin(), all.end());
	ll ans = sum - (n + maxval - 1);
	// cerr << ans << endl;
	int c = 0;
	for (int i = 1; i <= n && i <= maxval - 1; ++i) {
		while (c < szof(all) - 1 && all[c] < i) {
			++c;
		}
		if (c < szof(all) - 1) {
			// cerr << i << endl;
			++c;
			++ans;
		}
	}
	cout << ans << "\n";
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