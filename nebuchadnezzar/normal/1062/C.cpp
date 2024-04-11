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

void solve() {
	/*for (int ones = 0; ones < 100; ++ones) {
		for (int zeroes = 0; zeroes < 100; ++zeroes) {
			int ans = sum(mpow(2, ones), MOD - 1);
			int val = ans;
			add(ans, mult(sum(mpow(2, zeroes), MOD - 1), val));
			int curone = 1, curzero = 0;
			int ans2 = 0;
			for (int j = 0; j < ones; ++j) {
				int val = curone;
				add(ans2, val);
				add(curone, val);
				add(curzero, val);
			}
			for (int j = 0; j < zeroes; ++j) {
				int val = curzero;
				add(ans2, val);
				add(curzero, val);
			}
			if (ans != ans2) {
				cout << ones << " " << zeroes << endl;
				cerr << ans << " " << ans2 << endl;
			}
			assert(ans == ans2);
			// cout << ans << "\n";
		}
	}*/

	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> arr;
	vector<int> pref = {0};
	for (int i = 0; i < n; ++i) {
		arr.push_back(s[i] - '0');
		pref.push_back(pref.back() + arr.back());
	}

	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		int ones = pref[r] - pref[l];
		int zeroes = (r - l) - ones;
		int ans = sum(mpow(2, ones), MOD - 1);
		int val = ans;
		add(ans, mult(sum(mpow(2, zeroes), MOD - 1), val));
		/*int curone = 1, curzero = 0;
		int ans2 = 0;
		for (int j = 0; j < ones; ++j) {
			int val = curone;
			add(ans2, val);
			add(curone, val);
			add(curzero, val);
		}
		for (int j = 0; j < zeroes; ++j) {
			int val = curzero;
			add(ans2, val);
			add(curzero, val);
		}
		assert(ans == ans2);*/
		cout << ans << "\n";
	}
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