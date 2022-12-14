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

int a[100005], d[100005], n;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	d[0] = -INF;
	for (int i = 1; i <= n; i++)
		d[i] = INF;
	for (int i = 0; i < n; i++) 
	{
		int j = int (upper_bound (d, d + n + 1, a[i]) - d);
		if (d[j - 1] < a[i] && a[i] < d[j])
			d[j] = a[i];
	}
	for (int i = n; i >= 1; i--)
		if (d[i] != INF)
		{
			printf("%d\n", i);
			return 0;
		}
	return 0;
}