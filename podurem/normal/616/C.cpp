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

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define mk make_pair
#define psh push_back
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK ""

const int INF = (int)1e9 + 7;
const int MAXN = (int)1e3 + 7;
const double EPS = (double)1e-7;

char c[MAXN][MAXN];
pii a[MAXN][MAXN];
char USED[MAXN][MAXN];
int k = 0, aa;
vector <pii> v;

void dfs(int x, int y)
{
	aa++;
	USED[x][y] = 1;
	for (int dx = -1; dx <= 1; ++dx)
		for (int dy = -1; dy <= 1; ++dy)
			if ((dx == 0 || dy == 0) && !USED[x + dx][y + dy] && c[x + dx][y + dy] == '.')
				dfs(x + dx, y + dy);
	v.psh(mk(x, y));
}

int main()
{
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	forn(i, n + 2)
	{
		c[i][0] = '*';
		c[i][m + 1] = '*';
	}
	forn(i, m + 2)
	{
		c[0][i] = '*';
		c[n + 1][i] = '*';
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> c[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (!USED[i][j] && c[i][j] == '.')
			{
				v.resize(0);
				k++;
				aa = 0;
				dfs(i, j);
				forn(k1, v.size())
					a[v[k1].first][v[k1].second] = mk(k, aa);
			}
	set <pii> s;
	int ans;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			if (c[i][j] == '.')
				cout << '.';
			else
			{
				ans = 0;
				s.clear();
				for (int dx = -1; dx <= 1; ++dx)
					for (int dy = -1; dy <= 1; ++dy)
						if ((dx == 0 || dy == 0) && c[i + dx][j + dy] == '.')
							s.insert(a[i + dx][j + dy]);
				for (auto it = s.begin(); it != s.end(); ++it)
					ans += (*it).second;
				cout << (ans + 1) % 10;
			}
		cout << "\n";
	}
	return 0;
}