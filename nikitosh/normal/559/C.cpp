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
const int MOD = 1e9 + 7;

pii a[MAXN];
int cnt[MAXN];
int fact[MAXN + 5], invfact[MAXN + 5];


inline int add(int a)
{
    if (a >= MOD)
        a -= MOD;
    return a;
}

int power(int a, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        int s = power(a, n / 2);
        return (s * 1ll * s) % MOD;
    }
    return (a * 1ll * power(a, n - 1)) % MOD;
}

int c(int n, int k)
{
    return ((fact[n] * 1ll * invfact[k]) % MOD * 1ll * invfact[n - k]) % MOD;
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    fact[0] = 1;
    invfact[0] = power(fact[0], MOD - 2);
    forab (i, 1, MAXN)
        fact[i] = (fact[i - 1] * 1ll * i) % MOD, invfact[i] = power(fact[i], MOD - 2);
    int h, w, n;
    scanf("%d%d%d", &h, &w, &n);
    forn (i, n)
        scanf("%d%d", &a[i].fs, &a[i].sc);
    sort(a, a + n);
    a[n++] = mp(h, w);
    forn (i, n)
    {
        cnt[i] = c(a[i].fs - 1 + a[i].sc - 1, a[i].fs - 1);
        forn (j, i)
            if (a[j].fs <= a[i].fs && a[j].sc <= a[i].sc)
                cnt[i] = add(cnt[i] - (cnt[j] * 1ll * c(a[i].fs - a[j].fs + a[i].sc - a[j].sc, a[i].fs - a[j].fs)) % MOD + MOD);
    }
    printf("%d\n", cnt[n - 1]);
    return 0;
}