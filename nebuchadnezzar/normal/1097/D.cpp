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

void solve() {
	ll n;
	int k;
	cin >> n >> k;

	vector<pair<ll, int>> primes;

	for (ll i = 2; i * i <= n; ++i) {
		int cnt = 0;
		while (n % i == 0) {
			++cnt;
			n /= i;
		}
		if (cnt) {
			primes.push_back({i, cnt});
		}
	}

	if (n > 1) {
		primes.push_back({n, 1});
	}

	vector<int> inv_num = {0};
	for (int i = 1; i < 1000; ++i) {
		inv_num.push_back(inv(i));
	}

	int ans = 1;

	for (auto p : primes) {
		vector<int> possib(p.ss + 1);
		possib[p.ss] = 1;
		for (int i = 0; i < k; ++i) {
			int cur = 0;
			for (int j = p.ss; j >= 0; --j) {
				add(cur, mult(possib[j], inv_num[j + 1]));
				possib[j] = cur;
			}
		}

		int curp = 1;
		int cur = 0;
		int val = p.ff % MOD;
		for (int i = 0; i <= p.ss; ++i) {
			cur = sum(cur, mult(possib[i], curp));
			curp = mult(curp, val);
		}

		ans = mult(ans, cur);
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