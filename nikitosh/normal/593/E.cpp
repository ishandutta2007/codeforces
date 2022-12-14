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

const int MAXN = 20, MOD = 1e9+7;
const LL INF = 8e18;
const int turn[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int a[MAXN], c[MAXN][MAXN], d[MAXN][MAXN], e[MAXN][MAXN], cc[MAXN][MAXN], res[MAXN][MAXN];
LL a2[MAXN];

inline bool good(int x, int y, int n, int m)
{
    return x >= 0 && y >= 0 && x < n && y < m && c[x][y] == 0;
}

inline int foo(int x, int y, int m)
{
    return x * m + y;
}   

void mul(int aa[MAXN][MAXN], int bb[MAXN][MAXN])
{
    forn (i, MAXN)
        forn (j, MAXN)
            cc[i][j] = bb[j][i];
    forn (i, MAXN)
        forn (j, MAXN)
        {
            LL k = 0;
            forn (g, MAXN)
            {
                k += aa[i][g] * 1ll * bb[j][g];
                if (k > INF)
                    k %= MOD;
            }
            k %= MOD;
            e[i][j] = k;            
        }
}

void power(int aa[MAXN][MAXN], int n)
{
    if (n == 1)
    {
        forn (i, MAXN)
            forn (j, MAXN)
                res[i][j] = aa[i][j];
        return;
    }
    if (n % 2 == 0)
    {
        power(aa, n / 2);
        mul(res, res);
        forn (i, MAXN)
            forn (j, MAXN)
                res[i][j] = e[i][j];
        return;
    }
    power(aa, n / 2);
    mul(res, res);
    forn (i, MAXN)
        forn (j, MAXN)
            res[i][j] = e[i][j];
    mul(aa, res);
    forn (i, MAXN)
        forn (j, MAXN)
            res[i][j] = e[i][j];
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    
    a[0] = 1;
    int lastT = 1;    
    forn (qq, q)
    {
        int type, x, y, t;
        scanf("%d%d%d%d", &type, &x, &y, &t);
        x--, y--;
        forn (i, MAXN)
            forn (j, MAXN)
                d[i][j] = 0;
        forn (i, n)
            forn (j, m)
            {
                forn (g, 4)
                {
                    int x = i + turn[g][0], y = j + turn[g][1];
                    if (good(i, j, n, m) && good(x, y, n, m))
                        d[foo(i, j, m)][foo(x, y, m)] = 1;
                }
                if (good(i, j, n, m))
                    d[foo(i, j, m)][foo(i, j, m)] = 1;
            }
        power(d, t - lastT);
        forn (i, MAXN)
            forn (j, MAXN)
                d[i][j] = res[i][j];
        lastT = t;
        forn (i, MAXN)
            a2[i] = 0;
        forn (i, MAXN)
            forn (j, MAXN)
            {
                a2[i] = (a2[i] + d[i][j] * 1ll * a[j]);             
                if (a2[i] > INF)
                    a2[i] %= MOD;
            }
        forn (i, MAXN)
            a[i] = a2[i] % MOD;
        if (type == 2)
            c[x][y] = 1;
        if (type == 3)
            c[x][y] = 0;
        if (type == 2)
            a[foo(x, y, m)] = 0;
        if (type == 1)
            printf("%d\n", a[foo(x, y, m)]);
        //forn (i, 3)
        //    printf("%d ", a[i]);
        //puts("");
    } 
    return 0;
}