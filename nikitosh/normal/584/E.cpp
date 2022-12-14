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

int p1[MAXN], p2[MAXN], p[MAXN], place[MAXN], used[MAXN], def[MAXN];
vi tmp;
vector <pii> ansV;

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    scanf("%d", &n);
    forn (i, n)
        scanf("%d", &p1[i]), place[p1[i] - 1] = i;
    forn (i, n)
        scanf("%d", &p2[i]), p[i] = place[p2[i] - 1];
    forn (i, n)
        place[p[i]] = i;
    int ans = 0;      

    forn (i, n)
        def[i] = i;
    forn (j, n)
    {
        tmp.clear();
        int k = p[j];
        int ind = -1;
        forn (g, n)
            if (def[g] == k)
                ind = g;
        assert(ind != -1);
        int v = def[j];
        if (v == k)
            continue;
        tmp.pb(j);
        int curMax = place[v];
        forab (i, j + 1, ind)
            if (place[def[i]] > curMax)
                tmp.pb(i), curMax = place[def[i]];
        tmp.pb(ind);
        for (int i = sz(tmp) - 1; i > 0; i--)
        {
            ansV.pb(mp(tmp[i], tmp[i - 1]));
            swap(def[tmp[i]], def[tmp[i - 1]]);
        }
        ans += ind - j;
    }

    printf("%d\n%d\n", ans, sz(ansV));
    for (auto np : ansV)
        printf("%d %d\n", np.fs + 1, np.sc + 1);
    return 0;
}