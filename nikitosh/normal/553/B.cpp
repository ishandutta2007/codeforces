#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for ( int i = 0 ; (i) < (n) ; ++i )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; ++it )
 
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAXN = 105;
const LL INF = 1e18 + 1;

int ans[MAXN];
LL f[MAXN];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    LL k;
    scanf("%d%I64d", &n, &k);
    f[0] = 1, f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = (f[i - 1] + f[i - 2]);
        if (f[i] > INF)
            f[i] = INF;
    }
    int pos = 0;
    for (int i = n; i > 0; i--)
    {
        if (k <= f[i - 1])
            ans[pos++] = n - i + 1;
        else
        {
            k -= f[i - 1];
            ans[pos++] = n - i + 2;
            ans[pos++] = n - i + 1;
            i--;
        }
    }
    forn (i, n)
        printf("%d ", ans[i]);
    return 0;
}