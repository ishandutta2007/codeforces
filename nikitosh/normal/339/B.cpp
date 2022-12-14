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

int n, m, a[100005];
long long sum;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	a[0] = 1;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] >= a[i - 1])
			sum += a[i] - a[i - 1];
		else
			sum += a[i] + n - a[i - 1];
	}
	printf("%I64d\n", sum);	
	return 0;
}