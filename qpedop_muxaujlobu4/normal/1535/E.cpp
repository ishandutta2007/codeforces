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
const ld eps = 1e-4, pi = acosl(-1);
const ll maxN = 1 << 20, maxT = 1000000, A = 179, mid = 150;
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
const int sz = 21;
int p[sz][maxN];
ll a[maxN], c[maxN];
void add(int v) {
	for (int i = 1; i < sz; ++i) {
		p[i][v] = p[i - 1][p[i - 1][v]];
	}
}
void solve() {
	int q;
	cin >> q >> a[0] >> c[0];
	p[0][0] = 0;
	for (int i = 1; i <= q; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			cin >> p[0][i] >> a[i] >> c[i];
			add(i);
		}
		else {
			int v, w;
			cin >> v >> w;
			ll t1 = 0, t2 = 0;
			while (w && a[v]) {
				int vv = v;
				for (int j = sz - 1; j >= 0; --j) {
					if (a[p[j][vv]])
						vv = p[j][vv];
				}
				if (a[vv] <= w) {
					w -= a[vv];
					t1 += a[vv];
					t2 += a[vv] * c[vv];
					a[vv] = 0;
				}
				else {
					t1 += w;
					t2 += w * c[vv];
					a[vv] -= w;
					w = 0;
				}
			}
			cout << t1 << " " << t2 << endl;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
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