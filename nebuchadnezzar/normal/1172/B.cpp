// Created by Nikolay Budin

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
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

const int MOD = 998244353;

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

void solve() {
	int n;
	cin >> n;
	vector<int> factorial = {1};
	for (int i = 1; i < n + 5; ++i) {
		factorial.push_back(mult(factorial.back(), i));
	}
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	function<int(int, int)> dfs = [&](int v, int p) {
		int cnt = 0;
		int ret = 1;
		for (int to : graph[v]) {
			if (to != p) {
				++cnt;
				int tmp = dfs(to, v);
				ret = mult(ret, tmp);
			}
		}

		if (p != v) {
			++cnt;
		}
		ret = mult(ret, factorial[cnt]);

		// cerr << v << " " << ret << endl;

		return ret;
	};

	int ans = mult(dfs(0, 0), n);

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