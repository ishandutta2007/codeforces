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
const int SQRT = 750;
const int INF = 1e9;

LL a[MAXN], add[MAXN];
set <pair <LL, int> > s[MAXN];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, q;
    scanf("%d%d", &n, &q);
    forn (i, n)
    {
        scanf("%I64d", &a[i]);
        s[i / SQRT].insert(mp(a[i], i));
    }
    forn (i, q)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int l, r, val;
            scanf("%d%d%d", &l, &r, &val);
            l--, r--;
            if (r - l <= 2 * SQRT)
            {
                forab (i, l, r + 1)
                {
                    s[i / SQRT].erase(mp(a[i], i));
                    a[i] += val;
                    s[i / SQRT].insert(mp(a[i], i));
                }
            }
            else
            {
                while (l % SQRT != 0)
                {
                    s[l / SQRT].erase(mp(a[l], l));
                    a[l] += val;
                    s[l / SQRT].insert(mp(a[l], l));
                    l++;
                }
                while (r % SQRT != SQRT - 1)
                {
                    s[r / SQRT].erase(mp(a[r], r));
                    a[r] += val;
                    s[r / SQRT].insert(mp(a[r], r));
                    r--;
                }
                l /= SQRT, r /= SQRT;
                forab (i, l, r + 1)
                    add[i] += val;
            }
        }
        else
        {
            int val;
            scanf("%d", &val);
            int minn = INF, maxx = -INF;
            forn (i, n / SQRT + 1)
            {
                LL k = val - add[i];
                auto it = s[i].lower_bound(mp(k, -1));
                if (it == s[i].end() || it->first != k)
                    continue;
                auto it2 = s[i].upper_bound(mp(k, INF));
                it2--;
                minn = min(minn, it->second);
                maxx = max(maxx, it2->second);
            } 
            if (minn == INF)
                puts("-1");
            else
                printf("%d\n", maxx - minn);
        }
    }
    return 0;
}