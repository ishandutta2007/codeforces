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
const ld eps = 1e-9, pi = acosl(-1);
const ll maxN = 1 << 10, maxT = 2001, A = 179, mid = 150;
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
	cout << "No solution\n";
	exit(0);
}
ll ps[maxN][maxN], a[maxN][maxN], vl[maxT];
int xx1[maxT], yy1[maxT], xx2[maxT], yy2[maxT];
int sz = 0;
int n;
void rbld() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < sz; ++i) {
		a[xx1[i]][yy1[i]] ^= vl[i];
		a[xx1[i]][yy2[i] + 1] ^= vl[i];
		a[xx2[i] + 1][yy1[i]] ^= vl[i];
		a[xx2[i] + 1][yy2[i] + 1] ^= vl[i];
		/*if (xx1[i] % 2 == xx2[i] % 2) {
			if (yy1[i] % 2 == yy2[i] % 2) {
				a[xx1[i]][yy1[i]] ^= vl[i];
				a[xx1[i]][yy2[i] + 1] ^= vl[i];
				a[xx2[i] + 1][yy1[i]] ^= vl[i];
				a[xx2[i] + 1][yy2[i] + 1] ^= vl[i];
			}
			else {
				a[xx1[i]][yy1[i]] ^= vl[i];
				a[xx1[i]][yy2[i] + 1] ^= vl[i];
			}
		}
		else {
			if (yy1[i] % 2 == yy2[i] % 2) {
				a[xx1[i]][yy1[i]] ^= vl[i];
				a[xx2[i] + 1][yy1[i]] ^= vl[i];
			}
			else {
				a[xx1[i]][yy1[i]] ^= vl[i];
				a[xx2[i] + 1][yy1[i]] ^= vl[i];
				a[xx1[i]][yy2[i] + 1] ^= vl[i];
				a[xx2[i] + 1][yy2[i] + 1] ^= vl[i];
			}
		}*/
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i > 1) {
				a[i][j] ^= a[i - 2][j];
				if (j > 1)
					a[i][j] ^= a[i - 2][j - 2] ^ a[i][j - 2];
			}
			else {
				if (j > 1)a[i][j] ^= a[i][j - 2];
			}
			ps[i][j] ^= a[i][j];
			//ps[i][j] ^= a[i][j];
		}
	}
	sz = 0;
}
void solve() {
	n = getint<int>();
	int q = getint<int>();
	//cin >> n >> q;
	while (q--) {
		int tip = getint<int>();
		//cin >> tip;
		if (tip == 2) {
			xx1[sz] = getint<int>();
			yy1[sz] = getint<int>();
			xx2[sz] = getint<int>();
			yy2[sz] = getint<int>();
			vl[sz] = getint<ll>();
			//cin >> xx1[sz] >> yy1[sz] >> xx2[sz] >> yy2[sz] >> vl[sz];
			++sz;
		}
		else {
			int xl, yl, xr, yr;
			xl = getint<int>(), yl = getint<int>(), xr = getint<int>(), yr = getint<int>();
			//cin >> xl >> yl >> xr >> yr;
			ll r = ps[xr][yr] ^ ps[xr][yl - 1] ^ ps[xl - 1][yr] ^ ps[xl - 1][yl - 1];
			for (int i = 0; i < sz; ++i) {
				int d1 = (xr < xx2[i] ? xr : xx2[i]) - (xl > xx1[i] ? xl : xx1[i]) + 1;
				int d2 = (yr < yy2[i] ? yr : yy2[i]) - (yl > yy1[i] ? yl : yy1[i]) + 1;
				if (d1 >= 0 && d2 >= 0 && (d1 & d2 & 1) == 1)
					r ^= vl[i];
			}
			cout << r << "\n";
		}
		if (q % maxT == maxT - 1) {
			rbld();
		}
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	//srand(time(0));
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

/*
5
2 1 3 5 4
simple solve: 1 2 3 1 2
1 2 3 3 3
*/