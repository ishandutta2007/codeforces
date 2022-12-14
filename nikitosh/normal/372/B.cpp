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

int n, m, a[50][50], d[50][50][50][50], boo[50][50][50][50], q, x, y, z, t;
char s[50];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d%d\n", &n, &m, &q);
	for (int i = 0; i < n; i++)
	{
		gets(s);
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[j] - '0';
			if (s[j] == '0')
				d[i][j][i][j] = 1;
		}
	}
	for (int len1 = 1; len1 <= n; len1++)
		for (int len2 = 1; len2 <= m; len2++)
		{
			for (int i = 0; i <= n - len1; i++)
				for (int j = 0; j <= m - len2; j++)
				{
					if (len1 == 1 && len2 == 1)
					{
						boo[i][j][i][j] = d[i][j][i][j];
						continue;
					}
					if (len1 == 1)
					{
						boo[i][j][i][j + len2 - 1] = boo[i][j][i][j + len2 - 2] & d[i][j + len2 - 1][i][j + len2 - 1];
						continue;
					}
					if (len2 == 1)
					{
						boo[i][j][i + len1 - 1][j] = boo[i][j][i + len1 - 2][j] & d[i + len1 - 1][j][i + len1 - 1][j];
						continue;
					}
					boo[i][j][i + len1 - 1][j + len2 - 1] = boo[i][j][i + len1 - 2][j + len2 - 1] & 
					boo[i][j][i + len1 - 1][j + len2 - 2] & d[i + len1 - 1][j + len2 - 1][i + len1 - 1][j + len2 - 1];
				}
		}
	for (int i = 0; i < n; i++)
	{
		for (int len = 2; len <= m; len++)
			for (int g = 0; g < m - len + 1; g++)
			{
				d[i][g][i][g + len - 1] = d[i][g][i][g + len - 2]; 
				for (int j = g + len - 1; j >= g; j--)
				{
					if (a[i][j] == 1)
						break;
					d[i][g][i][g + len - 1]++;
				}
			}
	}
	for (int len1 = 2; len1 <= n; len1++)
		for (int len2 = 1; len2 <= m; len2++)
			for (int i = 0; i <= n - len1; i++)
				for (int j = 0; j <= m - len2; j++)
				{
					int i2 = i + len1 - 1;
					int j2 = j + len2 - 1;
					d[i][j][i2][j2] = d[i][j][i2 - 1][j2] + d[i + 1][j][i2][j2] - d[i + 1][j][i2 - 1][j2];
					int l1 = j, l2 = j;
					while(l2 <= j2)
					{
						if (boo[i][l1][i2][l2])
							l2++;
						else
						{
							d[i][j][i2][j2] += (l2 - l1) * (l2 - l1 + 1) / 2;
							if (l1 == l2)
								l2++;
							l1 = l2;
						}
					}
					if (boo[i][l1][i2][j2])
						d[i][j][i2][j2] += (j2 - l1 + 1) * (j2 - l1 + 2) / 2;
				}
   	//for (int i = 0; i < n; i++)
	//	for (int i2 = i; i2 < n; i2++)
	//		for (int j = 0; j < m; j++)
	//			for (int j2 = j; j2 < m; j2++)
	//				printf("%d %d %d %d %d\n", i, j, i2, j2, d[i][j][i2][j2]);
	for (int i = 0; i < q; i++)
   	{
   		scanf("%d%d%d%d", &x, &y, &z, &t);
   		x--;
   		y--;
   		z--;
   		t--;
   		printf("%d\n", d[x][y][z][t]);
   	}
	return 0;
}