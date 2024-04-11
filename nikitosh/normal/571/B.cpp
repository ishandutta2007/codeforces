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

const int MAXN = 3e5 + 5, MAXK = 5005;

int a[MAXN];
LL d[MAXK][MAXK];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, k;
    scanf("%d%d", &n, &k);    
    forn (i, n)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int l = n / k;
    int t = n % k;
    int s = (n - t * (l + 1)) / l;
    d[0][0] = 0;
    forn (i, s + 1)
        forn (j, t + 1)
        {
            if (i == 0 && j == 0)
                continue;
            if (i == 0)
                d[i][j] = d[i][j - 1] + a[j * (l + 1) - 1] - a[(j - 1) * (l + 1)];
            if (j == 0)
                d[i][j] = d[i - 1][j] + a[i * l - 1] - a[(i - 1) * l];
            if (i != 0 && j != 0)
            {
                d[i][j] = min(d[i][j - 1] + a[i * l + j * (l + 1) - 1] - a[i * l + (j - 1) * (l + 1)], 
                              d[i - 1][j] + a[i * l + j * (l + 1) - 1] - a[(i - 1) * l + j * (l + 1)]);
            } 
        }
    printf("%I64d\n", d[s][t]);
    return 0;
}