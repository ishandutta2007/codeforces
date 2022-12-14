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

int n, m, k, a[100005], t, l;
long long sum = 0;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d%d", &k, &a[i]);
	sort(a, a + m);
	for (int i = 1; i <= n + 10; i++)
	{
		if (i == 2)
			l = 2;
		l = i * (i - 1) / 2 + 1;
		if (i % 2 == 0)
			l += (i - 2) / 2;
		if (l <= n)
			t = i;
		if (l > (int) 1e7)
			break;
	}
	for (int i = m - 1; i >= max(0, m - t); i--)
		sum += a[i];
	printf("%I64d\n", sum);
	return 0;
}