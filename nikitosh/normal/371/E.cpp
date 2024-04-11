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

int n, k, l;
long long sum[300005], ans[300005], t, min1 = (long long) 8e18;
pair <long long, int> a[300005];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", &t);
		a[i] = mp(t, i + 1);
	}
	sort(a, a + n);
	sum[0] = a[0].first;
	for (int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + a[i].first; 
	scanf("%d", &k);
	t = 1 - k;
	for (int i = 0; i < k; i++)
	{
		ans[0] += t * a[i].first;
		t += 2;
	}
	for (int i = 1; i <= n - k; i++)
		ans[i] = ans[i - 1] - 2 * (sum[i + k - 2] - sum[i - 1]) + (k - 1) * (a[i + k - 1].first + a[i - 1].first);
	for (int i = 0; i <= n - k; i++)
		if (ans[i] < min1)
		{
			min1 = ans[i];
			l = i;
		}
	for (int i = 0; i < k; i++)
		printf("%d ", a[l + i].second);
	return 0;
}