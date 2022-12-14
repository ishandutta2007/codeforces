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

int n, m, k, w, min1[1005], res, ans, sel[1005], c[1005][1005], used[1005];
char s[105], t[1005][105];
vector < pair <int, int > > ANS;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d%d%d\n", &n, &m, &k, &w);
	for (int g = 0; g < k; g++)
	{
		for (int i = 0; i < n; i++)
		{
        	gets(s);
        	for (int j = 0; j < m; j++)
        		t[g][i * m + j] = s[j];
		}
		for (int i = 0; i < g; i++)
		{
			res = 0;
			for (int x = 0; x < n; x++)
				for (int y = 0; y < m; y++)
					if (t[g][x * m + y] != t[i][x * m + y])
						res++;
			c[i + 1][g + 1] = res * w;
			c[g + 1][i + 1] = res * w;
		} 
		c[g + 1][0] = n * m;
		c[0][g + 1] = n * m;
	}
	k++;
	for (int i = 0; i < k; i++)
	{
		min1[i] = 1e9;
		sel[i] = -1;
	}
	min1[0] = 0;
	for (int i = 0; i < k; i++)
	{
		int v = -1;
		for (int j = 0; j < k; j++)
			if (used[j] == 0 && (v == -1 || min1[j] < min1[v]))
				v = j;
		used[v] = 1;
		if (sel[v] != -1)
		{
		    ANS.pb(mp(v, sel[v]));
			ans += min1[v];
		}
		for (int j = 0; j < k; j++)
			if (c[v][j] < min1[j])
			{
				min1[j] = c[v][j];
				sel[j] = v;
			}
	}
	printf("%d\n", ans);
	for (int i = 0; i < k - 1; i++)
		printf("%d %d\n", ANS[i].first, ANS[i].second);
	return 0;
}