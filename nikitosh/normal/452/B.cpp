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

int n, m, sw, l1, l2, l3, l4, sz;
vector <pair <int, int> > ans, ans2;
double sum, max1;

int sqr (int k)
{
	return k * k;
}

double foo (int k, int l)
{
	return sqrt(sqr(ans2[k].first - ans2[l].first) + sqr(ans2[k].second - ans2[l].second));
}

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d%d", &n, &m);
	if (n < m)
	{
		swap(n, m);
		sw = 1;
   	} 
   	if (m == 0)
   	{
   		ans2.pb(mp(1, 0));
   		ans2.pb(mp(n, 0));
   		ans2.pb(mp(0, 0));
   		ans2.pb(mp(n - 1, 0));
   	    sz = (int) ans2.size();
   	  	if (sw)
	   		for (int i = 0; i < sz; i++)
   				swap(ans2[i].first, ans2[i].second);
   		for (int i = 0; i < sz; i++)
			printf("%d %d\n", ans2[i].first, ans2[i].second);
		return 0;
	}
   	ans.pb(mp(0, 0));
   	ans.pb(mp(0, 1));
   	ans.pb(mp(1, 0));
   	ans.pb(mp(0, m));
   	ans.pb(mp(0, m - 1));
   	ans.pb(mp(1, m));
   	ans.pb(mp(n, m));
   	ans.pb(mp(n, m - 1));
   	ans.pb(mp(n - 1, m));
   	ans.pb(mp(n, 0));
   	ans.pb(mp(n, 1));
   	ans.pb(mp(n - 1, 0));
    sz = (int) ans.size();
    sort(ans.begin(), ans.end());
    ans2.pb(ans[0]);
    for (int i = 1; i < sz; i++)
    	if (ans[i] != ans[i - 1])
    		ans2.pb(ans[i]);
    sz = (int) ans2.size();
    for (int i = 0; i < sz; i++)
    	for (int j = 0; j < sz; j++)
    		for (int x = 0; x < sz; x++)
    			for (int y = 0; y < sz; y++)
    			{
    				if (i == j || i == x || i == y || j == x || j == y || x == y)
    					continue;
    				sum = foo(i, j) + foo(j, x) + foo(x, y);
    				if (sum > max1)
    				{
    					max1 = sum;
    					l1 = i;
    					l2 = j;
    					l3 = x;
    					l4 = y;
    				}
    			}
   	if (sw)
   		for (int i = 0; i < sz; i++)
   			swap(ans2[i].first, ans2[i].second);
   	printf("%d %d\n%d %d\n%d %d\n%d %d\n", ans2[l1].first, ans2[l1].second, ans2[l2].first, ans2[l2].second, ans2[l3].first, ans2[l3].second, ans2[l4].first, ans2[l4].second);
    return 0;
}