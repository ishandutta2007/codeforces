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

const int MAXN = 1e6 + 5;

int a[MAXN];
pii b[MAXN];
LL dp[MAXN], t[4 * MAXN];

void update(int ind, LL k)
{
    while (ind > 0)
        t[ind] += k, ind /= 2;
}

LL get(int v, int ll, int rr, int l, int r)
{
    if (ll >= l && rr <= r)
        return t[v];
    if (ll >= r || l >= rr)
        return 0;
    int mm = (ll + rr) / 2;
    return get(2 * v, ll, mm, l, r) + get(2 * v + 1, mm, rr, l, r);
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    scanf("%d", &n);
    forn (i, n)
        scanf("%d", &a[i]), dp[i] = 1, b[i] = mp(a[i], i);
    sort(b, b + n);
    forn (i, n)
        if (i != 0 && b[i].fs == b[i - 1].fs)
            a[b[i].sc] = a[b[i - 1].sc];
        else
            a[b[i].sc] = i;
    int N = 1;
    while (N < n)
        N *= 2;
    forn (qq, 2)
    {
        forn (i, 2 * N)
            t[i] = 0;
        forn (i, n)
        {
            LL k = get(1, 0, N, a[i] + 1, N);
            update(a[i] + N, dp[i]);
            dp[i] = k;
        }
    }
    LL ans = 0;
    forn (i, n)
        ans += dp[i];
    printf(I64 "\n", ans);
    return 0;
}