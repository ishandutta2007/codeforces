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
const ll INF = 2e18 + 100;
const int mod = 1000000007;
const ld eps = 1e-6, pi = acos(-1);
const ll maxN = 100010, maxT = 4096, A = 179, K = 170;
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
	cout << "No\n";
	exit(0);
}
int n, m;
int run(vector<vector<int>>a) {
	int r = 0;
	vector<vector<int>>b(n, vector<int>(m));
	vector<vector<int>>c(n, vector<int>(m));
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (i + 1 < n)b[i][j] ^= b[i + 1][j];
			if (j + 1 < m)b[i][j] ^= b[i][j + 1];
			if (i + 1 < n && j + 1 < m)b[i][j] ^= b[i + 1][j + 1];
			if ((a[i][j] ^ b[i][j]) == 1) {
				++r;
				b[i][j] ^= 1;
				c[i][j] = 1;
			}
		}
	}
	for (int i = n - 2; i >= 0; --i) {
		for (int j = m - 2; j >= 0; --j) {
			if (c[i][j] == 1 && c[n - 1][m - 1] == 1 && c[i][m - 1] == 1 && c[n - 1][j] == 1) {
				--r;
				return r;
			}
		}
	}
	return r;
}
bool gd(int i, int j, vector<vector<int>>& ps) {
	ll v = (n - i) * (m - j);
	return v == ps[i][j];
}
void solve() {
	cin >> n >> m;
	vector<vector<int>>a(n,vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <  m; ++j) {
			char t;
			cin >> t;
			a[i][j] = t == 'B';
		}
	}
	int ans = run(a);

	cout << ans << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("party.in", "r", stdin); freopen("party.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}