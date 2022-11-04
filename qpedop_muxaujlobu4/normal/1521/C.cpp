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
const ll maxN = 250010, maxT = 4010, A = 179, mid = 150;
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
void panic() {
	cout << "-1\n";
	exit(0);
}
int qw(int t, int i, int j, int x) {
	cout << "? " << t << " " << i << " " << j << " " << x << endl;
	int v;
	cin >> v;
	if (v == -1)
		exit(0);
	return v;
}
void solve() {
	int n;
	cin >> n;
	set<int>s;
	for (int i = 0; i < n; i += 2) {
		int i1 = i;
		int j1 = (i + 1) % n;
		++i1;
		++j1;
		int v = qw(2, i1, j1, 1);
		if (v <= 2) {
			s.insert(i1);
			s.insert(j1);
		}
	}
	int i1 = -1;
	for (auto x : s) {
		for (auto y : s) {
			if (y <= x) {
				continue;
			}
			if (qw(2, x, y, 1) == 1) {
				i1 = x;
			}
			if (qw(2, y, x, 1) == 1) {
				i1 = y;
			}
		}
	}
	vector<int>ans(n);
	ans[i1 - 1] = 1;
	for (int i = 0; i < n; ++i) {
		if (i + 1 == i1)
			continue;
		ans[i] = qw(1, i1, i + 1, n - 1);
	}
	cout << "! ";
	for (auto x : ans)cout << x << " ";
	cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
	//srand(time(0));
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("gymnasts.in", "r", stdin); freopen("gymnasts.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}