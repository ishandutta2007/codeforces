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

int n, a[105], max1 = 0, g, m;

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
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		max1 = max(max1, a[i]);
	}
	g = a[0];
	for (int i = 1; i < n; i++)
		g = gcd(g, a[i]);
	m = max1 / g;
	if ((m - n) % 2 == 0)
		puts("Bob");
	else
		puts("Alice");
	return 0;
}