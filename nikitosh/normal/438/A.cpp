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

int n, m, a[1005], k, l, it, used[1005], ans;
pair <int, int> b[1005];
vector <int> c[1005];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = mp(a[i], i);
	}
	sort(b, b + n);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &k, &l);
		k--;
		l--;
		c[k].pb(l);
		c[l].pb(k);
   	}
   	for (int i = n - 1; i >= 0; i--)
   	{
   		it = b[i].second;
   		used[it] = 1;
   		for (int j = 0; j < (int) c[it].size(); j++)
   	        if (used[c[it][j]] == 0)
	   			ans += a[c[it][j]];
   	}
   	printf("%d\n", ans);
	return 0;
}