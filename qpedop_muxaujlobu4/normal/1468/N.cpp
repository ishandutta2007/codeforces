#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#pragma comment(linker, "/STACK:2769095000")
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstdlib>
//#include<cstdint>
#include<sstream>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<sstream>
#include<numeric>
#include<random>
//#include<functional>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<complex>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef int itn;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pdd;
typedef pair<ll, ld> pid;
typedef pair<int, char> pic;
typedef pair<int, pii> piii;
#define xx first
#define yy second
//#define F first
//#define S second
#define zz second
#define mp make_pair
#define y1 oshfkfsldhs
#define union jfghjdghdjhgjhdjgh
#define all(x) (x).begin(), (x).end()
#define out(x) return void(cout << (x) << endl)
#define OUT(x) ((cout << (x)), exit(0))
const ll MOD = 1e9 + 7; //(ll)998244353;
const ll MOR = (ll)1e9 + 33;
const int dy[] = { 0, 0, 1, 1 };
const int dx[] = { 0, 1, 0, 1 };
const char dc[] = { 'D', 'U', 'R', 'L' };
const ll INF = 1e18 + 100;
const ld EPS = 1e-10;
const double PI = 3.14159265358979323846;
const int SZ = 400;
const ll MAXN = 8e5 + 10;

#ifdef _DEBUG
ll __builtin_popcount(ll x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
inline void getint(int& x) {
	int c = getc(stdin);
	x = 0;
	while (c <= 32)
		c = getc(stdin);
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getc(stdin);
	return;
}
inline void writeint(int& x)
{
	char s[10];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		putc(s[n], stdout);
	putc('\n', stdout);
}

void solve() {
	int c[3], a[5];
	cin >> c[0] >> c[1] >> c[2];
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
	bool yes = 1;
	c[0] -= a[0];
	c[1] -= a[1];
	c[2] -= a[2];
	if (c[0] > 0)
	{
		int r = min(c[0], a[3]);
		c[0] -= r;
		a[3] -= r;
	}
	if (c[1] > 0)
	{
		int r = min(c[1], a[4]);
		c[1] -= r;
		a[4] -= r;
	}
	c[2] -= a[3];
	c[2] -= a[4];
	if (c[0] >= 0 && c[1] >= 0 && c[2] >= 0)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
#ifdef _DEBUG
	auto _ = freopen("input.txt", "r", stdin);
	_ = freopen("output.txt", "w", stdout);
#else
	//auto _ = freopen("improvements.in", "r", stdin);
	//_ = freopen("improvements.out", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) solve();
}