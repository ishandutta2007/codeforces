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

int T, sz;
long long n, f[100], a[100];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	f[0] = 1;
	f[1] = 2;
	sz = 1;
	while(f[sz] < (long long) 1e18)
		f[sz + 1] = f[sz] + f[sz - 1], sz++;
	scanf("%d", &T);
	for (int g = 0; g < T; g++)
	{
		long long dp1 = 1, dp2 = 0, s;
		int cnt = 0;
		scanf("%I64d", &n);
		for (int i = sz; i >= 0; i--)
			if (n >= f[i])
			{
				a[i] = 1;
				n -= f[i];
			}
			else
				a[i] = 0;
		for (int i = 0; i <= sz; i++)
			if (a[i])
			{
				s = dp1 + dp2;
				dp2 = cnt / 2 * dp1 + (cnt + 1) / 2 * dp2;
				dp1 = s;
				cnt = 0;
			}
			else
				cnt++;
		printf("%I64d\n", dp1 + dp2);
	}
	return 0;
}