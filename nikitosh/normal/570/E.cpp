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

const int MAXN = 505, MOD = 1e9 + 7;

char s[MAXN][MAXN];

int d[MAXN][MAXN], d2[MAXN][MAXN];

inline int add(int x)
{
    return x >= MOD ? x - MOD : x;
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, m;
    scanf("%d%d\n", &n, &m);
    forn (i, n)
        gets(s[i]);
    int ans = 0;
    forn (i, n)
    {
        forn (j, m)
            fornr(k, n)
            {
                d2[j][k] = 0;
                if (i == 0 && j == 0 && k == n - 1 && s[i][j] == s[k][m - 1])
                {
                    d2[j][k] = 1;
                    continue;
                }
                if (n - 1 - k > i + j)
                    break;
                int l = m - 1 - (i + j - (n - 1 - k));
                if (s[i][j] != s[k][l])
                    continue;
                if (j != 0)
                {
                    if (k != n - 1 && s[i][j - 1] == s[k + 1][l])
                        d2[j][k] = add(d2[j][k] + d2[j - 1][k + 1]);
                    if (l != m - 1 && s[i][j - 1] == s[k][l + 1])
                        d2[j][k] = add(d2[j][k] + d2[j - 1][k]);
                }
                if (i != 0)
                {
                    if (k != n - 1 && s[i - 1][j] == s[k + 1][l])
                        d2[j][k] = add(d2[j][k] + d[j][k + 1]);
                    if (l != m - 1 && s[i - 1][j] == s[k][l + 1])
                        d2[j][k] = add(d2[j][k] + d[j][k]);
                }
            }
        forn (j, m)
            fornr(k, n)
                d[j][k] = d2[j][k];
        if ((n + m) % 2 == 0)
        {
            forn (j, m)
                if (2 * (i + j) == n + m - 2)
                    ans = add(ans + d[j][i]);       
        }
        else
            forn (j, m)
                if (2 * (i + j) == n + m - 3)
                    ans = add(ans + d[j][i]), ans = add(ans + d[j][i + 1]);       
    }
    printf("%d\n", ans);
    return 0;
}