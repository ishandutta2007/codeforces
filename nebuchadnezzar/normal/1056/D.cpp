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
	for (int i = 0; i < n - 1; ++i) {
		int p;
		cin >> p;
		--p;
		graph[p].push_back(i + 1);
	}

	vector<int> arr(n + 1);

	function<int(int)> dfs = [&](int v) {
		int ret = 0;
		if (!szof(graph[v])) {
			++ret;
		}
		for (int to : graph[v]) {
			ret += dfs(to);
		}
		arr[ret]++;
		return ret;
	};

	dfs(0);

	int s = 0;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		while (s < i) {
			s += arr[cnt];
			++cnt;
		}
		cout << cnt - 1 << " ";
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