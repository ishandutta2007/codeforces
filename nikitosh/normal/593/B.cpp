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

LL INF = 1e18;

vector <pair <LL, LL> > v;

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, x_1, x_2;
    scanf("%d", &n);
    scanf("%d%d", &x_1, &x_2);
    forn (i, n)
    {
        int k, b;
        scanf("%d%d", &k, &b);    
        LL y_1 = k * 1ll * x_1 + b, y_2 = k * 1ll * x_2 + b;
        v.pb(mp(y_1, y_2));
    }
    sort(all(v));
    bool ok = 0;
    LL maxx = -INF;
    forn (i, sz(v))
    {
        int j = i;
        LL minn = INF, maxx2 = -INF;
        while (j < sz(v) && v[j].fs == v[i].fs)
            minn = min(minn, v[j].sc), maxx2 = max(maxx2, v[j].sc), j++;
        if (minn < maxx)
            ok = 1;
        //printf("%I64d %I64d\n", minn, maxx);
        maxx = max(maxx, maxx2);
        i = j - 1;        
    } 
    if (ok)
        puts("YES");
    else
        puts("NO");
    return 0;
}