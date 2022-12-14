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

int n, k, a[105], sum;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		a[k]++;
	}
	for (int i = 1; i <= 100; i++)
	{
		a[i] /= 2;
		sum += a[i];
	}
	printf("%d\n", sum / 2);
	return 0;
}