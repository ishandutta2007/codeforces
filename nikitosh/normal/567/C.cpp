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

map <LL, int> cnt;
int a[MAXN], lef[MAXN], righ[MAXN];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, k;
    scanf("%d%d", &n, &k);
    LL ans = 0;
    forn (i, n)
    {
        scanf("%d", &a[i]);
        if (a[i] % k == 0)
            lef[i] = cnt[a[i] / k];
        cnt[a[i]]++;
    }
    cnt.clear();
    fornr (i, n)
    {
        righ[i] = cnt[a[i] * 1ll * k];
        cnt[a[i]]++;
        ans += lef[i] * 1ll * righ[i];
    }
    printf(I64 "\n", ans);
    return 0;
}