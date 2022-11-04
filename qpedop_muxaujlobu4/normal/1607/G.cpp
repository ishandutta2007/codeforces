#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<unordered_map>
#include<random>
#include<ctime>
//#include<complex>
#include<numeric>
typedef long long ll;
typedef long double ld;
typedef unsigned short us;
typedef unsigned long long ull;
//typedef complex<double> base;
using namespace std;
ll gcd(ll i, ll j) {
	if (j == 0)return i;
	else return gcd(j, i % j);
}
#ifdef _DEBUG
int __builtin_popcount(int x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
template<typename T> inline T getint() {
	T val = 0;
	char c;

	bool neg = false;
	while ((c = getchar()) && !(c >= '0' && c <= '9')) {
		neg |= c == '-';
	}

	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));

	return val * (neg ? -1 : 1);
}
//#define int long long
const ll INF = 1e9 + 100;
const int mod = 1000000007;
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 1 << 20, maxT = 1010, A = 179, K = 450;
mt19937 mt_rand(time(0));
ll bp(ll et, ll b) {
	b %= mod - 1;
	et %= mod;
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "impossible\n";
	exit(0);
}
void solve() {
	int n, mm;
	cin >> n >> mm;
	vector<int>a(n), b(n), m(n, mm);
	ll s = 0;
	vector<pair<int, int>>ans(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		if (m[i] > a[i]) {
			b[i] -= m[i] - a[i];
			ans[i].second += m[i] - a[i];
			m[i] = a[i];
		}
		if (m[i] > b[i]) {
			a[i] -= m[i] - b[i];
			ans[i].first += m[i] - b[i];
			m[i] = b[i];
		}
		s += a[i] - b[i];
	}
	for (int i = 0; i < n; ++i) {
		ll fr_a = max(0LL, min(min((ll)a[i], s), (ll)m[i]));
		a[i] -= fr_a;
		s -= fr_a;
		m[i] -= fr_a;
		ans[i].first += fr_a;
		ll fr_b = max(0LL, min(min((ll)b[i], -s), (ll)m[i]));
		b[i] -= fr_b;
		s += fr_b;
		m[i] -= fr_b;
		ans[i].second += fr_b;
		if (m[i] == 0)continue;
		ans[i].first += m[i] / 2;
		ans[i].second += m[i] / 2;
		if (m[i] % 2 == 1) {
			++ans[i].second;
			++s;
		}
	}
	cout << abs(s) << "\n";
	for (auto x : ans) {
		cout << x.first << " " << x.second << "\n";
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("hear.in", "r", stdin); freopen("hear.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
7 7
1 2
2 3
3 4
4 5
2 5
5 6
6 7
5
4 3 2 5 6 7
1
*/