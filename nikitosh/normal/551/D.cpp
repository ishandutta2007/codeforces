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

int mod;

vector <int> mul(vector <int> v1, vector <int> v2)
{
    return {int((v1[0] * 1ll * v2[0] + v1[1] * 1ll * v2[2]) % mod),
            int((v1[0] * 1ll * v2[1] + v1[1] * 1ll * v2[3]) % mod),
            int((v1[2] * 1ll * v2[0] + v1[3] * 1ll * v2[2]) % mod),
            int((v1[2] * 1ll * v2[1] + v1[3] * 1ll * v2[3]) % mod)};
}

vector <int> fib(LL n)
{
    if (n == 1)
        return {1,1,1,0};
    if (n % 2 == 0)
    {
        auto res = fib(n / 2);
        return mul(res, res);
    }
    return mul(fib(n - 1), {1,1,1,0});
}

int power(LL n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        int res = power(n / 2);
        return (res * 1ll * res) % mod;
    }
    return (2 * power(n - 1)) % mod;
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    LL n, k;
    int l;
    scanf("%I64d%I64d%d%d", &n, &k, &l, &mod);
    int cnt1 = 0, cnt2 = 0;
    LL k2 = k;
    forn (i, l)
    {
        if (k2 & 1)
            cnt1++;
        else
            cnt2++;
        k2 >>= 1;
    }
    if (k2)
    {
        puts("0");
        return 0;
    }
    auto res = fib(n + 2);
    int f = res[1] % mod;
    int ans = 1;
    forn (i, cnt2)
        ans = (ans * 1ll * f) % mod;        
    int s = ((power(n) - f) % mod + mod) % mod;
    forn (i, cnt1)
        ans = (ans * 1ll * s) % mod;
    printf("%d\n", ans % mod);
    return 0;
}