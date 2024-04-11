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

const int MAXN = 10005, INF = 1e9;

int a[MAXN], b[MAXN], d[MAXN], cnt[MAXN];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, t;
    scanf("%d%d", &n, &t);
    forn (i, n)
        scanf("%d", &a[i]);
    int l = min(t, n);
    forn (i, l)
        forn (j, n)
            b[i * n + j] = a[j];
    int m = l * n;
    forn (i, m + 1)
        d[i] = INF;
    d[0] = 0;
    forn (i, m)
    {
        int k = upper_bound(d, d + m + 1, a[i % n]) - d;
        d[k] = a[i % n];
    }
    int maxx = 0;
    forn (i, n)
    {
        cnt[a[i]]++;
        if (cnt[a[i]] > maxx)
            maxx = cnt[a[i]];
    }
    int ans = 0;
    forn (i, m + 1)
        if (d[i] != INF)
            ans = i;
                   
    printf("%d\n", ans + (t - l) * maxx);
    return 0;
}