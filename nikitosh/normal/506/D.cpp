#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<map>
 
using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif
 
#define FNAME "1"

int n, m, a[100005], b[100005], c[100005], num, used[100005], q, k, l;
set <int> List[100005];
vector <pair <int, int> > d[100005], ans[100005];
map <pair <int, int>, int> Map;

void dfs (int v, int col)
{
	used[v] = 1;
	int pos = lower_bound(d[v].begin(), d[v].end(), mp(col, -1)) - d[v].begin();
    for (int i = pos; i < (int) d[v].size(); i++)
    {
    	if (d[v][i].first != col)
    		break;
		if (used[d[v][i].second] == 0)
			dfs(d[v][i].second, col);
	}
	ans[v].pb(mp(col, num));
}

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		a[i]--;
		b[i]--;
		c[i]--;
		List[c[i]].insert(a[i]);
		List[c[i]].insert(b[i]);
		d[a[i]].pb(mp(c[i], b[i]));
		d[b[i]].pb(mp(c[i], a[i]));
   	} 
   	for (int i = 0; i < n; i++)
   		sort(d[i].begin(), d[i].end());
   	for (int i = 0; i < m; i++)
   	{
   		num = 0;
   		for (set<int>::iterator it = List[i].begin(); it != List[i].end(); it++)
   			if (used[*it] == 0)
   			{
   				dfs(*it, i);	
   				num++;
   			}
   		for (set<int>::iterator it = List[i].begin(); it != List[i].end(); it++)
   			used[*it] = 0;
   	}
   	scanf("%d", &q);
   	for (int i = 0; i < q; i++)
   	{
   		scanf("%d%d", &k, &l);
   		k--;
   		l--;
   		if (ans[l].size() < ans[k].size())
   				swap(k, l);
   		if (Map.count(mp(k, l)) != 0)
   			printf("%d\n", Map[mp(k, l)]);
   		else
   		{
   			int res = 0;
   			for (int j = 0; j < (int) ans[k].size(); j++)
   				if (*lower_bound(ans[l].begin(), ans[l].end(), ans[k][j]) == ans[k][j])
   					res++;
   			Map[mp(k, l)] = res;
        	printf("%d\n", res);
		}
   	}
    return 0;
}