#include <bits/stdc++.h> 

using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;

#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#define FNAME "1"

int n, x_0, y_0, x[1005], y[1005], used[1005];

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    int ans = 0;
	scanf("%d%d%d", &n, &x_0, &y_0);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);    
		x[i] -= x_0;
		y[i] -= y_0;
	}
    for (int i = 0; i < n; i++)
    	if (used[i] == 0)
    	{
    		for (int j = 0; j < n; j++)
    			if (y[i] * x[j] == y[j] * x[i])
    				used[j] = 1;
    		ans++;	
    	}
    printf("%d\n", ans);
    return 0;
}