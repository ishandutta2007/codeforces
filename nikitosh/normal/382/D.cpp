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

const int turn[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int n, m, a[2005][2005], used[2005][2005], xx, yy, d[2005][2005], len = -1, dx, dy, dk, dl, ii, jj;
char s[4005];
vector < pair <int, int> > top;

bool foo (int p, int q, int k, int l)
{
	if (p < 0 || q < 0 || p >= n || q >= m)
		return 0;
	if (a[p][q] == -1)
		return 0;
	if (p + turn[a[p][q]][0] == k && q + turn[a[p][q]][1] == l)
		return 1;
	return 0;
}

void dfs2 (int k, int l)
{
	used[k][l] = 1;
   	for (int g = 0; g < 4; g++)
   	{
   	    dx = k + turn[g][0], dy = l + turn[g][1];
  	    if (foo(dx, dy, k, l) && used[dx][dy] == 0)
  			dfs2(dx, dy);
	}
}

void dfs (int k, int l)
{
    used[k][l] = 1;
	if (a[k][l] == -1)
	{
		used[k][l] = 2;
		top.pb(mp(k, l));
		return;
	}
	dk = k + turn[a[k][l]][0], dl = l + turn[a[k][l]][1];
  	if (dk >= 0 && dk < n && dl >= 0 && dl < m && used[dk][dl] == 1)
	{
  		puts("-1");
  		exit(0);
  	}
	if (dk >= 0 && dk < n && dl >= 0 && dl < m && used[dk][dl] == 0)
		dfs(dk, dl);
	used[k][l] = 2;	
	top.pb(mp(k, l));
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; i++)
	{
		gets(s);
		for (int j = 0; j < m; j++)
		{
			a[i][j] = -1;
		    if (s[j] == '>')
		    	a[i][j] = 0;
			if (s[j] == 'v')
		    	a[i][j] = 1;
			if (s[j] == '<')
		    	a[i][j] = 2;
			if (s[j] == '^')
		    	a[i][j] = 3;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (used[i][j] == 0)
				dfs(i, j);
	assert((int) top.size() == n * m);
	for (int i = 0; i < n * m; i++)
	{
		ii = top[i].first, jj = top[i].second;
       	for (int g = 0; g < 4; g++)
       	{
       	    dx = ii + turn[g][0], dy = jj + turn[g][1];
       		if (foo(dx, dy, ii, jj))
       		{
       			d[dx][dy] = max(d[dx][dy], d[ii][jj] + 1); 
       		}
		}
	}
	len = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (d[i][j] > len)
			{
				len = d[i][j];
				xx = i;
				yy = j;
			}
		}
	if (len == 0)
	{
		puts("0");
		return 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			used[i][j] = 0;
	top.clear();
	dfs(xx, yy);
	int sz = top.size();
	assert(sz >= len);
	xx = top[sz - len].first, yy = top[sz - len].second;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			used[i][j] = 0;
	dfs2(xx, yy);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (d[i][j] == len && used[i][j] == 0)
			{
				printf("%d\n", 2 * len);
				return 0;
			}
	printf("%d\n", max(0, 2 * len - 1));
	return 0;
}