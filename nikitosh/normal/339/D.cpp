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

int n, d[1000005], v[2000005], a[1000005], p, b, t, m;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &t, &m);
	n = 1 << t;
	for (int i = 1; i < 2 * n; i++)
		for (int j = 1; j < 20; j++)
			if (i < (1 << j))
			{
				d[i] = (t - j + 1) % 2;
				break;
			}
	for (int i = 0; i < n; i++)
		scanf("%d", &v[n + i]);
	for (int i = n - 1; i >= 1; i--)
	{
		if (d[2 * i] == 0)
		{
			v[i] = v[2 * i] | v[2 * i + 1];
		}
		else
		{
			v[i] = v[2 * i] ^ v[2 * i + 1];
		}
		//printf("%d\n", v[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &p, &b);
		p += n - 1;
		v[p] = b;
		while(p > 0)
		{
			p /= 2;
			if (d[2 * p] == 0)
				v[p] = v[2 * p] | v[2 * p + 1];
			else
				v[p] = v[2 * p] ^ v[2 * p + 1];
	    }
	    printf("%d\n", v[1]);
	}
	return 0;
}