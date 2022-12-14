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

const int INF = 1e9;

set <pii> s;
vector <pii> v;

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, q, a, k;
    scanf("%d%d%d%d", &n, &k, &a, &q);
    int ans = (n + 1) / (a + 1);
    s.insert(mp(1, n));
    forn (qq, q)
    {
        int l;
        scanf("%d", &l);
        auto it = s.upper_bound(mp(l, INF));
        it--;
        ans -= (it->sc - it->fs + 2) / (a + 1);
        v.clear();
        if (l != it->fs)
        {
            v.pb(mp(it->fs, l - 1));
            ans += (l - it->fs + 1) / (a + 1);
        }
        if (l != it->sc)
        {
            v.pb(mp(l + 1, it->sc));
            ans += (it->sc - l + 1) / (a + 1);
        } 
        s.erase(it);
        for (auto np : v)
            s.insert(np);
        if (ans < k)
        {
            printf("%d\n", qq + 1);
            return 0;
        }
    }
    puts("-1");
    return 0;
}