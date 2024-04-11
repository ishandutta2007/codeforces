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

int n, m, k, l, ans1, ans2;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &l);
		if (l == 1)
			ans1++;
		else
			ans2++;
	}
	if (ans1 <= m)
		printf("%d\n", max(0, n - m - k));
	else
	{
		printf("%d\n", ans1 - m + max(0, ans2 - k));
	}	
	return 0;
}