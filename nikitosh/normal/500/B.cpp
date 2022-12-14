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

int n, p[1005], ans[1005], used[1005];
char s[1005];
vector <int> c[1005], res, tmp;

void dfs (int v)
{
	used[v] = 1;
	tmp.pb(v);
	for (int i = 0; i < (int) c[v].size(); i++)
		if (used[c[v][i]] == 0)
			dfs(c[v][i]);
}

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	scanf("\n");
	for (int i = 0; i < n; i++)
	{
		gets(s);
		for (int j = 0; j < n; j++)
			if (s[j] == '1')
				c[i].pb(j);	
   	} 
   	for (int g = 0; g < n; g++)
   		if (used[g] == 0) 
   		{
			tmp.clear();
			dfs(g);
			res.resize(tmp.size());
			for (int i = 0; i < (int) tmp.size(); i++)
				res[i] = p[tmp[i]];
			sort(res.begin(), res.end());
			sort(tmp.begin(), tmp.end());
			for (int i = 0; i < (int) tmp.size(); i++)
				ans[tmp[i]] = res[i];
   		}
   	for (int i = 0; i < n; i++)
   		printf("%d ", ans[i]);
    return 0;
}