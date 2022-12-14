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

int n, k, q, a[5005], was[10000005], s;

int main() {
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        was[a[i]]++;
    }
    scanf("%d", &q);
    for (int qq = 0; qq < q; qq++)
    {
        scanf("%d", &s);
        int ans = 1e9;
        //cerr << s << endl;
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= k; j++)
            {
                int t = s - j * a[i];
                if (t == 0)
                    ans = min(ans, j);
                if ( t < 0)
                    break;
                for (int g = 1; g <= k - j; g++)
                    if (t % g == 0 && t / g <= 1e7 && was[t / g])
                        ans = min(ans, j + g); 
            }
        if (ans == 1e9)
            ans = -1;
        printf("%d\n", ans);
    } 
    return 0;
}