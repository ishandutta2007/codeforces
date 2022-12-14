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

const int MAXN = 2e5 + 5;

int used[MAXN], goodDeg[MAXN];
set<pair<double, int> >::iterator iters[MAXN];
vector <int> tmp, c[MAXN];
set <pair <double, int> > s;

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    forn (i, k)
    {
        int v;
        scanf("%d", &v);
        used[v - 1] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;
        u--;
        c[v].pb(u);
        c[u].pb(v);
    }
    forn (i, n)
        for (int to : c[i])
            if (!used[i] && !used[to])
                goodDeg[i]++;
    forn (i, n)
        if (!used[i])
            iters[i] = s.insert(mp(goodDeg[i] / (double) c[i].size(), i)).first;
    int cur = 0;
    double ans = -1;
    while (s.size() != 0)
    {
        int v = (*s.begin()).second;
        double res = (*s.begin()).first;
        if (res > ans)
        {
            ans = res;
            cur = s.size();
        }
        s.erase(s.begin());
        for (int to : c[v])
            if (!used[to])
            {
                goodDeg[to]--;
                s.erase(iters[to]);
                iters[to] = s.insert(mp(goodDeg[to] / (double) c[to].size(), to)).first;
            }
        used[v] = 1;
        tmp.pb(v);
    }
    //printf("%.20f\n", ans);
    printf("%d\n", cur);
    for (int i = tmp.size() - 1; i >= (int) tmp.size() - cur; i--)
    {
        printf("%d ", tmp[i] + 1);
    }
    return 0;
}