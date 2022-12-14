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

int n, a[1005][1005], k, ans, q, t;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
		ans += a[i][i];
	ans %= 2;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &t);
		if (t == 1 || t == 2)
		{
			scanf("%d", &k);
			k--;
		    if (a[k][k] == 1)
		    	ans--;
		    else
		    	ans++;
		    a[k][k] ^= 1;
		    ans = (ans + 2) % 2;
			//printf("%d\n\n", ans);
		}
		if (t == 3)
			printf("%d", ans);
	}
	return 0;
}