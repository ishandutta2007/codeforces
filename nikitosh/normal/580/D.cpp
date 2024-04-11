#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end() 

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

const int MAXN = 19;

int a[MAXN], b[MAXN][MAXN];
LL dp[(1 << MAXN)][MAXN];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    forn (i, n)
        scanf("%d", &a[i]);
    forn (i, k)
    {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        x--, y--;
        b[x][y] = c;
    }    
    forn (mask, (1 << n))
    {
        forn (i, n)
            if ((mask >> i) & 1)
            {
                int mask2 = mask ^ (1 << i);
                int was = 0;
                forn (j, n)
                    if ((mask2 >> j) & 1)
                    {
                        was = 1;
                        dp[mask][i] = max(dp[mask][i], dp[mask2][j] + b[j][i] + a[i]);    
                    }
                if (!was)
                    dp[mask][i] = a[i];
            } 
    }
    LL ans = 0;
    forn (mask, (1 << n))
    {
        int cnt = 0;
        forn (j, n) 
            if ((mask >> j) & 1)
                cnt++;
        if (cnt == m)
            forn (j, n)
                ans = max(ans, dp[mask][j]);
    }
    printf(I64 "\n", ans);
    return 0;
}