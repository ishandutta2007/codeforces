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

const int mod = 1e9 + 7;

int n, k, x[100005];
vector <int> c[100005];
long long d[100005][3];

long long mul (long long a, int n)
{
 	if (n == 0)
 		return 1;
 	if (n % 2 == 1)
 		return (a * mul(a, n - 1)) % mod;
 	long long b = mul(a, n / 2);
 	return (b * b) % mod;	
}

void dfs (int v)
{
	for (int i = 0; i < (int) c[v].size(); i++)
		dfs(c[v][i]);
	if (x[v] == 1)
	{
		d[v][2] = 0;
		d[v][1] = 1;
		for (int i = 0; i < (int) c[v].size(); i++)
			d[v][1] = (d[v][1] * (d[c[v][i]][1] + d[c[v][i]][2])) % mod;
	}
	else
	{
		d[v][2] = 1;
		for (int i = 0; i < (int) c[v].size(); i++)
			d[v][2] = (d[v][2] * (d[c[v][i]][1] + d[c[v][i]][2])) % mod;
		d[v][1] = 0;
		for (int i = 0; i < (int) c[v].size(); i++)
		{
			d[v][1] = (d[v][1] + ((d[v][2] * mul((d[c[v][i]][1] + d[c[v][i]][2]) % mod, mod - 2)) % mod * d[c[v][i]][1]) % mod) % mod;
		}
	}
}

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d", &k);
		c[k].pb(i + 1);
   	} 
   	for (int i = 0; i < n; i++)
   		scanf("%d", &x[i]);
   	dfs(0);
   	printf("%I64d\n", d[0][1]);
    return 0;
}