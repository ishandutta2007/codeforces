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

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
	return pair<int, int>(a.first + b.first, a.second + b.second);
}

void solve() {
	string s;
	cin >> s;
	bool flag = true;
	pair<int, int> curpos(0, 0);
	for (int i = 0; i < (int)s.size(); ++i) {
		pair<int, int> nextpos;
		if (s[i] == 'L') nextpos = curpos + pair<int, int>(-1, 0);
		if (s[i] == 'R') nextpos = curpos + pair<int, int>(1, 0);
		if (s[i] == 'U') nextpos = curpos + pair<int, int>(0, 1);
		if (s[i] == 'D') nextpos = curpos + pair<int, int>(0, -1);
		bool kek = true;
		if (nextpos == make_pair(0, 0)) kek = false;
		//cout << nextpos.first << " " << nextpos.second << endl;
		pair<int, int> cur(0,0);
		for (int j = 0; j < s.size() && kek; ++j) {
			pair<int, int> next;
			if (s[j] == 'L') next = cur + pair<int, int>(-1, 0);
			if (s[j] == 'R') next = cur + pair<int, int>(1, 0);
			if (s[j] == 'U') next = cur + pair<int, int>(0, 1);
			if (s[j] == 'D') next = cur + pair<int, int>(0, -1);
			if (next != nextpos) cur = next;
		}
		if (kek && cur == make_pair(0, 0)) {
			cout << nextpos.first << " " << nextpos.second << endl;
			flag = false;
			break;
		}
		curpos = nextpos;
	}
	if (flag) cout << "0 0" << endl;
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