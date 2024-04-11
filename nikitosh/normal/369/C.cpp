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

int n, k, l, t, used[100005], h[100005], height, pr[100005];
vector <int> c[100005], ans;
vector < pair <int, int> > v, tmp; 

void dfs(int v)
{
	used[v] = 1;
	h[v] = height++;
	for (int i = 0; i < (int) c[v].size(); i++)
		if (used[c[v][i]] == 0)
		{
			dfs(c[v][i]);
			pr[c[v][i]] = v;
		}
	height--;
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d%d", &k, &l, &t);
		k--;
		l--;
		c[k].pb(l);
		c[l].pb(k);
		if (t == 2)
			v.pb(mp(k, l));
	}
	dfs(0);
	for (int i = 0; i < n; i++)
		used[i] = 0;
	for (int i = 0; i < (int) v.size(); i++)
		if (h[v[i].first] > h[v[i].second])
			tmp.pb(mp(h[v[i].first], v[i].first));
		else
			tmp.pb(mp(h[v[i].second], v[i].second));
	sort(tmp.begin(), tmp.end());
	for (int i = (int) tmp.size() - 1; i >= 0; i--)
	{
		l = tmp[i].second;
		if (used[l] == 1)
			continue;
		ans.pb(l + 1);
		while (used[l] == 0)
		{
			used[l] = 1;
			l = pr[l];
		}
 	}	
 	printf("%d\n", ans.size());
 	for (int i = 0; i < (int) ans.size(); i++)
 		printf("%d ", ans[i]);
	return 0;
}