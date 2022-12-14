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

int x[MAXN], y[MAXN];
double val1[MAXN], val2[MAXN];

LL getS(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3)
{
    return (x_2 - x_1) * 1ll * (y_3 - y_1) - (x_3 - x_1) * 1ll * (y_2 - y_1);
}

int gr(int k, int l)
{
    return __gcd(abs(x[k] - x[l]), abs(y[k] - y[l]));
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
        scanf("%d%d", &x[i], &y[i]);
    LL s = 0;
    forab (i, 1, n - 1)
        s += getS(x[0], y[0], x[i], y[i], x[i + 1], y[i + 1]);
    double ans = s / 2.0 + 1;
    forn (i, n)
        x[i + n] = x[i], y[i + n] = y[i];
    forn (i, n)
        ans += gr(i, i + 1) / 2.0;
    double cur = 1;
    forba (i, 1, n)
    {
        val1[i] = cur, cur /= 2;
        val2[i] = (n * 1ll * n + n + 2) * cur;
    }
    //printf("%.6f\n", ans);
    int l = min(60, n);
    forn (i, n)
    {
        double cur = 0;
        forab(j, 1, l)
        {
            if (j == 1)
                cur = gr(i, i + 1);
            else
            {
                cur -= gr(i, i + j - 1) / 2.0;
                cur += gr(i + j - 1, i + j) / 2.0 + gr(i, i + j) / 2.0;            
                cur += getS(x[i], y[i], x[i + j - 1], y[i + j - 1], x[i + j], y[i + j]) / 2.0;
            }
            ans -= cur * (1 - val1[j]) / ((1ll << (j + 1)) - val2[j]);
            //printf("%.20f\n", ans);
        }
    }
    printf("%.20f\n", ans);
    return 0;
}