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

int n, m, N, used[1000005], l, d[1000005], ans;
char a[1005][1005];
vector <int> c[1000005], top;

bool foo (char c1, char c2)
{
	if (c1 == 'D' && c2 == 'I')
		return 1;
	if (c1 == 'I' && c2 == 'M')
		return 1;
	if (c1 == 'M' && c2 == 'A')
		return 1;
	if (c1 == 'A' && c2 == 'D')
		return 1;
	return 0;
}

void edge (int k, int l)
{
	if (k > 0 && foo(a[k][l], a[k - 1][l]))
		c[k * m + l].pb((k - 1) * m + l);
	if (l > 0 && foo(a[k][l], a[k][l - 1]))
		c[k * m + l].pb(k * m + l - 1);
	if (k < n - 1 && foo(a[k][l], a[k + 1][l]))
		c[k * m + l].pb((k + 1) * m + l);
	if (l < m - 1 && foo(a[k][l], a[k][l + 1]))
		c[k * m + l].pb(k * m + l + 1);
}

void dfs (int v)
{
	//printf("%d %d\n", v / m + 1, v % m + 1);
	used[v] = 1;
	for (int i = 0; i < (int) c[v].size(); i++)
	{
	    if (used[c[v][i]] == 1)
	    {
			puts("Poor Inna!");
			exit(0);	    	
	    }
		if (used[c[v][i]] == 0)
			dfs(c[v][i]);
	}
	used[v] = 2;
	top.pb(v);
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
		for (int j = 0; j < m; j++)
			scanf("%c", &a[i][j]);
		scanf("\n");
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			edge(i, j);
	N = n * m;
	for (int i = 0; i < N; i++)
		if (used[i] == 0)
			dfs(i);
	for (int i = 0; i < N; i++)
	{
		l = top[i];
		for (int j = 0; j < (int) c[l].size(); j++)
			d[l] = max(d[l], d[c[l][j]] + 1);
		if (a[l / m][l % m] == 'D')
			ans = max(ans, (d[l] + 1) / 4);
		//printf("%d %d\n", l, d[l]);
	}
    if (ans == 0)
		puts("Poor Dima!");
	else
		printf("%d\n", ans);
	return 0;
}