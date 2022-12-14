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

const int MAXN = 1e5 + 5, MAXK = 18, MAXCNT = 10;

int tin[MAXN], tout[MAXN], up[MAXN][MAXK], a[MAXN][MAXK][MAXCNT + 1], size[MAXN][MAXK], buf[MAXN], buf2[MAXN];
int timer = 0;
vi g[MAXN];
set <int> s[MAXN];

void dfs(int v, int p)
{
    tin[v] = timer++;
    forab (i, 1, MAXK)
    {
        up[v][i] = up[up[v][i - 1]][i - 1];
        if (up[v][i - 1] == 0)
        {
            size[v][i] = size[v][i - 1];
            forn (j, size[v][i])
                a[v][i][j] = a[v][i - 1][j];
        }
        else
        {
            merge(a[v][i - 1], a[v][i - 1] + size[v][i - 1], a[up[v][i - 1]][i - 1], a[up[v][i - 1]][i - 1] + size[up[v][i - 1]][i - 1], buf);
            size[v][i] = min(MAXCNT, size[v][i - 1] + size[up[v][i - 1]][i - 1]);
            forn (j, size[v][i])
                a[v][i][j] = buf[j];
        }
    }
    for (auto u : g[v])
        if (u != p)
        {
            up[u][0] = v;
            dfs(u, v);
        }
    tout[v] = timer++;
}

bool isAncestor(int v, int u)
{
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}

int lca(int v, int u)
{
    fornr (i, MAXK)
        if (!isAncestor(up[v][i], u))
            v = up[v][i];
    if (isAncestor(v, u))
        return v;
    return up[v][0];
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    forn (i, n - 1)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--, u--;
        g[v].pb(u);
        g[u].pb(v);
    } 
    forn (i, m)
    {
        int l;
        scanf("%d", &l);
        l--;
        s[l].insert(i + 1);
    }
    forn (i, n)
    {
        auto it = s[i].begin();
        forn (j, min(sz(s[i]), MAXCNT))
            a[i][0][j] = *it++;
        size[i][0] = min(sz(s[i]), MAXCNT);
    }
    dfs(0, -1);
    forn (qq, q)
    {
        int v, u, k;
        scanf("%d%d%d", &v, &u, &k);
        v--, u--;
        int w = lca(v, u);
        //printf("%d %d %d\n", v, u, w);
        int curSz = 0;
        fornr (i, MAXK)
            if (!isAncestor(up[v][i], w) || (up[v][i] == w && v != w))
            {
                //printf("curSz = %d\n", up[v][i]);
                merge(buf2, buf2 + curSz, a[v][i], a[v][i] + size[v][i], buf);
                curSz = min(MAXCNT, curSz + size[v][i]);
                forn (j, curSz)
                    buf2[j] = buf[j];
                v = up[v][i];
            }
        //printf("curSz = %d\n", curSz);
        fornr (i, MAXK)
            if (!isAncestor(up[u][i], w) || (up[u][i] == w && u != w))
            {
                merge(buf2, buf2 + curSz, a[u][i], a[u][i] + size[u][i], buf);
                curSz = min(MAXCNT, curSz + size[u][i]);
                forn (j, curSz)
                    buf2[j] = buf[j];
                u = up[u][i];
            }
        //printf("curSz = %d\n", curSz);
        merge(buf2, buf2 + curSz, a[w][0], a[w][0] + size[w][0], buf);
        curSz = min(MAXCNT, curSz + size[w][0]);
        //printf("curSz = %d\n", curSz);
        forn (j, curSz)
            buf2[j] = buf[j];
        curSz = min(curSz, k);
        printf("%d ", curSz);
        forn (j, curSz)
            printf("%d ", buf2[j]);
        puts("");
    }

    return 0;
}