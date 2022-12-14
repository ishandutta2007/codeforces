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

pii a[MAXN];
int w[MAXN];
vector <pii> ans;
set <pair <int, pii> > s;
set <pii> used;
map <int, int> was;
map <pii, int> cnt;

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    scanf("%d", &n);    
    forn (i, n)
        scanf("%d%d", &a[i].fs, &a[i].sc), used.insert(mp(a[i].fs, a[i].sc));
    forn (i, n)
        scanf("%d", &w[i]);
    s.insert(mp(0, mp(0, 0)));
    used.erase(mp(0, 0));
    forn (k, n)
    {
        auto it = s.lower_bound(mp(w[k], mp(0, 0)));
        if (it == s.end() || it->fs != w[k])
        {
            puts("NO");
            return 0;
        }
        auto np = *it;
        s.erase(it);
        auto cur = np.sc;
        ans.pb(cur);
        was[cur.sc - cur.fs] = 0;
        auto nxt1 = mp(cur.fs, cur.sc + 1);
        if (used.count(nxt1))
        {
            if (!was[cur.sc + 1 - cur.fs])
            { 
                was[cur.sc + 1 - cur.fs] = 1;
                s.insert(mp(cur.sc + 1 - cur.fs, nxt1));
                used.erase(nxt1);            
            }
            else
            {
                puts("NO");
                return 0;
            }
        }    
        auto nxt2 = mp(cur.fs + 1, cur.sc);
        if (used.count(nxt2))
        {
            if (!was[cur.sc - 1 - cur.fs])
            { 
                was[cur.sc - 1 - cur.fs] = 1;
                s.insert(mp(cur.sc - 1 - cur.fs, nxt2));
                used.erase(nxt2);            
            }
            else
            {
                puts("NO");
                return 0;
            }
        }
    }
    int res = 1;
    for (auto np : ans)
        cnt[np] = res++;
    forn (i, n)
        if (a[i].fs > 0 && cnt[mp(a[i].fs - 1, a[i].sc)] > cnt[a[i]])
        {
            puts("NO");
            return 0;
        }
    forn (i, n)
        if (a[i].sc > 0 && cnt[mp(a[i].fs, a[i].sc - 1)] > cnt[a[i]])
        {
            puts("NO");
            return 0;
        }
    puts("YES");
    for (auto np : ans)
        printf("%d %d\n", np.fs, np.sc);
    return 0;
}