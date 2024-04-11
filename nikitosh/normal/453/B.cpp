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

const int INF = 1e9;

int n, L, tmp, sz, a[105], d[105][66000], min1, ind, k, pr[105][66000], q[105];
vector <int> ans, v[105];
int p[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};


int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	L = 1 << 16;
	for (int i = 1; i < 60; i++)
	{
		for (int j = 0; j < 16; j++)
			if (i % p[j] == 0)
				v[i].pb(j);
		q[i] = 0;
		for (int j = 0; j < (int) v[i].size(); j++)
			q[i] |= (1 << v[i][j]);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < L; j++)
		{
			d[i][j] = INF;
			for (int g = 1; g < 60; g++)
			{
				if ((j & q[g]) != q[g])
					continue;
				if (i == 1 && j != q[g])
					continue;
				if (d[i][j] > d[i - 1][j ^ q[g]] + abs(g - a[i]))
				{
					d[i][j] = d[i - 1][j ^ q[g]] + abs(g - a[i]);
					pr[i][j] = g;
				}	
			}
            //printf("%d %d\n", j, pr[i][j]);
		}
   	//printf("%d\n", pr[1][11]);
	min1 = INF;
	for (int i = 0; i < L; i++)
		if (min1 > d[n][i])
		{
			min1 = d[n][i];
			ind = i;
		}
	k = n;
	while (k > 0)
	{
		ans.pb(pr[k][ind]);
		//cerr << ind << endl;
		ind = ind ^ q[pr[k][ind]];
		k--;
	}
	for (int i = (int) ans.size() - 1; i >= 0; i--)
		printf("%d ", ans[i]);
	return 0;
}