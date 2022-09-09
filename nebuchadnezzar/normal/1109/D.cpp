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

const int MOD = 1000000007;

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

vector<int> fact = {1};

int factorial(int n) {
	while (szof(fact) <= n) {
		fact.push_back(mult(fact.back(), szof(fact)));
	}
	// cerr << n << " " << szof(fact) << endl;
	return fact[n];
}

int ank(int n, int k) {
	return mult(factorial(n), inv(factorial(n - k)));
}

int cnk(int n, int k) {
	return mult(mult(factorial(n), inv(factorial(n - k))), inv(factorial(k)));
}

void solve() {
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int l = 2; l <= n && l - 1 <= m; ++l) {
		// cerr << l << " " << ank(n - 2, l - 2) << " " << cnk(m - 1, l - 2) << endl;
		int cur = mult(ank(n - 2, l - 2), cnk(m - 1, l - 2));
		// cerr << mpow(m, n - l) << endl;
		cur = mult(cur, mpow(m, n - l));
		if (l < n) {
			int tmp = mpow(n, n - l - 1);
			tmp = mult(tmp, l);
			cur = mult(cur, tmp);
			// cerr << tmp << endl;
		}
		add(ans, cur);
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