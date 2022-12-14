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

int a, b, w, x, c, dlt, k1, g_w, g_x, dl, l;
long long ans;

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
	scanf("%d%d%d%d%d", &a, &b, &w, &x, &c);
	if (c <= a)
	{
		puts("0");
		return 0;
	}
	dlt = c - a;
	k1 = b / x;
	if (k1 >= dlt)
	{
		printf("%d\n", dlt);
		return 0;
	}
	ans += k1;
	dlt -= k1;
	b %= x;
	while(b < x)
	{
		b += w - x;
		ans++;
	}
	b -= x;
	ans++;
	dlt--;
	l = w * x / gcd(w, x);
	g_w = l / w;
	g_x = l / x;
	dl = g_x - g_w;
	//printf("%d %d %d %d %d\n", l, g_w, g_x, dlt, dl);
	ans += (long long) (dlt / dl) * (long long) g_x;
	dlt %= dl;
	while(dlt > 0)
	{
		ans++;
		if (b >= x)
		{
			b -= x;
			dlt--;
		}
		else
			b += w - x;
	}
	printf("%I64d\n", ans);
	return 0;
}