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

const int MAXN = 1e5 + 5;

int used[MAXN], cnt[MAXN];
vector <int> g[MAXN];
int flag;

void dfs(int v, int color)
{
    used[v] = color;
    cnt[color]++;
    for (int to : g[v])
    {
        if (used[to] == used[v])
            flag = 1;
        if (used[to] == 0)
            dfs(to, 3 - color);
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
    if (m == 0)
    {
        printf("3 %I64d\n", n * 1ll * (n - 1) * 1ll * (n - 2) / 6);
        return 0;
    }
    forn (i, m)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        g[v].pb(u);
        g[u].pb(v);
    }
    bool one = 1;
    forn (i, n)
        if ((int) g[i].size() > 1)
            one = 0;
    if (one)
    {
        printf("2 %I64d\n", m * 1ll * (n - 2));
        return 0;
    }
    LL ans = 0;
    forn (i, n)
        if (!used[i])
        {
            cnt[1] = cnt[2] = 0;
            dfs(i, 1);
            ans += cnt[1] * 1ll * (cnt[1] - 1) / 2;
            ans += cnt[2] * 1ll * (cnt[2] - 1) / 2;
        }
    if (flag)
    {
        puts("0 1\n");
        return 0;
    }
    printf("1 %I64d\n", ans);
    return 0;
}