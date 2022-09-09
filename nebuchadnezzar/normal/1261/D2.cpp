// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

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
	return mult(factorial[n], mult(inv_factorial[k], inv_factorial[n - k]));
}

void solve() {
	int n, k;
	cin >> n >> k;
	factorial = {1};
	for (int i = 1; i < n + 5; ++i) {
		factorial.push_back(mult(factorial.back(), i));
	}
	inv_factorial.push_back(inv(factorial.back()));
	for (int i = n + 4; i >= 1; --i) {
		inv_factorial.push_back(mult(inv_factorial.back(), i));
	}
	reverse(inv_factorial.begin(), inv_factorial.end());
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	int coef = 1;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int next = (i + 1) % n;
		if (arr[i] == arr[next]) {
			coef = mult(coef, k);
		} else {
			++cnt;
		}
	}

	int inv_2 = inv(2);
	int ans = 0;
	for (int i = 0; i < cnt; ++i) {
		int zero_bal = 0;
		if ((cnt - i) % 2 == 0) {
			zero_bal = cnk(cnt - i, (cnt - i) / 2);
		}
		int cur = mult(mult(sum(mpow(2, cnt - i), MOD - zero_bal), inv_2), mult(cnk(cnt, i), mpow(k - 2, i)));
		// cerr << i << " " << cur << endl;
		add(ans, cur);
	}

	// cerr << coef << endl;
	cout << mult(ans, coef) << "\n";
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