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

int n, m, a[5005][5005], d[5005][5005], used[5005], len, ans = -1;
char s[5005];

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
			a[i][j] = s[j] - '0';
		scanf("\n");
	}
	for (int i = 0; i < n; i++)
	{
	    d[i][m] = m;
		for (int j = m - 1; j >= 0; j--)
	    	if (a[i][j] == 0)
	    		d[i][j] = j;
	    	else
	    		d[i][j] = d[i][j + 1];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j <= m; j++)
			used[j] = 0;
		for (int j = 0; j < n; j++)
			used[d[j][i]]++;
	    len = n;
	    for (int j = i; j < m; j++)
		{
			len -= used[j];
			ans = max(ans, len * (j - i + 1));					
		}
	}
	printf("%d\n", ans);
	return 0;
}