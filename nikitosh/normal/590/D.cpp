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

const int MAXN = 155, INF = 1e9;

int a[MAXN], dp[MAXN][MAXN * MAXN], dp2[MAXN][MAXN * MAXN];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, k, s, sum = 0;
    scanf("%d%d%d", &n, &k, &s);
    forn (i, n)
        scanf("%d", &a[i]);
    forn (i, k)
        sum += a[i];
    int l = min(k, n - k);
    int cnt = n * (n - 1) / 2;
    forn (g, cnt + 1)
        dp2[0][g] = 0;
    forn (g, cnt + 1)
        forab (j, 1, l + 1)
            dp2[j][g] = INF;
    forn (i, k)
        forba (j, 1, l + 1)
        {
            fornr (g, cnt + 1)
                if (g >= k - 1 - i)
                    dp[j][g] = max(dp[j][g], dp[j - 1][g - (k - 1 - i)] + a[i]);
        }
    //printf("%d\n", dp[2][cnt]);
    forn (i, n - k)
        forba (j, 1, l + 1)
        {
            fornr (g, cnt + 1)
                if (g >= i)
                    dp2[j][g] = min(dp2[j][g], dp2[j - 1][g - i] + a[k + i]);
        }
    int ans = INF;
    forn (m, l + 1)
    {
        if (s >= m * m)
        {
            int s2 = min(2 * cnt, s - m * m);
            forn (i, s2 + 1)
            {
                ans = min(ans, sum - dp[m][min(cnt, i + m * (m - 1) / 2)] + dp2[m][min(cnt, s2 - i + m * (m - 1) / 2)]);
                //printf("%d %d %d %d\n", ans,  sum,                              dp[m][min(cnt, i + m * (m - 1) / 2)],        dp2[m][min(cnt, s2 - i + m * (m - 1) / 2)]);
            }
        }
    }    
    printf("%d\n", ans);
    return 0;
}