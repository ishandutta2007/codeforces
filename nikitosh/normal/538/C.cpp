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
#define I64 "%I64d"
#else
#define I64 "%lld"
#endif

#define FNAME "1"

const int MAXN = 1e5 + 5;

int n, m;
int h[MAXN], t[MAXN];
int ans;

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d", &t[i], &h[i]);
    ans = max(t[0] + h[0] - 1, n - t[m - 1] + h[m - 1]);
    for (int i = 1; i < m; i++)
    {
        int diff = (t[i] - t[i - 1]) - abs(h[i] - h[i - 1]);
        if (diff < 0)
        {
            puts("IMPOSSIBLE");
            return 0;
        }
        ans = max(ans, max(h[i], h[i - 1]) + diff / 2);
    } 
    printf("%d\n", ans);
    return 0;
}