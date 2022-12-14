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

const int MAXL = 20, mod = 1e9+7;

int timer = 0, n, k, l, w, q, used[100005], ans, tin[100005], tout[100005]; 
long long sz[100005], dist[100005], distsq[100005], updist[100005], updistsq[100005], two[100005][20], twodist[100005][20];
vector <long long> d[100005];
vector <int> c[100005];

void dfs (int v, int p = 0, int w = 0)
{
	tin[v] = timer++;
	sz[v] = 1;
	used[v] = 1;
	two[v][0] = p;
	twodist[v][0] = w; 
	for (int i = 1; i < MAXL; i++)
	{
		twodist[v][i] = (twodist[v][i - 1] + twodist[two[v][i - 1]][i - 1]) % mod;
		two[v][i] = two[two[v][i - 1]][i - 1];
	}
	for (int i = 0; i < (int) c[v].size(); i++)
		if (used[c[v][i]] == 0)
		{
			dfs(c[v][i], v, d[v][i]);
			sz[v] += sz[c[v][i]];
			dist[v] = (dist[v] + dist[c[v][i]] + sz[c[v][i]] * d[v][i]) % mod;
			distsq[v] = (distsq[v] + distsq[c[v][i]] + 2 * d[v][i] * dist[c[v][i]] + d[v][i] * ((d[v][i] * sz[c[v][i]]) % mod)) % mod;
		}
	tout[v] = timer++;
}

void dfs2 (int v)
{
	used[v] = 1;
	for (int i = 0; i < (int) c[v].size(); i++)
		if (used[c[v][i]] == 0)
		{
			updist[c[v][i]] = ((updist[v] + dist[v] - (dist[c[v][i]] + sz[c[v][i]] * d[v][i]) + (n - sz[c[v][i]]) * d[v][i]) % mod + mod) % mod;
			long long l = ((updistsq[v] + distsq[v] - (distsq[c[v][i]] + 2 * d[v][i] * dist[c[v][i]] + d[v][i] * ((d[v][i] * sz[c[v][i]]) % mod))) % mod + mod) % mod;
			updistsq[c[v][i]] = ((l - d[v][i] * ((d[v][i] * (n - sz[c[v][i]])) % mod) + 2 * d[v][i] * updist[c[v][i]]) % mod + mod) % mod;
			dfs2(c[v][i]);
		}
}

bool upper (int v, int u)
{
	return (tin[v] <= tin[u] && tout[v] >= tout[u]);
}

int lca (int a, int b)
{
	int res = 0;
	if (a == b)
		return 0;
	if (upper(a, b))
	{
		for (int i = MAXL - 1; i >= 0; i--)
			if (!upper(two[b][i], a))
			{
				res = (res + twodist[b][i]) % mod;
				b = two[b][i];
			}
		return (res + twodist[b][0]) % mod;
	}
	if (upper(b, a))
	{
		for (int i = MAXL - 1; i >= 0; i--)
			if (!upper(two[a][i], b))
			{
				res = (res + twodist[a][i]) % mod;
				a = two[a][i];
			}
		return (res + twodist[a][0]) % mod;
	}
	for (int i = MAXL - 1; i >= 0; i--)
		if (!upper(two[a][i], b))
		{
			res = (res + twodist[a][i]) % mod;
			a = two[a][i];
		}
	for (int i = MAXL - 1; i >= 0; i--)
		if (!upper(two[b][i], a))
		{
			res = (res + twodist[b][i]) % mod;
			b = two[b][i];
		}
	return ((res + twodist[a][0]) % mod + twodist[b][0]) % mod;
}

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d%d", &k, &l, &w);
		k--;
		l--;
		c[k].pb(l);
		c[l].pb(k);
		d[k].pb(w);
		d[l].pb(w);			
   	} 
   	dfs(0);
   	for (int i = 0; i < n; i++)
   		used[i] = 0;
   	dfs2(0);
   	for (int i = 0; i < n; i++)
   		used[i] = 0;
   	scanf("%d", &q);
   	for (int qq = 0; qq < q; qq++)
   	{
		scanf("%d%d", &k, &l);
		k--;
		l--;
		long long x = lca(k, l);
		
		if (upper(l, k))
			ans = ((((distsq[k] + updistsq[k] - 2 * (updistsq[l] + x * (x * (n - sz[l]) % mod) + 2 * x * updist[l])) % mod) + mod) % mod) % mod;
		else
			ans = ((2 * (x * ((x * sz[l]) % mod) + distsq[l] + 2 * x * dist[l]) - (distsq[k] + updistsq[k])) % mod + mod) % mod;
		
		printf("%d\n", ans);
   	}
    return 0;
}