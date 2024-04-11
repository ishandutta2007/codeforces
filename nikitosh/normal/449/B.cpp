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

const long long INF = 1e18;

int n, m, k, a, b, st[400005], fin[400005], w[400005], ANS, v, used[100005];
vector <int> c[100005], c2[100005];
set < pair <long long, int> > s;
long long d[100005], ans[100005];

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &st[i], &fin[i], &w[i]);
   		st[i]--;
   		fin[i]--;
   		c[st[i]].pb(fin[i]);
   		c2[st[i]].pb(w[i]);
   		c[fin[i]].pb(st[i]);
   		c2[fin[i]].pb(w[i]);
   	} 
   	for (int i = 0; i < n; i++)
    	d[i] = INF;
    d[0] = 0;
    for (int i = 0; i < k; i++)
   	{
   		scanf("%d%d", &a, &b);
   		a--;
   		d[a] = min(d[a], (long long) b);
   	}
    for (int i = 0; i < n; i++)
    	s.insert(mp(d[i], i));
    for (int i = 0; i < n; i++)
    {
    	v = s.begin()->second;
    	s.erase(s.begin());
    	for (int j = 0; j < (int) c[v].size(); j++)
    		if (d[c[v][j]] >= d[v] + c2[v][j])
    		{
    			used[c[v][j]] = 1;
    			s.erase(mp(d[c[v][j]], c[v][j]));
    			d[c[v][j]] = d[v] + c2[v][j];
    			s.insert(mp(d[c[v][j]], c[v][j]));
    		}
    }
    for (int i = 1; i < n; i++)
    	if (used[i] == 0)
    		ANS++;
    printf("%d\n", k - ANS);
    return 0;
}