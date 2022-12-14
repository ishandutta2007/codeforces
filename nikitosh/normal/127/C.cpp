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

const double eps = 1e-8;
double t1, t2, t0, l, ans = 1e18, t;
int x1, x2, l1, l2;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%lf%lf%d%d%lf", &t1, &t2, &x1, &x2, &t0);
	if (t0 == t2)
	{
		if (t0 == t1)
			printf("%d %d\n", x1, x2);
		else
			printf("%d %d\n", 0, x2);
		return 0;
	}
	for (int i = 0; i <= x1; i++)
	{
		l = (double) i * (t0 - t1) / (t2 - t0);
		long long k = (int) ceil(l);
		if (i == 0 && k == 0)
			k = x2;
		if (k <= x2)
		{
			t = (t1 * (double) i + t2 * (double) k) / (double) (i + k);
			if (ans > t + eps || (abs(ans - t) <= eps && k + i > l1 + l2))
			{
				ans = t;
				l1 = i;
				l2 = k;
			}
		}
	}
	printf("%d %d\n", l1, l2);
	return 0;
}