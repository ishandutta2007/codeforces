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

int n, w[200005], h[200005], max1, ind, max2, l, sum;

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d", &n);
    for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &w[i], &h[i]);
		sum += w[i];
		if (h[i] > max1)
		{
			max1 = h[i];
			ind = i;
		}
   	} 
    for (int i = 0; i < n; i++)
    	if (i != ind)
    		max2 = max(max2, h[i]);
    for (int i = 0; i < n; i++)
    {
    	if (i == ind)
    		l = max2;
    	else
    		l = max1;
    	printf("%d ", (sum - w[i]) * l);
    }
    return 0;
}