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
const double EPS = (double)1e-8;

int dp[MAXN][MAXN];
vi a;

int zap(int x, int y)
{
	if (y - x == 0)
		return 1;
	if (y - x == 1)
		return (int)(a[x] != a[y]) + 1;
	if (dp[x][y] != 0)
		return dp[x][y];
	int min1 = INF;
	if (a[x] == a[y])
		min1 = zap(x + 1, y - 1);
	for (int i = x; i < y; i++)
		min1 = min(min1, zap(x, i) + zap(i + 1, y));
	return dp[x][y] = min1;
}

int main()
{
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	a.resize(n);
	forn(i, n)
		cin >> a[i];
	cout << zap(0, n - 1);
	return 0;
}