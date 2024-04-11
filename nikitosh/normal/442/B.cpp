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
double a[1005], s_0, s_1;

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    	scanf("%lf", &a[i]);
    sort(a, a + n);
    s_0 = 1;
    s_1 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
    	if (s_0 * a[i] + s_1 * (1 - a[i]) > s_1)
    	{
    		s_1 = s_0 * a[i] + s_1 * (1 - a[i]);
    		s_0 = s_0 * (1 - a[i]);
    	}	
    }
    printf("%.20lf\n", s_1);
    return 0;
}