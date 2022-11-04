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
const ll INF = 1000000000;
const int mod = 998244353;
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 500010, maxT = 200000, A = 179, K = 450;
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
ll dp1[maxN], dp2[maxN];
void solve() {
	int n;
	cin >> n;
	vector<int>a(n);
	dp1[0] = 1;
	for (auto& x : a) {
		cin >> x;
		vector<int>rn;
		if (x)rn.push_back(x - 1);
		rn.push_back(x + 1);
		rn.push_back(x);
		for (auto j : rn) {
			if (j != x) {
				dp2[j] = (dp2[j] + dp2[j]) % mod;
				if (j < x)dp2[j] = (dp2[j] + dp1[j]) % mod;
				else dp1[j] = (dp1[j] + dp1[j]) % mod;
			}
			else {
				dp1[j + 1] = (dp1[j + 1] + dp1[j]) % mod;
				//dp1[j + 2] = (dp1[j + 2] + dp2[j]) % mod;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i <= n + 1; ++i) {
		ans = (ans + dp1[i] + dp2[i]) % mod;
		dp1[i] = dp2[i] = 0;
	}
	cout << (ans - 1 + mod) % mod << "\n";
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