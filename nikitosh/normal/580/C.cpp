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

const int MAXN = 1e5 + 5;

int was[MAXN], len[MAXN], a[MAXN];
vi g[MAXN];

void dfs(int v, int pr, int m, int &ans)
{
    if (pr != -1)
    {
        was[v] = was[pr];
        len[v] = len[pr];
    }
    if (a[v])
        len[v]++;
    else
        len[v] = 0;
    if (len[v] > m)
        was[v] = 1;
    //printf("%d %d %d\n", v, len[v], was[v]);
    for (int u : g[v])
        if (u != pr)
            dfs(u, v, m, ans);
    if (v != 0 && sz(g[v]) == 1 && !was[v])
        ans++;
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, m;
    scanf("%d%d", &n, &m);
    forn (i, n)
        scanf("%d", &a[i]);
    forn (i, n - 1)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--, u--;
        g[v].pb(u), g[u].pb(v);
    } 
    int ans = 0;
    dfs(0, -1, m, ans);
    printf("%d\n", ans);
    return 0;
}