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

const int MAXN = 105;

int dp[MAXN][3 * MAXN][3 * MAXN], lef[MAXN][MAXN][3 * MAXN], b[MAXN][3 * MAXN], leftX[MAXN], x[MAXN], rightX[MAXN];
pii a[MAXN];
vi v;

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    scanf("%d", &n);
    forn (i, n)
    {
        scanf("%d%d", &a[i].fs, &a[i].sc);
        v.pb(a[i].fs - a[i].sc);
        v.pb(a[i].fs);
        v.pb(a[i].fs + a[i].sc);
    }
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    sort(a, a + n);
    int sz = sz(v);
    forn (i, n)
    {
        leftX[i] = lower_bound(all(v), a[i].fs - a[i].sc) - v.begin();
        x[i] = lower_bound(all(v), a[i].fs) - v.begin();
        rightX[i] = lower_bound(all(v), a[i].fs + a[i].sc) - v.begin();
    }
    forn (l, n)
        forn (r, n)
            forn (i, sz)
                lef[l][r][i] = -1;
    forn (l, n)
    {
        forn (r, n)
            forn (i, sz)
                forn (j, sz)
                    dp[r][i][j] = -1;
        dp[l][x[l]][x[l]] = leftX[l];
        dp[l][rightX[l]][rightX[l]] = x[l];
        forab (r, l, n - 1)
            forn (i, sz)
                forn (j, sz)
                    if (dp[r][i][j] != -1)
                    {
                        int leftEnd = 0, rightEnd = 0, rightLeftEnd = 0;
                        leftEnd = min(dp[r][i][j], leftX[r + 1]);
                        rightEnd = max(i, x[r + 1]);
                        if (leftX[r + 1] > j)
                            rightLeftEnd = j;
                        else
                            //rightLeftEnd = x[r + 1];
                            rightLeftEnd = rightEnd;
                        if (dp[r + 1][rightEnd][rightLeftEnd] == -1 || dp[r + 1][rightEnd][rightLeftEnd] > leftEnd)
                            dp[r + 1][rightEnd][rightLeftEnd] = leftEnd;
                        leftEnd = min(dp[r][i][j], x[r + 1]);
                        rightEnd = max(i, rightX[r + 1]);
                        if (x[r + 1] > j)
                            rightLeftEnd = j;
                        else
                            rightLeftEnd = max(rightEnd, rightX[r + 1]);
                        if (dp[r + 1][rightEnd][rightLeftEnd] == -1 || dp[r + 1][rightEnd][rightLeftEnd] > leftEnd)
                            dp[r + 1][rightEnd][rightLeftEnd] = leftEnd;
                    }    
        forab (r, l, n)
            forn (i, sz)
                if (dp[r][i][i] != -1)
                    lef[l][r][i] = dp[r][i][i];
    }
    /*
    forn (l, n)
        forn (r, n)
            forn (i, sz)
                if (lef[l][r][i] != -1)
                    printf("left[%d][%d][%d] = %d\n", l, r, v[i], v[lef[l][r][i]]);
    */
    int ans = 0;
    forn (i, n)
        forn (j, sz)
        {
            forn (g, i)
                forn (k, j)
                    if (lef[g + 1][i][j] > k && b[g][k] + v[j] - v[lef[g + 1][i][j]] > b[i][j])
                        b[i][j] = b[g][k] + v[j] - v[lef[g + 1][i][j]];
            forn (g, i + 1)
                if (lef[g][i][j] != -1)
                    b[i][j] = max(b[i][j], v[j] - v[lef[g][i][j]]);
            ans = max(ans, b[i][j]);
            //printf("b[%d][%d] = %d\n", i, v[j], b[i][j]);
        }
    printf("%d\n", ans);
    return 0;
}