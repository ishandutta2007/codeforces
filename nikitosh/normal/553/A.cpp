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

const int MAXN = 1005;
const int MOD = 1e9 + 7;

int c[MAXN + 5][MAXN + 5];
int a[MAXN + 5];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    int sum = 0;
    c[0][0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) 
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
    scanf("%d", &n);
    forn (i, n)
        scanf("%d", &a[i]), sum += a[i];
    int ans = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans = (ans * 1ll * c[sum - 1][a[i] - 1]) % MOD;
        sum -= a[i];
    }
    printf("%d\n", ans);
    return 0;
}