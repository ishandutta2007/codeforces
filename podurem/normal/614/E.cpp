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

int nod(int a, int b)
{
	if (b == 0)
		return a;
	else
		return nod(b, a % b);
}

int main()
{
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, gcd, kol = 0;
	cin >> n;
	vi a(n);
	forn(i, n)
	{
		cin >> a[i];
		kol += a[i] % 2;
	}
	if (n == 1)
	{
		cout << a[0] << "\n";
		forn(i, a[0])
			cout << 'a';
		return 0;
	}
	if (kol > 1)
	{
		cout << 0 << "\n";
		forn(i, n)
			forn(j, a[i])
				cout << char('a' + i);
		return 0;
	}
	gcd = nod(a[0], a[1]);
	for (int i = 2; i < n; i++)
		gcd = nod(gcd, a[i]);
	if (kol == 1)
	{
		string s = "", q = "", s1 = "";
		forn(i, n)
			if (a[i] % 2)
			{
				a[i] /= gcd;
				forn(j, a[i])
					q.psh('a' + i);
			}
			else
			{
				a[i] /= 2 * gcd;
				forn(j, a[i])
					s.psh('a' + i);
			}
		s1 = s;
		reverse(all(s1));
		cout << gcd << "\n";
		forn(i, gcd)
			cout << s << q << s1;
	}
	else
	{
		string s = "", s1 = "";
		forn(i, n)
		{
			a[i] /= gcd;
			forn(j, a[i])
				s.psh('a' + i);
		}
		s1 = s;
		reverse(all(s1));
		cout << gcd << "\n";
		forn(i, gcd / 2)
			cout << s << s1;
	}
	return 0;
}