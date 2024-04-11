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

#define FNAME "1"
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

int n, l, r, q1, q2, a[100005], sum[100005], sum2[100005], tmp, ans = (int) 1e9;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d%d%d%d", &n, &l, &r, &q1, &q2);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (i != 0)
			sum[i] = sum[i - 1];
		sum[i] += a[i];
	}
	sum2[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
		sum2[i] = sum2[i + 1] + a[i];
	for (int i = 0; i <= n; i++)
	{
		tmp = 0;
		if (i != 0)
			tmp += sum[i - 1] * l;
		tmp += sum2[i] * r;
		if (i > n - i)
			tmp += (i - (n - i) - 1) * q1;
		if (n - i > i)
			tmp += (n - 2 * i - 1) * q2;
		ans = min(ans, tmp);	 
	}
	printf("%d\n", ans);
	return 0;
}