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
const int mod = 1000000007;
const ld eps = 1e-9, pi = acosl(-1);
const ll maxN = 3 * (1 << 20), maxT = 519, A = 179, mid = 150, K = 350;
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
	cout << "No\n";
	exit(0);
}
ll f[maxN], g[maxN];
void build() {
	f[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		f[i] = f[i - 1] * i % mod;
	}
	g[maxN - 1] = bp(f[maxN - 1], mod - 2);
	for (int i = maxN - 2; i >= 0; --i) {
		g[i] = g[i + 1] * (i + 1) % mod;
	}
}
ll c(int n, int k) {
	return f[n] * g[k] % mod * g[n - k] % mod;
}
int pl(const int& a, const int& b) {
	int r = a + b;
	if (r >= mod)r -= mod;
	return r;
}
void solve() {
	build();
	int n, q;
	cin >> n >> q;
	vector<ll>pol(3 * n + 4);
	vector<ll>pp(3 * n + 4);
	for (int i = 3 * n + 3; i >= 0; --i) {
		pol[i] = c(3 * n + 3, i);
	}
	pol[0] = pl(pol[0], mod - 1);
	pol[1] = pl(pol[1], mod - 3);
	pol[2] = pl(pol[2], mod - 3);
	pol[3] = pl(pol[3], mod - 1);
	vector<ll>t(4);
	t[1] = t[2] = 3;
	t.back() = 1;
	for (int i = 3 * n + 3; i >= 3; --i) {
		vector<ll>tmp = t;
		for (auto& x : tmp)x = x * pol[i] % mod;
		pp[i] = pol[i];
		pol[i] = pl(pol[i], mod - tmp[3]);
		pol[i - 1] = pl(pol[i - 1], mod - tmp[2]);
		pol[i - 2] = pl(pol[i - 2], mod - tmp[1]);
	}
	for (int i = 0; i < 3; ++i)pp[i] = pol[i];
	while (q--) {
		int v;
		cin >> v;
		cout << pp[v + 3] << "\n";
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
	//freopen("commuting.in", "r", stdin); freopen("commuting.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}