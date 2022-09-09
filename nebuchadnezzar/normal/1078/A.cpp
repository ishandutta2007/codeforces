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

double sqr(double num) {
	return num * num;
}

void solve() {
	double a, b, c;
	double x1, y1, x2, y2;
	cin >> a >> b >> c;
	cin >> x1 >> y1 >> x2 >> y2;

	double ans = abs(x2 - x1) + abs(y2 - y1);

	vector<pair<double, pair<double, double>>> v1, v2;
	if (a) {
		double newx = (-c - (double) b * y1) / a;
		v1.push_back({abs(newx - x1), {newx, y1}});

		newx = (-c - (double) b * y2) / a;
		v2.push_back({abs(newx - x2), {newx, y2}});
	}

	if (b) {
		double newy = (-c - (double) a * x1) / b;
		v1.push_back({abs(newy - y1), {x1, newy}});

		newy = (-c - (double) a * x2) / b;
		v2.push_back({abs(newy - y2), {x2, newy}});
	}

	for (auto p1 : v1) {
		for (auto p2 : v2) {
			double l = p1.ff + p2.ff + sqrt(sqr(p1.ss.ff - p2.ss.ff) + sqr(p1.ss.ss - p2.ss.ss));
			ans = min(ans, l);
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