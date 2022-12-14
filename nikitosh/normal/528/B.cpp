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

const int INF = 2e9+10;

int n, d[200005], l, ans;
pair <int, int> a[200005];

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i].first, &a[i].second);
    sort(a, a + n);
    d[0] = -INF;
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    for (int i = 0; i < n; i++)
    {
        l = upper_bound(d, d + n + 1, a[i].first - a[i].second) - d - 1;
        d[l + 1] = min(d[l + 1], a[i].first + a[i].second);
    }   
    for (int i = 0; i <= n; i++)
        if (d[i] != INF)
            ans = i;
    printf("%d\n", ans);
    return 0;
}