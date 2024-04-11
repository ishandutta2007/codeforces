
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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mk make_pair
#define psh push_back
#define X first
#define Y second
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK "exam"

const double INF = (double)2 * 1e9 + 7;
const int MAXN = (int)1e5 + 7;
const double EPS = (double)1e-8;

double f(pair <double, double> a, pair <double, double> b)
{
	return sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
}

double rstMI(pair <ll, ll> a, pair <ll, ll> b, pair <ll, ll> p)
{
	double t1 = 0, t2 = 1, nl, nr;
	forn(i, 200)
	{
		nl = t1 + (t2 - t1) / 3;
		nr = t2 - (t2 - t1) / 3;
		if (f(mk(a.X + (b.X - a.X) * nl, a.Y + (b.Y - a.Y) * nl), p) > f(mk(a.X + (b.X - a.X) * nr, a.Y + (b.Y - a.Y) * nr), p))
			t1 = nl;
		else
			t2 = nr;
	}
	return f(mk(a.X + (b.X - a.X) * t1, a.Y + (b.Y - a.Y) * t1), p);
}

double rstMA(pair <ll, ll> a, pair <ll, ll> b, pair <ll, ll> p)
{
	double t1 = 0, t2 = 1, nl, nr;
	forn(i, 200)
	{
		nl = t1 + (t2 - t1) / 3;
		nr = t2 - (t2 - t1) / 3;
		if (f(mk(a.X + (b.X - a.X) * nl, a.Y + (b.Y - a.Y) * nl), p) < f(mk(a.X + (b.X - a.X) * nr, a.Y + (b.Y - a.Y) * nr), p))
			t1 = nl;
		else
			t2 = nr;
	}
	return f(mk(a.X + (b.X - a.X) * t1, a.Y + (b.Y - a.Y) * t1), p);
}

int main()
{
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	pair <ll, ll> p;
	cin >> p.X >> p.Y;
	vector <pair <ll, ll> > a(n);
	double min1 = INF, max1 = 0;
	forn(i, n)
		cin >> a[i].X >> a[i].Y;
	forn(i, n - 1)
	{
		if (rstMI(a[i], a[i + 1], p) < min1)
			min1 = rstMI(a[i], a[i + 1], p);
		if (rstMA(a[i], a[i + 1], p) > max1)
			max1 = rstMA(a[i], a[i + 1], p);
	}
	if (rstMI(a[0], a[n - 1], p) < min1)
		min1 = rstMI(a[0], a[n - 1], p);
	if (rstMA(a[0], a[n - 1], p) > max1)
		max1 = rstMA(a[0], a[n - 1], p);
	cout.precision(20);
	cout << fixed << acos(-1) * (max1 * max1 - min1 * min1);
	return 0;
}