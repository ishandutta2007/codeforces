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

const int MAXN = 2e5 + 5, INF = 1e9;

int used[MAXN], was[MAXN], dp[MAXN], a[MAXN];
pii deep[MAXN];
pair <int, pii> ans[MAXN];
vi g[MAXN];

void dfs(int v, int p)
{
    ans[v] = mp(-INF, mp(-1, -1));
    deep[v] = mp(-INF, -1);
    if (used[v])
        deep[v] = mp(0, -v);
    pii max1 = deep[v], max2 = mp(-INF, -1);
    for (int u : g[v])
        if (u != p)
        {
            dfs(u, v);   
            //printf("%d %d\n", u, deep[u].fs);
            if (ans[v] < ans[u])
                ans[v] = ans[u];
            if (deep[u].fs >= 0)
                deep[v] = max(deep[v], mp(deep[u].fs + 1, deep[u].sc));
            max2 = max(max2, mp(deep[u].fs + 1, deep[u].sc));
            if (max2 > max1)
                swap(max1, max2); 
        }
    if (max2.fs >= 0)
        ans[v] = max(ans[v], mp(max1.fs + max2.fs, mp(max(max1.sc, max2.sc), min(max1.sc, max2.sc))));
}

void dfs2(int v, int p)
{
    dp[v] = -INF;
    if (used[v])
        dp[v] = 0, was[v] = 1;
    for (int u : g[v])
        if (u != p)
        {
            dfs2(u, v);
            if (was[u])
                was[v] = 1;
            if (dp[u] >= 0)
                dp[v] = max(dp[v], dp[u] + 1);
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
    forn (i, n - 1)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--, u--;
        g[v].pb(u), g[u].pb(v);
    } 
    forn (i, m)
        scanf("%d", &a[i]), used[a[i] - 1] = 1;
    if (m == 1)
    {
        printf("%d\n0\n", a[0]);
        return 0;
    }
    dfs(0, -1);
    int u = -ans[0].sc.fs;
    dfs2(u, -1);
    int cnt = 0;
    forn (i, n)
        if (i != u && was[i])
            cnt++;
    cnt *= 2;
    cnt -= dp[u];
    printf("%d\n%d\n", u + 1, cnt);
    return 0;
}