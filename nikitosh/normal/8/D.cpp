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

const double PI = 3.1415926535897932384626433832795;
const int MAXN = 10;
const double EPS = 1e-10;

double x[MAXN], y[MAXN], r[MAXN];
vector <pair <double, double> > ans;

double sqr(double x)
{
    return x * x;
}

double dist(double x_1, double y_1, double x_2, double y_2)
{
    return sqrt(sqr(x_1 - x_2) + sqr(y_1 - y_2));
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int t1, t2;
    scanf("%d%d", &t1, &t2);
    forn (i, 3)
        scanf("%lf%lf", &x[i], &y[i]);
    fornr (i, 3)
        x[i] -= x[0], y[i] -= y[0];
    double a = dist(x[0], y[0], x[1], y[1]);
    double b = dist(x[0], y[0], x[2], y[2]);
    double c = dist(x[1], y[1], x[2], y[2]);
    if (b + c <= a + t2)
    {
        printf("%.20f\n", min(b + c + t1, a + t2));
        return 0;
    }
    double ll = 0, rr = min(b + c + t1, a + t2);
    forn (qq, 1000)
    {
        double mm = (ll + rr) / 2;
        r[0] = mm;
        r[1] = a + t2 - mm;
        r[2] = b + t1 - mm;
        //printf("%f\n", mm);
        if (r[0] < 0 || r[1] < 0 || r[2] < 0)
        {
            rr = mm;
            continue;
        }
        //printf("%f %f %f\n", r[0], r[1], r[2]);
        bool ok = 0;
        forn (i, 3)
            forab (j, i + 1, 3)
            {
                double d = dist(x[i], y[i], x[j], y[j]);
                if (d > r[i] + r[j] + EPS)
                    continue;
                if (d + r[i] <= r[j] + EPS)
                {
                    int g = 3 - i - j;
                    if (dist(x[g], y[g], x[i], y[i]) <= r[i] + r[g])
                        ok = 1;
                    continue;
                }
                if (d + r[j] <= r[i] + EPS)
                {
                    int g = 3 - i - j;
                    if (dist(x[g], y[g], x[j], y[j]) <= r[j] + r[g])
                        ok = 1;
                    continue;
                }
                double aa = x[j] - x[i], bb = y[j] - y[i], cc = (r[i] * r[i] + d * d - r[j] * r[j]) / (2 * r[i]);
                ans.clear();
                if (bb == 0)
                {
                    double x_0 = cc / aa, y_0 = sqrt(1 - x_0 * x_0);
                    ans.pb(mp(x_0, y_0));
                    y_0 *= -1;
                    ans.pb(mp(x_0, y_0));
                }
                else
                {
                    double a0 = (aa * aa) / (bb * bb) + 1, b0 = (-2 * aa * cc / (bb * bb)), c0 = (cc * cc) / (bb * bb) - 1;
                    double dis = max(0.0, b0 * b0 - 4 * a0 * c0);
                    double x_0, y_0;
                    x_0 = (-b0 - sqrt(dis)) / (2 * a0);
                    y_0 = (cc - aa * x_0) / bb;    
                    ans.pb(mp(x_0, y_0));
                    x_0 = (-b0 + sqrt(dis)) / (2 * a0);
                    y_0 = (cc - aa * x_0) / bb;    
                    ans.pb(mp(x_0, y_0));
                }
                forn (g, 3)
                    if (g != i && g != j)
                        for (auto np : ans)
                        {
                            //printf("%f %f\n", np.fs, np.sc);
                            //printf("%.20f %.20f\n", np.fs * np.fs + np.sc * np.sc, abs(aa * np.fs + bb * np.sc - cc));
                            //printf("%.20f %.20f\n", abs(dist(x[i], y[i], x[i] + r[i] * np.fs, y[i] + r[i] * np.sc) - r[i]), abs(dist(x[j], y[j], x[i] + r[i] * np.fs, y[i] + r[i] * np.sc) - r[j]));
                            //assert(abs(dist(x[i], y[i], x[i] + r[i] * np.fs, y[i] + r[i] * np.sc) - r[i]) <= EPS);
                            //assert(abs(dist(x[j], y[j], x[i] + r[i] * np.fs, y[i] + r[i] * np.sc) - r[j]) <= EPS);
                            if (dist(x[g], y[g], x[i] + r[i] * np.fs, y[i] + r[i] * np.sc) <= r[g] + EPS)
                                ok = 1;
                        }
                //printf("%d %d %d\n", i, j, ok);
            }
        if (ok)
            ll = mm;
        else
            rr = mm;
    }
    printf("%.20f\n", ll);
    return 0;
}