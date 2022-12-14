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

int n, k, a[10];

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
	if (a[1] != n / 3 || (a[4] + a[6] != n / 3) || (a[2] + a[3] != n / 3) || a[6] < a[3] || a[2] < a[4])
	{
		puts("-1");
		return 0;
	}
	for (int i = 0; i < a[4]; i++)
	{
		puts("1 2 4");
		a[2]--;
	}
	for (int i = 0; i < a[3]; i++)
		puts("1 3 6");
	for (int i = 0; i < a[2]; i++)
		puts("1 2 6");
	return 0;
}