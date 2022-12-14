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

int n, N, K, mod = (int) 1e9 + 7, used[2005];
long long a[2005], d[4005][4005];

long long foo (int n, int k)
{
	if (k < 2)
		return d[n][k];
	if (d[n][k] != 0)
		return d[n][k];
	if (d[n][k - 1] == 0)
		d[n][k - 1] = foo(n, k - 1);
	if (d[n + 1][k - 2] == 0)
		d[n + 1][k - 2] = foo(n + 1, k - 2);
	d[n][k] = ((n * d[n][k - 1]) % mod + ((k - 1) * d[n + 1][k - 2]) % mod) % mod;
	return d[n][k];
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", &a[i]);
		if (a[i] != -1)
			used[a[i]] = 1;
	}
	long long tmp = 1;
	for (int i = 1; i <= 2 * n; i++)
	{
		tmp = (tmp * i) % mod;
		d[i][0] = tmp;
		d[i][1] = (tmp * i) % mod;
	}
	for (int i = 1; i <= n; i++)
	{
		if (used[i] == 1)
			continue;
		if (a[i - 1] != -1)
			N++;
		else
			K++;
  	}                        
 	printf("%I64d\n", foo(N, K));
	return 0;
}