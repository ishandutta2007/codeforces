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
	vector<pii> all;
	pii minx = {INF, -1};
	pii maxx = {-INF, -1};
	pii miny = {INF, -1};
	pii maxy = {-INF, -1};
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		all.push_back({x, y});
		minx = min(minx, {x, i});
		maxx = max(maxx, {x, i});
		miny = min(miny, {y, i});
		maxy = max(maxy, {y, i});
	}

	vector<int> interesting = {minx.ss, maxx.ss, miny.ss, maxy.ss};
	sort(interesting.begin(), interesting.end());
	interesting.erase(unique(interesting.begin(), interesting.end()), interesting.end());

	int ans = 0;
	for (int i = 0; i < szof(interesting); ++i) {
		int a = interesting[i];
		for (int j = i + 1; j < szof(interesting); ++j) {
			int b = interesting[j];
			for (int k = 0; k < n; ++k) {
				int x1 = min(min(all[a].ff, all[b].ff), all[k].ff);
				int x2 = max(max(all[a].ff, all[b].ff), all[k].ff);
				int y1 = min(min(all[a].ss, all[b].ss), all[k].ss);
				int y2 = max(max(all[a].ss, all[b].ss), all[k].ss);
				ans = max(ans, x2 - x1 + y2 - y1);
			}
		}
	}

	cout << ans * 2 << " ";
	ans = maxx.ff - minx.ff + maxy.ff - miny.ff;
	for (int i = 4; i <= n; ++i) {
		cout << ans * 2 << " ";
	}
	cout << "\n";
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