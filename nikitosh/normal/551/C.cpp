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

int a[MAXN], b[MAXN];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, m;
    scanf("%d%d", &n, &m);
    forn (i, n)
        scanf("%d", &b[i]);
    LL l = 0, r = 1e18;
    while (r - l > 1)
    {
        LL t = (l + r) / 2;
        LL cntStud = 0, rem = 0;
        forn (i, n)
            a[i] = b[i];
        fornr (i, n)
        {
            if (a[i] <= rem)
                rem -= a[i], a[i] = 0;
            else
                a[i] -= rem, rem = 0;
            if (a[i] == 0)
                continue;
            LL zn = t - (i + 1);
            if (zn <= 0)
            {
                cntStud = 1e18;
                break;
            }
            LL k = (a[i] + zn - 1) / (zn);
            cntStud += k;
            rem += k * zn - a[i];            
        }
        if (cntStud > m)
            l = t;
        else
            r = t;
    }
    printf("%I64d\n", r);
    return 0;
}