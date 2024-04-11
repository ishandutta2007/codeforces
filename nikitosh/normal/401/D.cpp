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

int m, used[20], b[20], d[20], cnt;
long long n, dp[300005][101];

void gen (int k)
{
	if (k == 10)
	{
		//printf("%d\n", cnt);
		int boo = 0;
		for (int i = 1; i < k; i++)
		{
			if (b[i] > 1)
				boo = 1;			
		}
		if (boo == 0 && b[0] > 1)
			return;
		//puts("AA");
		for (int i = 0; i < k; i++)
			if (b[i] != used[i] + 1)
			{
				for (int j = 0; j < m; j++)
				{
			    	//printf("%d %d %I64d\n", cnt + d[i], cnt, dp[cnt]);
					dp[cnt + d[i]][(10 * j + i) % m] += dp[cnt][j];
				}
			}
		return;
	}
	cnt -= d[k];
	for (int i = 0; i <= used[k]; i++)
	{
		cnt += d[k];
		b[k]++; 
		gen(k + 1);
	}
	cnt -= d[k] * used[k];
	b[k] = 0;
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%I64d%d", &n, &m);
	while (n > 0)
	{
		used[n % 10]++;
		n /= 10;
	} 
	dp[0][0] = 1;
	d[9] = 1;
	for (int i = 8; i >= 0; i--)
	{
		d[i] = d[i + 1] * (used[i + 1] + 1);
		//printf("d = %d\n", d[i]);
	}
	gen(0);
	printf("%I64d\n", dp[d[0] * (used[0] + 1) - 1][0]);
	return 0;
}