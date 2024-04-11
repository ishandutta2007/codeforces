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

const int MAXN = 4e5 + 5;

int a[MAXN], maxx[MAXN], p[MAXN], sum[MAXN];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    scanf("%d", &n);
    forn (i, n)
        scanf("%d", &a[i]), a[n + i] = a[i];
    LL ans = 0;
    forab (g, 1, n)
    {
        if (n % g != 0)
            continue;
        forn (i, g)
            maxx[i] = 0;
        forn (i, n)
            maxx[i % g] = max(maxx[i % g], a[i]);
        
        int k = n / g;
        forab (i, 1, k + 1)
        {
            if (__gcd(i, k) == 1)
                p[i] = 1;
            else
                p[i] = 0;
            sum[i] = sum[i - 1] + p[i];
        }
        int ind = -1;
        forn (i, n)
            if (a[i] != maxx[i % g])
                ind = i;
        if (ind == -1)
        {
            ans += n * 1ll * sum[(n - 1) / g];    
            continue;
        }
        forab (i, ind + 1, ind + n + 1)
        {
            if (a[i] != maxx[i % g])
                continue;
            int last = ind + n + 1;
            forab (j, i, ind + n + 1)
                if (a[j] != maxx[j % g])
                {
                    last = j;
                    break;
                } 
            int curLen = last - i;
            forab (j, i, last)
                ans += sum[curLen / g], curLen--;
            i = last - 1;
        }    
    }   
    printf(I64 "\n", ans);
    return 0;
}