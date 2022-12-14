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

LL solve(int a, int b, int c, int l)
{
    LL ans = 0;
    if (b > c)
        swap(b, c);
    forn (i, l + 1)
    {
        int k = min(i + a - b - c, l - i);
        if (k >= 0)
            ans += (k + 1) * 1ll * (k + 2) / 2;
    }
    return ans;
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int a, b, c, l;
    scanf("%d%d%d%d", &a, &b, &c, &l);    
    LL ans = (l + 3) * 1ll * (l + 2) * 1ll * (l + 1) / 6;
    ans -= (solve(a, b, c, l) + solve(b, a, c, l) + solve(c, a, b, l));
    printf(I64 "\n", ans);
    return 0;
}