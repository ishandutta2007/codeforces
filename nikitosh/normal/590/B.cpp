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

int x_1, y_1, x_2, y_2, v_x, v_y, u_x[2], u_y[2], vMax, t;

double len(double x, double y)
{
    return sqrt(x * x + y * y);
}

double foo(int k)
{
    double cosAng = (v_x * u_x[k] + v_y * u_y[k]) / (len(v_x, v_y) * len(u_x[k], u_y[k]));
    double a = 1;
    double b = 2 * len(u_x[k], u_y[k]) * cosAng;
    double c = (u_x[k] * u_x[k] + u_y[k] * u_y[k] - vMax * vMax);
    double d = b * b - 4 * a * c;
    assert(d >= 0);
    return (-b + sqrt(d)) / (2 * a);
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    scanf("%d%d%d%d", &x_1, &y_1, &x_2, &y_2);
    v_x = x_2 - x_1, v_y = y_2 - y_1;
    scanf("%d%d", &vMax, &t);
    forn (i, 2)
        scanf("%d%d", &u_x[i], &u_y[i]);
    double dist = len(v_x, v_y);
    double ll = 0;
    double rr = 1e9;
    forn (k, 1000)
    {
        double mm = (ll + rr) / 2;
        double x = v_x, y = v_y;
        if (mm <= t)
        {
            x -= mm * u_x[0], y -= mm * u_y[0];
        }
        else
        {
            x -= (t * u_x[0] + (mm - t) * u_x[1]), y -= (t * u_y[0] + (mm - t) * u_y[1]);
        }
        if (len(x, y) <= vMax * mm)
            rr = mm;
        else
            ll = mm;
    }
    printf("%.20f\n", ll);
    return 0;
}