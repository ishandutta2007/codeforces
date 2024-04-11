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

long double x;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	cin >> x;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			//printf("%lf\n", x * x * (4 * i * i + j * j) - i * i * j * j);
			if (abs(x * x * (4 * i * i + j * j) - i * i * j * j) < 1e-2)
			{
				printf("%d %d\n", j, i);
				return 0;
			}
		}
	return 0;
}