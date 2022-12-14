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

int n, m, a[1005][1005], d1[1005][1005], d2[1005][1005], d3[1005][1005], d4[1005][1005], s1, s2, ans;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
	    	scanf("%d", &a[i][j]);
   	for (int i = 1; i <= n; i++)
   		for (int j = 1; j <= m; j++)
   			d1[i][j] = max(d1[i - 1][j], d1[i][j - 1]) + a[i][j];
   	for (int i = n; i >= 1; i--)
   		for (int j = m; j >= 1; j--)
   			d2[i][j] = max(d2[i + 1][j], d2[i][j + 1]) + a[i][j];
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= m; j++)
			d3[i][j] = max(d3[i][j - 1], d3[i + 1][j]) + a[i][j];
   	for (int i = 1; i <= n; i++)
   		for (int j = m; j >= 1; j--)
   			d4[i][j] = max(d4[i - 1][j], d4[i][j + 1]) + a[i][j];
   	for (int i = 2; i < n; i++)
   		for (int j = 2; j < m; j++)
   		{
   			s1 = d1[i][j - 1] + d2[i][j + 1] + d3[i + 1][j] + d4[i - 1][j];
   			s2 = d1[i - 1][j] + d2[i + 1][j] + d3[i][j - 1] + d4[i][j + 1];
   			ans = max(ans, max(s1, s2));
   		}
   	printf("%d\n", ans);
	return 0;
}