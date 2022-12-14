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

int n;
long long a[300005], ans;

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		ans += a[i] * (i + 2);
	ans -= a[n - 1];
	printf("%I64d\n", ans);	    
    return 0;
}