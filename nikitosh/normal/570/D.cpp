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

const int MAXN = 5e5 + 5;

int used[MAXN], tin[MAXN], tout[MAXN], h[MAXN];
int timer = 0, height = 1, maxx = 0;
vector <vector <int> > sum[MAXN];
vector <pii> lst[MAXN + 5];
vi g[MAXN];
char s[MAXN];

void dfs(int v)
{
    used[v] = 1;
    tin[v] = timer++;
    h[v] = height++;
    maxx = max(maxx, height);
    lst[h[v]].pb(mp(tin[v], v));
    for (int u : g[v])
        if (!used[u])
            dfs(u);
    tout[v] = timer++;
    height--;
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, q;
    scanf("%d%d", &n, &q);
    forn (i, n - 1)
    {
        int k;
        scanf("%d", &k);
        g[k - 1].pb(i + 1);
    } 
    scanf("\n");
    gets(s);
    dfs(0);                                                                         
    forab (i, 1, maxx + 1)
    {
        sum[i].resize(sz(lst[i]));
        forn (j, sz(lst[i]))
        {
            sum[i][j].resize(26);
            if (j != 0)
                forn (g, 26)
                    sum[i][j][g] = sum[i][j - 1][g]; 
            sum[i][j][s[lst[i][j].sc] - 'a'] = 1 ^ sum[i][j][s[lst[i][j].sc] - 'a'];
        }
    }
    forn (qq, q)
    {
        int v, hi;
        scanf("%d%d", &v, &hi);
        if (hi > maxx)
        {
            puts("Yes");
            continue;
        }
        v--;
        int l = lower_bound(all(lst[hi]), mp(tin[v], -1)) - lst[hi].begin();
        int r = upper_bound(all(lst[hi]), mp(tout[v], -1)) - lst[hi].begin();
        l--, r--;
        int cnt = 0, sum1 = 0, sum2 = 0;
        forn (g, 26)
        {
            if (r < 0)
                sum1 = 0;
            else   
                sum1 = sum[hi][r][g];
            if (l < 0)
                sum2 = 0;
            else   
                sum2 = sum[hi][l][g];
            if ((sum1 ^ sum2) == 1)
                cnt++;
        }
        if (cnt >= 2)
            puts("No");
        else
            puts("Yes");
    }
    return 0;
}