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

int n, k, l, a[100005], b[100005], d[100005], used[100005];
vector <int> c[100005], ans;

void dfs (int v, int boo1, int boo2)
{
	used[v] = 1;
	int boo3 = boo1;
	if ((d[v] == 1 && boo1 == 0) || (d[v] == 0 && boo1 == 1))
	{
		ans.pb(v);
		boo3 ^= 1;
	}
	for (int i = 0; i < (int) c[v].size(); i++)
		if (used[c[v][i]] == 0)
			dfs(c[v][i], boo2, boo3);
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d", &k, &l);
		k--;
		l--;
		c[k].pb(l);
		c[l].pb(k);
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
		if (b[i] != a[i])
			d[i] = 1;
	}
	dfs(0, 0, 0);
	printf("%d\n", (int) ans.size());
	for (int i = 0; i < (int) ans.size(); i++)
		printf("%d\n", ans[i] + 1);
	return 0;
}