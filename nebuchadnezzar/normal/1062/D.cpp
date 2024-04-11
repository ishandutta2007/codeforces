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
	vector<vector<int>> graph(n - 2 + 1);
	vector<ll> cost(n - 2 + 1);
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j * j <= i; ++j) {
			if (i % j == 0) {
				graph[i - 2].push_back(j - 2);
				graph[j - 2].push_back(i - 2);
				cost[i - 2] += i / j;
				if (i / j > j) {
					graph[i - 2].push_back(i / j - 2);
					graph[i / j - 2].push_back(i - 2);
					cost[i - 2] += j;
				}
			}
		}
	}

	ll s = 0;
	vector<int> used(n - 1);
	function<void(int)> dfs = [&](int v) {
		used[v] = true;
		s += cost[v];
		for (int to : graph[v]) {
			if (!used[to]) {
				dfs(to);
			}
		}
	};

	ll ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (!used[i]) {
			s = 0;
			dfs(i);
			ans = max(ans, s);
		}
	}

	cout << ans * 4 << "\n";
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