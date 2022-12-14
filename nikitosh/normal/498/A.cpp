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

int x_1, y_1, x_2, y_2, n, a, b, c, ans;
long long sgn1, sgn2;

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d%d%d%d", &x_1, &y_1, &x_2, &y_2);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &a, &b, &c);    
    	sgn1 = x_1 * (long long) a + y_1 * (long long) b + c; 
    	sgn2 = x_2 * (long long) a + y_2 * (long long) b + c; 
		if ((sgn1 > 0 && sgn2 < 0) || (sgn1 < 0 && sgn2 > 0))
			ans++;
    }
    printf("%d\n", ans);
    return 0;
}