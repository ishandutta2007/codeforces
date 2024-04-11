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
const ll INF = 1e18 + 100;
const int mod = 998244353;
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 100100, maxT = 4010, A = 179, mid = 150;
mt19937 mt_rand(time(0));
ll bp(ll et, ll b) {
	b %= mod - 1;
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
int f[maxN];
int g[maxN];
void panic() {
	cout << "-1\n";
	exit(0);
}
ll c(int n, int k) {
	return (ll)f[n] * g[k] % mod * g[n - k] % mod;
}
void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	int cnt1 = 1;
	for (int i = 0; i + 1 < n; ++i) {
		if (s[i] == '1' && s[i + 1] == '1') {
			++cnt;
			++i;
		}
	}
	for (auto x : s) {
		if (x == '0')++cnt1;
	}
	cout << c(cnt1 + cnt - 1, cnt) << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("gymnasts.in", "r", stdin); freopen("gymnasts.out", "w", stdout);
#endif
	f[0] = g[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		f[i] = (ll)f[i - 1] * i % mod;
		g[i] = bp(f[i], mod - 2);
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}