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

int main()
{
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll n, A, cf, cm, m;
	cin >> n >> A >> cf >> cm >> m;
	vector <pair <ll, ll> > a(n);
	vector <ll> ans(n, -1);
	forn(i, n)
	{
		cin >> a[i].X;
		a[i].Y = i;
	}
	sort(all(a));
	vector <ll> pref(n), pref2(n);
	pref[0] = a[0].X;
	forn(i, n - 1)
		pref[i + 1] = pref[i] + a[i + 1].X;
	pref2[0] = A - a[n - 1].X;
	forn(i, n - 1)
		pref2[i + 1] = pref2[i] + A - a[n - i - 2].X;
	ll copm, uk = n - 1, max1 = -1, ukans, kol, zn;
	forn(i, n + 1)
	{
		if (i == 0)
			copm = m;
		else
			copm = m - pref2[i - 1];
		if (copm < 0)
			break;
		if (i == n)
		{
			cout << n * cf + A * cm << "\n";
			forn(i, n)
				cout << A << " ";
			return 0;
		}
		uk = min(uk, n - i - 1);
		if (uk != -1)
			while (a[uk].X * (uk + 1) - pref[uk] > copm)
			{
				uk--;
				if (uk == -1)
					break;
			}
		if (uk != -1)
		{
			copm -= a[uk].X * (uk + 1) - pref[uk];
			if (min(A, (a[uk].X + copm / (uk + 1))) * cm + i * cf > max1)
			{
				max1 = (min(A, a[uk].X + copm / (uk + 1))) * cm + i * cf;
				ukans = uk;
				kol = i;
				zn = min(A, a[uk].X + copm / (uk + 1));
			}
		}
	}
	cout << max1 << "\n";
	forn(i, kol)
		ans[a[n - i - 1].Y] = A;
	forn(i, ukans + 1)
		if (ans[a[i].Y] == -1)
			ans[a[i].Y] = zn;
	forn(i, n)
		if (ans[a[i].Y] == -1)
			ans[a[i].Y] = a[i].X;
	forn(i, n)
		cout << ans[i] << " ";
	return 0;
}