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
int mod = 998244353;
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
bool is_it_prime(int v) {
	for (int i = 2; i * i <= v; ++i)
		if (v % i == 0)return false;
	return true;
}
void solve() {
	int n;
	cin >> n >> mod;
	if (n == 1) {
		cout << "0\n";
		return;
	}
	vector<ll>prec(n - 1);
	prec.back() = 1 % mod;
	for (int i = n - 3, j = n; i >= 0; --i, --j) {
		prec[i] = prec[i + 1] * j % mod;
	}
	vector<ll>dp(maxN);
	dp[maxN / 2] = 1 % mod;
	ll ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		vector<ll>dp1(maxN);
		vector<ll>a(maxN);
		vector<ll>dd(i + 2);
		for (int j = 1, k = i + 1; j <= i + 1; ++j, --k) {
			dd[j] = dd[j - 1] + k;
			dd[j] %= mod;
		}
		for (int j = 0; j < maxN; ++j) {
			if (dp[j] == 0) {
				continue;
			}
			a[j - i] += dp[j];
			a[j - i] %= mod;
			a[j + 1] += (mod - 2 * dp[j] % mod) % mod;
			a[j + 1] %= mod;
			a[j + i + 2] += dp[j];
			a[j + i + 2] %= mod;
		}
		ll s = 0, s1 = 0;
		for (int j = 0; j < maxN; ++j) {
			s1 += a[j];
			s1 %= mod;
			s += s1;
			s %= mod;
			dp1[j] = s;
			if (j > maxN / 2) {
				int tmp = j - maxN / 2;
				ans += prec[i] * dd[(min(i + 1, tmp - 1))] % mod * dp1[j];
				ans %= mod;
			}
		}
		dp = dp1;
	}
	cout << ans << "\n";
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
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}