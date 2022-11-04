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
const ll INF = 1000000007;
const int mod = 998244353;
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 200100, maxT = 510, A = 179, K = 450;
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
ll f[maxN], a[maxN], b[maxN];
vector<int>qq[1 << 20];
vector<int>recalc[1 << 20];
void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		a[i] -= max(0LL, b[i]);
	}
	int q;
	cin >> q;
	vector<ll>qw(q);
	for (int i = 0; i < q; ++i) {
		ll tmp;
		cin >> tmp;
		qq[tmp].push_back(i);
	}
	f[1] = -1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 2 * i; j <= n; j += i) {
			f[j] -= f[i];
			a[j] -= a[i];
		}
	}
	ll ans = 0, kf = 0;
	for (int i = 1; i <= n; ++i) {
		ans += abs(a[i]);
		if (f[i] == 0) {
			continue;
		}
		if (f[i] * a[i] > 0) {
			kf += abs(f[i]);
			continue;
		}
		ll tmp = abs(a[i]) / abs(f[i]);
		//ans += abs(a[i]);
		kf -= abs(f[i]);
		if (tmp < (1 << 20))recalc[tmp].push_back(i);
	}
	for (ll curr = 0; curr < (1 << 20); ++curr) {
		for (auto x : qq[curr])qw[x] = ans;
		for (auto i : recalc[curr]) {
			ans -= abs(a[i] - f[i] * curr);
			ans += abs(a[i] - f[i] * (curr + 1));
			ans -= abs(f[i]);
			kf += 2 * abs(f[i]);
		}
		ans += kf;
	}


	for (auto x : qw)cout << x << "\n";
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
	//cin >> t;
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