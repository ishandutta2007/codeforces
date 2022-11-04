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
#include <numeric>
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
//#define int ll
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
const int SZ = 100;
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

vector<ll> counters;
vector<int> compress;
vector<int> cnt[MAXN];
vector<int> sets[MAXN];
vector<int> gist;
vector<int> inter;
void solve() {
	int n;
	cin >> n;
	compress.clear();
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		sets[i].resize(m);
		for (int j = 0; j < m; j++)
			cin >> sets[i][j], compress.push_back(sets[i][j]);
		sort(all(sets[i]));
	}

	sort(all(compress));
	compress.resize(unique(all(compress)) - compress.begin());
	int m = compress.size();
	for (int x = 0; x < m; x++)
		cnt[x].clear();
	for (int i = 0; i < n; i++)
	{
		for (int& x : sets[i])
			x = lower_bound(all(compress), x) - compress.begin();
	}
	for (int i = 0; i < n; i++)
	{
		for (int x : sets[i])
			cnt[x].push_back(i);
	}
	for (int x = 0; x < m; x++)
	{
		if (cnt[x].size() >= SZ)
			inter.push_back(x);
	}
	for (int x : inter)
	{
		gist.assign(m, 0);
		for (int i : cnt[x])
		{
			for (int j = 0; j < sets[i].size(); j++)
			{
				if (sets[i][j] == x)
					continue;
				if (gist[sets[i][j]] > 0)
				{
					cout << gist[sets[i][j]] << " " << i + 1 << "\n";
					return;
				}
				gist[sets[i][j]] = i + 1;
			}
		}
	}
	counters.clear();
	for (int x = 0; x < m; x++)
	{
		if (cnt[x].size() >= SZ)
			continue;
		for (int i = 0; i < cnt[x].size(); i++)
			for (int j = i + 1; j < cnt[x].size(); j++)
				counters.push_back(ll(cnt[x][i] + 1) * MOD + cnt[x][j] + 1);
	}
	sort(all(counters));
	for (int i = 1; i < counters.size(); i++)
	{
		if (counters[i] == counters[i - 1])
		{
			cout << counters[i] % MOD << " " << counters[i - 1] / MOD << "\n";
			return;
		}
	}
	cout << "-1\n";
}

int32_t main()
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