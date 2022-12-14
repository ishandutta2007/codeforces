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

int maxx = 0;
vector <pii> g[MAXN];
int used[MAXN];

void dfs(int v, int dist)
{
    used[v] = 1;
    maxx = max(maxx, dist);
    for (auto np : g[v])
        if (!used[np.fs])
            dfs(np.fs, dist + np.sc);
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    scanf("%d", &n);
    LL sum = 0;
    forn (i, n - 1)
    {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        v--, u--;
        sum += 2 * w;
        g[v].pb(mp(u, w));
        g[u].pb(mp(v, w));
    }
    dfs(0, 0);
    printf(I64 "\n", sum - maxx);
    return 0;
}