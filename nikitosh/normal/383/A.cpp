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

int n, a[400005], sum1[400005], sum2[400005];
long long ans = 0;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
   		sum1[i] = sum1[i - 1];
   		sum2[i] = sum2[i - 1];
   		if (a[i] == 0)
   			sum1[i]++;
   		else
   			sum2[i]++;
   	} 
	for (int i = n; i >= 1; i--)
	{
		if (a[i] == 0)
			ans += sum2[i - 1];			
    }
	printf("%I64d\n", ans);
	return 0;
}