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
	vector<vector<int>> graph(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		graph[p].push_back(i);
	}

	vector<int> arrs(n);
	for (int i = 0; i < n; ++i) {
		cin >> arrs[i];
	}

	ll ans = 0;

	function<void(int, int, int)> dfs = [&](int v, int d, int par_val) {
		if (d % 2 == 0) {
			for (int to : graph[v]) {
				if (arrs[v] == -1) {
					arrs[v] = arrs[to];
				} else {
					arrs[v] = min(arrs[v], arrs[to]);
				}
			}
			if (arrs[v] == -1) {
				arrs[v] = par_val;
			}
		}
		// cerr << v << " " << arrs[v] << endl;
		if (par_val > arrs[v]) {
			cout << "-1\n";
			exit(0);
		}
		ans += arrs[v] - par_val;
		for (int to : graph[v]) {
			dfs(to, d + 1, arrs[v]);
		}
	};

	dfs(0, 1, 0);

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