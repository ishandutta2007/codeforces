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

#define FNAME "1"
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

int n, m, t[20005], l[20005], r[20005], c[20005], b[20005], max1[20005], max2[20005], max3[20005];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d%d", &t[i], &l[i], &r[i], &c[i]);
		l[i]--;
		r[i]--;
    }
	for (int i = 0; i < n; i++)
		max1[i] = (int) 1e9;
	for (int i = 0; i < m; i++)
	{
		if (t[i] == 1)
			for (int j = l[i]; j <= r[i]; j++)
				b[j] += c[i];
		else
		{
			for (int j = l[i]; j <= r[i]; j++)
				max1[j] = min(max1[j], c[i] - b[j]);
		}
	}
	for (int i = 0; i < m; i++)
		max3[i] = -(int) 1e9;
	for (int i = 0; i < n; i++)
		max2[i] = max1[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (l[j] <= i && i <= r[j])
			{
				if (t[j] == 1)
					max2[i] += c[j];			
				else
					max3[j] = max(max3[j], max2[i]);
			}
		}
	}
	for (int i = 0; i< m; i++)
		if (t[i] == 2 && max3[i] != c[i])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	for (int i = 0; i < n; i++)
		printf("%d ", max1[i]);
	return 0;
}