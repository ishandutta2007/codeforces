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
                     
long long n, a[100005], sum, ans, g;

long long gcd (long long k, long long l)
{
	if (l == 0)
		return k;
	return gcd(l, k % l);
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%I64d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", &a[i]);
    	sum += a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++)
		ans += (a[i + 1] - a[i]) * (long long) (i + 1) * (long long) (n - i - 1);
	ans *= 2;
	ans += sum;
	g = gcd(ans, n);
	printf("%I64d %I64d\n", ans / g, n / g);
	return 0;
}