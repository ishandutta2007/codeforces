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

int k, n[5], t[5], l1, ans;
multiset <int> r[5];

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d%d%d%d%d%d%d", &k, &n[0], &n[1], &n[2], &t[0], &t[1], &t[2]);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < n[j]; i++)
			r[j].insert(0);
   	for (int i = 0; i < k; i++)
   	{
   		l1 = max(*r[0].begin(), max(*r[1].begin() - t[0], *r[2].begin() - t[0] - t[1]));
   		r[0].erase(r[0].begin());
   		r[1].erase(r[1].begin());
   		r[2].erase(r[2].begin());
   		r[0].insert(l1 + t[0]);
   		r[1].insert(l1 + t[0] + t[1]);
   		r[2].insert(l1 + t[0] + t[1] + t[2]);
   		ans = max(ans, l1 + t[0] + t[1] + t[2]);
   	}
   	printf("%d\n", ans);
	return 0;
}