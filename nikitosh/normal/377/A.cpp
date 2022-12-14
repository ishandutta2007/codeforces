#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cassert>

using namespace std;

#define FNAME ""
#define FILE 0

#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define LD long double

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

int n, m, t, a[505][505], h[505][505], used[505][505], x, y, height, turn[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char s[1005];
vector < pair <int, int> > v;

bool foo (int k, int l)
{
	if (k < 0 || k >= n || l < 0 || l >= m)
		return 0;
	if (a[k][l] == 1)
		return 0;
	return 1;
}

void dfs (int k, int l)
{
	used[k][l] = 1;
	h[k][l] = height++;
	for (int g = 0; g < 4; g++)
		if (foo(k + turn[g][0], l + turn[g][1]) && used[k + turn[g][0]][l + turn[g][1]] == 0)
			dfs(k + turn[g][0], l + turn[g][1]);
	used[k][l] = 2;
	height--;
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d%d\n", &n, &m, &t);
	for (int i = 0; i < n; i++)
	{
		gets(s);
		for (int j = 0; j < m; j++)
			if (s[j] == '.')
			{
				a[i][j] = 0;
				x = i;
				y = j;
			}
			else
				a[i][j] = 1;
	}
	dfs(x, y);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 0)
				v.pb(mp(h[i][j], i * m + j));
	sort(v.begin(), v.end());
	for (int i = (int) v.size() - 1; i >= (int) v.size() - t; i--)
		a[v[i].second / m][v[i].second % m] = 2;		
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0)
				printf(".");
			if (a[i][j] == 1)
				printf("#");
			if (a[i][j] == 2)
				printf("X");
		}
		puts("");
	}
	return 0;
}