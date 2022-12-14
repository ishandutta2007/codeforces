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
const double INF = 1e15;

int a[MAXN];
double b[MAXN];
int n;

double foo(double x)
{
    forn (i, n)
        b[i] = a[i] - x;
    double curSum = 0, minSum = 0, maxSum = 0, minAns = INF, maxAns = -INF;
    forn (i, n)
    {
        curSum += b[i];
        minAns = min(minAns, curSum - maxSum);
        maxAns = max(maxAns, curSum - minSum);
        minSum = min(minSum, curSum);
        maxSum = max(maxSum, curSum);
    }    
    return max(abs(minAns), abs(maxAns));
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    scanf("%d", &n);
    forn (i, n)
        scanf("%d", &a[i]);
    double ll = -1e5, rr = 1e5;
    forn (it, 100)
    {
        double mm1 = (2 * ll + rr) / 3, mm2 = (ll + 2 * rr) / 3;
        double val1 = foo(mm1), val2 = foo(mm2);
        if (val1 > val2)
            ll = mm1;
        else
            rr = mm2;
    }                
    printf("%.20f\n", foo(ll));
    return 0;
}