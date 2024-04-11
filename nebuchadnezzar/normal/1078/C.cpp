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

const int MOD = 998244353;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

int mpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = mult(ret, a);
		}
		a = mult(a, a);
		b >>= 1;
	}
	return ret;
}

int inv(int num) {
	return mpow(num, MOD - 2);
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	function<tuple<int, int, int>(int, int)> dfs = [&](int v, int p) {
		tuple<int, int, int> ret(0, 1, 1);
		vector<tuple<int, int, int>> arr;
		for (int to : graph[v]) {
			if (to != p) {
				auto tmp = dfs(to, v);
				get<1>(ret) = mult(get<1>(ret), sum(get<0>(tmp), get<2>(tmp)));
				get<2>(ret) = mult(get<2>(ret), get<2>(tmp));
				arr.push_back(tmp);
			}
		}
		for (auto val : arr) {
			int cval = mult(mult(get<1>(ret), inv(sum(get<0>(val), get<2>(val)))), get<1>(val));
			add(get<0>(ret), cval);
			add(get<2>(ret), cval);
		}
		// cerr << v + 1 << " " << get<0>(ret) << " " << get<1>(ret) << " " << get<2>(ret) << endl;
		return ret;
	};

	auto tmp = dfs(0, 0);

	cout << get<2>(tmp) << "\n";
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