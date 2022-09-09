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
	vector<tuple<int, int, ll>> inp;
	for (int i = 0; i < n; ++i) {
		int x, y;
		ll a;
		cin >> x >> y >> a;
		inp.push_back({x, y, a});
	}

	sort(inp.begin(), inp.end());

	deque<tuple<ll, int, int>> lines;
	lines.push_back({0, 0, INF});

	function<ll(int)> get_x = [&](int x) {
		int l = -1, r = szof(lines);
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (get<2>(lines[mid]) < x) {
				l = mid;
			} else {
				r = mid;
			}
		}

		auto [b, k, to] = lines[r];

		return (ll) k * x + b;
	};

	function<void(ll, int)> add_line = [&](ll b, int k) {
		while (szof(lines)) {
			auto [b1, k1, to1] = lines.front();
			if (b <= b1) {
				return;
			}
			ll to = (b - b1) / (k1 - k);
			if (to >= to1) {
				lines.pop_front();
				continue;
			}
			lines.push_front({b, k, to});
			return;
		}
		lines.push_back({b, k, INF});
	};

	ll ans = 0;

	for (auto [x, y, a] : inp) {
		ll val = get_x(y);
		ll res = val + (ll) x * y - a;
		ans = max(ans, res);
		if (res >= 0) {
			add_line(res, -x);
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