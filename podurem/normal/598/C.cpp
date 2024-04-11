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

const int INF = (int)1e9 + 7;
const int MAXN = (int)1e3 + 7;
const double EPS = (double)1e-13;

bool comp(pair <pair <long double, long double>, int> a, pair <pair <long double, long double>, int> b)
{
	return atan2(a.X.Y, a.X.X) < atan2(b.X.Y, b.X.X);
}

int main()
{
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector <pair <pair <long double, long double>, int> > a(n);
	forn(i, n)
	{
		cin >> a[i].X.X >> a[i].X.Y;
		a[i].Y = i + 1;
	}
	sort(all(a), comp);
	long double min1 = INF;
	int ans1, ans2;
	forn(i, n - 1)
		if (min1 > (atan2(a[i + 1].X.Y * 100, a[i + 1].X.X * 100) / acos(-1.0) * 18000 - atan2(a[i].X.Y * 100, a[i].X.X * 100) / acos(-1.0) * 18000))
		{
			min1 = atan2(a[i + 1].X.Y * 100, a[i + 1].X.X * 100) / acos(-1.0) * 18000 - atan2(a[i].X.Y * 100, a[i].X.X * 100) / acos(-1.0) * 18000;
			ans1 = a[i].Y;
			ans2 = a[i + 1].Y;
		}
	if (min1 > (atan2(a[0].X.Y * 100, a[0].X.X * 100) / acos(-1.0) * 18000 - (atan2(a[n - 1].X.Y * 100, a[n - 1].X.X * 100) / acos(-1.0) * 18000 - 2 * 18000)))
	{
		ans1 = a[0].Y;
		ans2 = a[n - 1].Y;
	}
	cout << ans1 << " " << ans2;
	return 0;
}