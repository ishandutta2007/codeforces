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

long long q, n, m, x_0, y_0, x_1, y_1, t, v, a[1005][1005], b[1005][1005], c[1005][1005], d[1005][1005];

void add2 (int x_0, int y_0, long long v)
{
	long long ta = v;
	long long tb = ((y_0 + 1) % 2) * v;
	long long tc = ((x_0 + 1) % 2) * v;
	long long td = (((x_0 + 1) * (y_0 + 1)) % 2) * v;
	for (int i = x_0; i < n; i |= (i + 1))
		for (int j = y_0; j < n; j |= (j + 1))
		{
			a[i][j] ^= ta;
			b[i][j] ^= tb; 
			c[i][j] ^= tc;
			d[i][j] ^= td;		
		}
}

void add (int x_0, int y_0, int x_1, int y_1, long long v)
{
	add2(x_0, y_0, v);
	add2(x_0, y_1 + 1, v);
	add2(x_1 + 1, y_0, v);
	add2(x_1 + 1, y_1 + 1, v);	
}

long long sum2 (int x_0, int y_0)
{
	long long ta = 0, tb = 0, tc = 0, td = 0;
	for (int i = x_0; i >= 0; i = (i & (i + 1)) - 1)
		for (int j = y_0; j >= 0; j = (j & (j + 1)) - 1)
		{
			ta ^= a[i][j];
			tb ^= b[i][j];
			tc ^= c[i][j];
			td ^= d[i][j];
		}
	//printf("%I64d %I64d %I64d %I64d\n", ta, tb, tc, td);
	//printf("aaa = %I64d\n", (ta * ((x_0 * y_0) % 2)) ^ (tb * (x_0 % 2)) ^ (tc * (y_0 % 2)) ^ td);
	return (ta * ((x_0 * y_0) % 2)) ^ (tb * (x_0 % 2)) ^ (tc * (y_0 % 2)) ^ td;
}               

long long sum (int x_0, int y_0, int x_1, int y_1)
{
	return sum2(x_1, y_1) ^ sum2(x_0 - 1, y_0 - 1) ^ sum2(x_0 - 1, y_1) ^ sum2(x_1, y_0 - 1);
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%I64d%I64d", &n, &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%I64d%I64d%I64d%I64d%I64d", &t, &x_0, &y_0, &x_1, &y_1);
		x_0--;
		y_0--;
		x_1--;
		y_1--;
		if (t == 2)
		{
			scanf("%I64d", &v);
	   		add(x_0, y_0, x_1, y_1, v);
	   	}
	   	else
	   		printf("%I64d\n", sum(x_0, y_0, x_1, y_1));
	}
    return 0;
}