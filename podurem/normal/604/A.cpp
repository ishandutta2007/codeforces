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
typedef pair<int, int> pii;
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

int solve()
{
	//freopen("std.in", "r", stdin);
	//freopen("std.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	double m1, m2, m3, m4, m5, w1, w2, w3, w4, w5, h1, h2;
	cin >> m1 >> m2 >> m3 >> m4 >> m5;
	cin >> w1 >> w2 >> w3 >> w4 >> w5;
	cin >> h1 >> h2;
	cout << (int)(max(0.3 * 500, (1 - m1 / 250) * 500 - 50 * w1) + max(0.3 * 1000, (1 - m2 / 250) * 1000 - 50 * w2) + max(0.3 * 1500, (1 - m3 / 250) * 1500 - 50 * w3) + max(0.3 * 2000, (1 - m4 / 250) * 2000 - 50 * w4) + max(0.3 * 2500, (1 - m5 / 250) * 2500 - 50 * w5) + 100 * h1 - 50 * h2);
	return 0;
}