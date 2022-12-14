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

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

int used[MAXN], col[MAXN];
vector <int> c[MAXN], d[MAXN], e[MAXN];

void dfs(int v, int color)
{
    used[v] = 1;
    col[v] = color;
    for (int to : c[v])
        if (!used[to])
            dfs(to, color);
}

void dfs2(int v, int color)
{
    used[v] = color;
    for (int to : e[v])
    {
        if (used[to] != 0 && used[to] == used[v])
        {
            puts("0");
            exit(0);
        } 
        if (used[to] == 0)
            dfs2(to, 3 - color);
    }
}


int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, m;
    scanf("%d%d", &n, &m);
    forn (i, m)
    {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        v--;
        u--;
        if (w)
        {
            c[v].pb(u);
            c[u].pb(v);
        }
        else
        {
            d[v].pb(u);
            d[u].pb(v);
        }
    }
    int color = 0;
    for (int i = 0; i < n; i++)
        if (used[i] == 0)
            dfs(i, color), color++;
    for (int i = 0; i < n; i++)
        for (int to : d[i])
            if (col[i] == col[to])
            {
                puts("0");
                return 0;
            }
    for (int i = 0; i < n; i++)
        for (int to : d[i])
        {
            e[col[i]].pb(col[to]);
            e[col[to]].pb(col[i]);
        }
    for (int i = 0; i < n; i++)
        used[i] = 0;
    int cnt = 0;
    for (int i = 0; i < color; i++)
        if (used[i] == 0)
            dfs2(i, 1), cnt++;
    int ans = 1;
    for (int i = 0; i < cnt - 1; i++)
        ans = (2 * ans) % MOD;
    printf("%d\n", ans);
    return 0;
}