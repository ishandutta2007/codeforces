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

int n, m, a[100005], g;
long long ans;

void foo (int k)
{
	while(k <= m)
	{
		ans += m - k;
		k *= 2;
	}
}

int gcd (int k, int l)
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
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	g = a[0] - 1;
	for (int i = 1; i < n; i++)
		g = gcd(g, a[i] - 1);
	for (int i = 1; i * i <= g; i++)
		if (g % i == 0)
		{
			if (i % 2 == 1)
				foo(i);
			if ((g / i) % 2 == 1 && i * i != g)
				foo(g / i);
	    }	
	printf("%I64d\n", ans);
	return 0;
}