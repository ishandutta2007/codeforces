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
const int mod = 998244353;
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 2e6 + 100, maxT = 61, A = 179, mid = 150;
mt19937 mt_rand(time(0));
ll bp(ll et, ll b) {
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
ll fact(ll n) {
	ll res = 1;
	for (int i = 1; i <= n; ++i)res = (res * i) % mod;
	return res;
}
vector<int>p;
void solve() {
	int n;
	cin >> n;
	vector<int>t(1010);
	for (int i = 2; i < 1010; ++i) {
		if (t[i] == 1)continue;
		p.push_back(i);
		for (int j = 2 * i; j < 1010; j += i)t[j] = 1;
	}
	vector<int>dp(n + 1, 0);
	dp[1] = 1;
	int s = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = s;
		//++dp[i];
		int add = 1;
		int jj = i;
		for (auto x : p) {
			int cnt = 0;
			while (jj % x == 0) {
				jj /= x;
				++cnt;
			}
			add *= cnt + 1;
		}
		if (jj > 1)add *= 2;
		dp[i] += add;
		dp[i] %= mod;
		s += dp[i];
		if (s >= mod)s -= mod;
	}
	cout << dp[n] << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}