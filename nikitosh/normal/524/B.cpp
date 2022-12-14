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

int n, w[1005], h[1005];
LL ANS = 1e9 + 5;

int main() {
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &w[i], &h[i]);
    } 
    for (int i = 1; i <= 1000; i++)
    {
        int boo = 1;
        for (int j = 0; j < n; j++)
            if (w[j] > i && h[j] > i)
                boo = 0;
        if (boo == 0)
            continue;
        LL sum = 0;
        for (int j = 0; j < n; j++)
        {
            int ans = 1e9;
            if (w[j] <= i)
                ans = h[j];
            if (h[j] <= i)
                ans = min(ans, w[j]);    
            sum += ans;
            //printf("%d %d\n", i, ans);
        }
        ANS = min(ANS, sum * i);
    }
    printf("%I64d\n", ANS);
    return 0;
}