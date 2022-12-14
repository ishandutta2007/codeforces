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

const int MAXN = 2e5 + 5;

int a[MAXN], used[MAXN];
vi cnt[MAXN], v[MAXN], divisors[MAXN];
vector <pii> edges;

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    scanf("%d", &n);
    forn (i, n)
        scanf("%d", &a[i]), a[i]--;
    int cur = 0;
    forn (i, n)
        if(!used[i])
        {
            int k = i;
            while (!used[k])
                v[cur].pb(k), used[k] = 1, k = a[k];
            cnt[sz(v[cur])].pb(cur);
            cur++;
        } 
    forab (i, 1, n + 1)
        for (int j = i + i; j <= n; j += i)
            divisors[j].pb(i);
    if (sz(cnt[1]) == 0 && sz(cnt[2]) == 0)
    {
        puts("NO");
        return 0;
    }
    for (int i = n; i > 0; i--)
    {
        forn (it, sz(cnt[i]))
        {
            int num = cnt[i][it];
            bool was = 0;
            for (int l : divisors[i])
                if (sz(cnt[l]) > 0)
                {
                    was = 1;
                    for (int j = 0; j < l; j++)
                        for (int g = j; g < i; g += l)
                            edges.pb(mp(v[num][g], v[cnt[l][0]][j]));        
                    break;
                }
            if (!was && i == 2)
            {
                if (it == 0)
                    edges.pb(mp(v[num][0], v[num][1]));
                else
                {
                    edges.pb(mp(v[num][0], v[cnt[i][0]][0]));
                    edges.pb(mp(v[num][1], v[cnt[i][0]][1]));
                }
                was = 1;
            }
            if (!was && i == 1)
            {
                if (it != 0)
                    edges.pb(mp(v[num][0], v[cnt[i][0]][0]));
                was = 1;
            }
            if (!was)
            {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    for (auto np : edges)
        printf("%d %d\n", np.fs + 1, np.sc + 1);
    return 0;
}