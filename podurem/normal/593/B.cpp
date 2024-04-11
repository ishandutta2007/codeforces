#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<long double, long double> pll;
typedef vector<int> vi;

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define for1(i, n) for (int i = 1; i <= (int)n; i++)
#define forq(i, s, t) for (int i = s; i <= (int)t; i++)
#define ford(i, s, t) for (int i = s; i >= (int)t; i--)
#define mk make_pair
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK ""

const double EPS = 1e-15;
const double PI = acos(-1.0);
const int MAXN = (int)1e5 + 7;
const int INF = (int)1e9 + 7;
const int MOD = (int)1e9 + 7;
const ll P = 239017;

int solve();

int main()
{
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("test.txt", "w", stderr);
	double tstart = TIME;
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	solve();
#ifdef _DEBUG
	double tend = TIME;
	cerr << tend - tstart << " s.\n";
#endif
	return 0;
}

ll x1;

bool comp(pll a, pll b)
{
	return (a.first * x1 + a.second < b.first * x1 + b.second) || (a.first * x1 + a.second == b.first * x1 + b.second && a.first < b.first);
}

int solve()
{
	ll n, x2;
	cin >> n;
	vector <pll> a(n);
	cin >> x1 >> x2;
	for (ll i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	sort(all(a), comp);
	for (ll i = 0; i < n - 1; i++)
	{
		if (a[i].first != a[i + 1].first)
		{
			long double x = (a[i + 1].second - a[i].second) / (a[i].first - a[i + 1].first);
			if (x > x1 && x < x2)
			{
				cout << "yes";
				return 0;
			}
		}
	}
	cout << "no";
	return 0;
}