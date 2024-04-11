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

int type[MAXN], pr[MAXN], cnt[MAXN];
vi g[MAXN], g2[MAXN];

void dfs(int v, int p = -1)
{
    pr[v] = p;
    for (int u : g[v])
        if (u != p)
            dfs(u, v);
    for (int u : g[v])
        if (u != p)
            g2[v].pb(u);
    if (sz(g2[v]) == 0)
    {
        type[v] = 1;
        return;
    }
    if (sz(g2[v]) == 1 && type[g2[v][0]] == 1)
    {
        type[v] = 1;
        return;
    }
    if (sz(g2[v]) == 2 && type[g2[v][0]] == 1 && type[g2[v][1]] == 1)
    {
        type[v] = 2;
        return;
    }
    type[v] = 3;
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    scanf("%d", &n);
    forn (i, n - 1)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--, u--;
        g[v].pb(u), g[u].pb(v);
    }    
    dfs(0);
    forn (i, n)
        if (i != 0 && type[i] == 3)
            cnt[pr[i]]++;
    int v = 0;
    forn (i, n)
        if (i != 0 && cnt[i] > 1)
            v = i;
    forn (i, n)
        g2[i].clear(), cnt[i] = 0;
    dfs(v);
    forn (i, n)
        if (i != v && type[i] == 3)
            cnt[pr[i]]++;
    forn (i, n)
        if ((i == v && cnt[i] > 2) || (i != v && cnt[i] > 1))
        {
            puts("No");
            return 0;
        }
    puts("Yes");
    return 0;
}