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

int n, k, l1, l2, ans, used[3005][3005], d[3005][3005], head, tail, v1, v2, p[3005];
pair <int, int> q[10000005];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	l1 = -1;
	l2 = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
		if (p[i] == 100)
			l1 = i;
		if (p[i] != 0)
			l2 = i;
	}
	q[tail++] = mp(0, 1);
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= n + 1; j++)
			d[i][j] = (int) 1e9;
	d[0][1] = 0;
	while(tail - head > 0)
	{
		v1 = q[head].first;
		v2 = q[head++].second;
		if (d[v1][v2] > k)
			continue;
		used[v1][v2] = 1;
		if (v2 >= n)
			continue;
		if (l2 >= v2 && p[v1] != 0 && d[v2 + 1][v2 + 2] == (int) 1e9)
		{
			q[tail++] = mp(v2 + 1, v2 + 2);
			d[v2 + 1][v2 + 2] = d[v1][v2] + 1;
		}
		if (l2 >= v2 && p[v1] != 100 && d[v2][v2 + 1] == (int) 1e9)
		{
			q[tail++] = mp(v2, v2 + 1);
			d[v2][v2 + 1] = d[v1][v2] + 1;
		}
		if (p[v1] != 0 && l1 < v2 && d[v1][v2 + 1] == (int) 1e9)			
		{
			q[tail++] = mp(v1, v2 + 1);
			d[v1][v2 + 1] = d[v1][v2] + 1;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (used[i][j])
				ans++;
	for (int i = 0; i < n; i++)
		if (used[i][n])
			ans++;
	if (used[n][n + 1])
		ans++;
	printf("%d\n", ans);
	return 0;
}