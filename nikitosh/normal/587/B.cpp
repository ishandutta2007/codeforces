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

const int MAXN = 1e6 + 5, MOD = 1e9 + 7;

LL t[3 * MAXN];
int a[MAXN], c[MAXN], dp[MAXN];
pii b[MAXN];

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
    int n, k;
    LL l;
    scanf("%d" I64 "%d", &n, &l, &k);    
    forn (i, n)
        scanf("%d", &a[i]), b[i] = mp(a[i], i);
    sort(b, b + n);
    int cur = 0;
    forn (i, n)
        if (i != 0 && b[i].fs == b[i - 1].fs)
            c[b[i].sc] = c[b[i - 1].sc];
        else
            c[b[i].sc] = cur++;
    int s = l % n;
    LL m = l / n;
    forn (i, n)
        dp[i] = 1;
    int tSize = 1;
    while (tSize < n)
        tSize *= 2;
    int ans = 0;
    forn (i, k)
    {
        int sum1 = 0, sum2 = 0;
        forn (j, s)
            sum1 = (sum1 + dp[j]) % MOD;
        forab (j, s, n)
            sum2 = (sum2 + dp[j]) % MOD;
        ans = (ans + sum1 * 1ll * (max(0ll, (m - i + 1)) % MOD) + sum2 * 1ll * (max(0ll, (m - i)) % MOD)) % MOD;
        forn (i, n)
        {
            int ind = tSize + c[i];
            while (ind > 0)
                t[ind] += dp[i], ind /= 2;
        }
        forn (i, n)
            dp[i] = get(1, 0, tSize, 0, c[i] + 1) % MOD;
        forn (i, n)
        {
            int ind = tSize + c[i];
            while (ind > 0)
                t[ind] = 0, ind /= 2;
        }
        //printf("%d\n", ans);
    }
    printf("%d\n", ans);
    return 0;
}