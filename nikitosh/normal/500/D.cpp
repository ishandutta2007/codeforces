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

int N, M, Q, k[100005], l[100005], w[100005], used[100005], sz[100005], num, val, dlt;
vector <int> c[100005], d[100005], e[100005];
long long ans[100005], h[100005], sum;

void dfs(int v)
{
	used[v] = 1;
	sz[v] = 1;
	for (int i = 0; i < (int) c[v].size(); i++)
		if (used[c[v][i]] == 0)
		{
		    dfs(c[v][i]);
		    ans[d[v][i]] = (long long) e[v][i] * (long long) sz[c[v][i]] * (N - sz[c[v][i]]);
		   	h[d[v][i]] = sz[c[v][i]] * (long long) (N - sz[c[v][i]]);
			sz[v] += sz[c[v][i]];
		}
}                     

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d%d%d", &k[i], &l[i], &w[i]);    
    	k[i]--;
    	l[i]--;
    	c[k[i]].pb(l[i]);
    	c[l[i]].pb(k[i]);  
    	d[k[i]].pb(i);
    	d[l[i]].pb(i);
    	e[k[i]].pb(w[i]);
    	e[l[i]].pb(w[i]);
    }
    dfs(0);
    for (int i = 0; i < N - 1; i++)
    	sum += ans[i];
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++)
    {
        scanf("%d%d", &num, &val);
        num--;
        dlt = w[num] - val;
        w[num] = val;
        sum -= (long long) dlt * h[num];
    	printf("%.20lf\n", 6 * sum / (double) ((long long) (N) * (long long) (N-1)));
    }
    return 0;
}