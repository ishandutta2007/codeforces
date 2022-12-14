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

int n, k, ans[1000005], a1, a2;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	if (n < 3 * k)
	{
		puts("-1");
		return 0;
	}
	for (int i = 0; i < k - 2; i++)
		ans[2 * i] = ans[2 * i + 1] = ans[n - i - 1] = i + 1;
	a1 = 2 * (k - 2);
	a2 = n - (k - 2) - 1;
	ans[a1] = ans[a1 + 1] = ans[a2 - 1] = k - 1;
	for (int i = 0; i < n; i++)
	{
		if (ans[i] == 0)
			ans[i] = k;
		printf("%d ", ans[i]);
	}
	return 0;
}