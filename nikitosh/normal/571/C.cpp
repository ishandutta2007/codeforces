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

const int MAXN = 4e5 + 5;

int used[MAXN], was[MAXN], ans[MAXN];
vi st, comp, path;
vector <pii> g[MAXN], g2[MAXN], c[MAXN];
vector <pair <int, pii> > edges;

void dfs(int v)
{
    was[v] = 1;
    used[v] = 1;
    for (auto u : g2[v])
        if (!was[u.fs])
        {
            ans[u.sc / 2] = u.sc % 2;
            dfs(u.fs);
        }
}

void searchCycle(int v, int p, bool &wasCycle)
{
    st.pb(v);
    comp.pb(v);
    was[v] = 2;
    bool wasBack = 0;
    for (auto u : g[v])
    {
        if (u.fs == p && !wasBack)
        {
            wasBack = 1;
            continue;
        }
        if (was[u.fs] == 2)
        {
            ans[u.sc / 2] = u.sc % 2;
            fornr (i, sz(st))
            {
                path.pb(st[i]);
                if (st[i] == u.fs)
                    break;
            }
            wasCycle = 1;
            return;
        }
        if (was[u.fs] == 0)
        {
            searchCycle(u.fs, v, wasCycle);
            ans[u.sc / 2] = u.sc % 2;
            if (wasCycle)
                return;
        }
    }
    was[v] = 1;
    st.pop_back();
}

void dfs2(int v)
{
    was[v] = 1;
    for (auto u : g[v])
        if (!was[u.fs])
        {
            ans[u.sc / 2] = u.sc % 2;
            dfs2(u.fs);
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
    forn (i, n)
    {
        int k, l;
        scanf("%d", &k);
        forn (j, k)
        {
            scanf("%d", &l);
            if (l < 0)
                c[abs(l)].pb(mp(i, 0));
            else
                c[l].pb(mp(i, 1));
        }
    }
    forab (i, 1, m + 1)
    {
        if (sz(c[i]) == 0)
            continue;
        if (sz(c[i]) == 1 || c[i][0].sc == c[i][1].sc)
        {
            ans[i] = c[i][0].sc;
            forn (j, sz(c[i]))
                used[c[i][j].fs] = 1;
        }
        else
        {
            if (c[i][0].sc == 1)
                swap(c[i][0], c[i][1]);
            edges.pb(mp(i, mp(c[i][0].fs, c[i][1].fs)));
        }
    }
    for (auto np : edges)
    {
        g2[np.sc.fs].pb(mp(np.sc.sc, 2 * np.fs + 1));
        g2[np.sc.sc].pb(mp(np.sc.fs, 2 * np.fs));
    }
    forn (i, n)
        if (used[i] && !was[i])
            dfs(i); 
    for (auto np : edges)
    {
        if (!used[np.sc.fs] && !used[np.sc.sc])
        {
            //printf("%d %d\n", np.sc.fs, np.sc.sc);
            g[np.sc.fs].pb(mp(np.sc.sc, 2 * np.fs + 1));
            g[np.sc.sc].pb(mp(np.sc.fs, 2 * np.fs));
        }
    }
    forn (i, n)
        if (!was[i])
        {
            bool wasCycle = 0;
            comp.clear();
            st.clear();
            path.clear();
            searchCycle(i, -1, wasCycle);
            if (!wasCycle)
            {
                puts("NO");
                return 0;
            }
            for (int v : comp)
                was[v] = 0;
            for (int v : path)
                was[v] = 1;
            for (int v : path)
                dfs2(v);           
        }
    puts("YES");
    forn (i, m)
        putchar('0' + ans[i + 1]);
    return 0;
}