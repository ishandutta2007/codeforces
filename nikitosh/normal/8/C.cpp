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

const int INF = (int) 1e9;

int x_0, y_0, n, x[30], y[30], N, dp[17000000], l;
pair <int, int> pr[17000000];

int dist (int k, int l)
{
	return (x[k] - x[l]) * (x[k] - x[l]) + (y[k] - y[l]) * (y[k] - y[l]);
}

int dist0 (int k)
{
	return x[k] * x[k] + y[k] * y[k];
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d%d", &x_0, &y_0, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		x[i] -= x_0;
		y[i] -= y_0;
	}
	N = 1 << n;
	for (int i = 0; i < n; i++)
	{
		dp[1 << i] = 2 * dist0(i);
		pr[1 << i] = mp(i, -1);
	}
	//for (int i = 0; i < n; i++)
	//	for (int j = i + 1; j < n; j++)
	//		dp[(1 << i) + (1 << j)] = min(dp[1 << i] + dp[1 << j], dist0(i) + dist0(j) + dist(i, j));
	for (int i = 1; i < N; i++)
	{
		if (dp[i] != 0)
			continue;
		dp[i] = INF;
	   	for (int j = 0; j < n; j++)
			if ((i & (1 << j)) != 0)
			    if (dp[i] > dp[i - (1 << j)] + 2 * dist0(j))
			    {
					dp[i] = dp[i - (1 << j)] + 2 * dist0(j);
					pr[i] = mp(j, -1);	    			
	    		}
		for (int j = 0; j < n; j++)
			if ((i & (1 << j)) != 0)
			{
				l = j;
				break;
			}
		for (int j = 0; j < n; j++)
			if (l != j && (i & (1 << j)) != 0)
			    if (dp[i] > dp[i - (1 << j) - (1 << l)] + dist0(j) + dist0(l) + dist(l, j))
			    {
					dp[i] = dp[i - (1 << j) - (1 << l)] + dist0(j) + dist0(l) + dist(l, j);
					pr[i] = mp(l, j);
				}
		//printf("%d %d %d\n", i, dp[i], pr[i].first);
	}
	l = N - 1;
	printf("%d\n", dp[l]);
	printf("0 ");
	while (l != 0)
	{
		//printf("l = %d\n", l);
		if (pr[l].second == -1)
		{
			printf("%d 0 ", pr[l].first + 1);
			l -= (1 << pr[l].first);
		}
		else
		{
			printf("%d %d 0 ", pr[l].first + 1, pr[l].second + 1);
			l = l - (1 << pr[l].first) - (1 << pr[l].second);
		}
		//printf("l = %d\n", l);
	}	
	return 0;
}