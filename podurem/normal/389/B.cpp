
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
#define TASK ""

const int INF = (int)1e9 + 7;
const int MAXN = (int)1e5 + 7;
const double EPS = (double)1e-8;

int n;

bool ss(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < n;
}

int main()
{
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	vector <vector <char> > a(n, vector <char>(n));
	forn(i, n)
		forn(j, n)
			cin >> a[i][j];
	forn(i, n)
		forn(j, n)
		{
			if (a[i][j] == '#')
			{
				a[i][j] = '.';
				if (ss(i + 1, j - 1))
					if (a[i + 1][j - 1] == '#')
						a[i + 1][j - 1] = '.';
					else
					{
						cout << "NO";
						return 0;
					}
				else
				{
					cout << "NO";
					return 0;
				}
				if (ss(i + 1, j))
					if (a[i + 1][j] == '#')
						a[i + 1][j] = '.';
					else
					{
						cout << "NO";
						return 0;
					}
				else
				{
					cout << "NO";
					return 0;
				}
				if (ss(i + 1, j + 1))
					if (a[i + 1][j + 1] == '#')
						a[i + 1][j + 1] = '.';
					else
					{
						cout << "NO";
						return 0;
					}
				else
				{
					cout << "NO";
					return 0;
				}
				if (ss(i + 2, j))
					if (a[i + 2][j] == '#')
						a[i + 2][j] = '.';
					else
					{
						cout << "NO";
						return 0;
					}
				else
				{
					cout << "NO";
					return 0;
				}
			}
		}
	cout << "YES";
	return 0;
}