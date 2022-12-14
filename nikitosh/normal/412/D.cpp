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

int n, m, a[100005], b[100005], boo, ans[30005], it;
set <int> c[30005];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
		a[i]--;
		b[i]--;
		c[a[i]].insert(b[i]);
	}
	for (int i = 1; i < n; i++)
	{
		boo = 0;
		it = 0;
		if (c[ans[i - 1]].count(i) == 0)
		{
			ans[i] = i;
			continue;
		}
		for (int j = i - 1; j > 0; j--)
			if (c[ans[j - 1]].count(i) == 0 && c[i].count(ans[j]) == 0)
			{
				it = j;
		        boo = 1;
				break;
			}
		for (int j = i; j > it; j--)
			ans[j] = ans[j - 1];
		ans[it] = i;
		//printf("%d\n", it);
	}
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i] + 1);
	return 0;
}