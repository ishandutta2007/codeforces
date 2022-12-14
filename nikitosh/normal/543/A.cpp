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

const int MAXN = 505;

int d[MAXN][MAXN], d2[MAXN][MAXN], a[MAXN];

int main() 
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
    int n, m, b, mod;
    scanf("%d%d%d%d", &n, &m, &b, &mod);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i <= n; i++)
        d[i][0] = 1;
    for (int i = 1; i <= m; i++)        
    {
        for (int j = 1; j <= n; j++)
            for (int g = 0; g <= b; g++)
            {
                d2[j][g] = 0;
                d2[j][g] = (d2[j][g] + d2[j - 1][g]) % mod;
                if (g >= a[j - 1])
                    d2[j][g] = (d2[j][g] + d[j][g - a[j - 1]]) % mod;
            }
        //printf("new %d %d\n", d2[1][1], 0);
        for (int j = 1; j <= n; j++)
            for (int g = 0; g <= b; g++)
            {
                d[j][g] = d2[j][g];
                //printf("%d %d %d %d\n", i, j, g, d[j][g]);
            }
    }
    int sum = 0;
    for (int i = 0; i <= b; i++)
        sum = (sum + d[n][i]) % mod;
    printf("%d\n", sum);
    return 0;
}