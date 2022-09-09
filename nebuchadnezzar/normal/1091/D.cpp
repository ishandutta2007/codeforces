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

vector<int> factorial, inv_factorial;

int cnk(int n, int k) {
	if (k < 0 || k > n) {
		return 0;
	}

	return mult(factorial[n], mult(inv_factorial[k], inv_factorial[n - k]));
}

void solve() {
	int n;
	cin >> n;
	factorial.push_back(1);
	for (int i = 1; i <= n + 10; ++i) {
		factorial.push_back(mult(factorial.back(), i));
	}
	inv_factorial.push_back(inv(factorial.back()));
	for (int i = n + 10; i >= 1; --i) {
		inv_factorial.push_back(mult(inv_factorial.back(), i));
	}
	reverse(inv_factorial.begin(), inv_factorial.end());
	int ans = factorial[n];
	for (int i = 0; i < n; ++i) {
		int k = n - i - 1;
		// cerr << i << " " << sum(mult(cnk(n - 1, k), n), MOD - cnk(n, k + 1)) << endl; 
		add(ans, mult(i, mult(factorial[i], sum(mult(cnk(n - 1, k), n), MOD - cnk(n, k + 1)))));
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