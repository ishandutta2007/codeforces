//#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;

#define BSET(a, p) ((a) | (1ll << (p)))
#define BCHK(a, p) ((a) & (1ll << (p)))
#define BXOR(a, p) ((a) ^ (1ll << (p)));
#define BREM(a, p) (BCHK(a, p)?(BXOR(a, p)):(a))
#define BSHO(a, N) (bitset<N>(a))

#define fi first
#define sc second 
#define pb push_back


#ifdef DEBUG
    #define dbg(s) {s;}
    #define PRELUDE
#endif

#ifndef DEBUG 
    #define PRELUDE { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
    #define dbg(s)
    #define endl "\n"
#endif

#define int ll
#define i32 int32_t

#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 
// Ordered set docs:
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

// To remove randomization use 0 below:
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int ri(int x) { // from [0, n-1]
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

inline ld rf() { // from [0, 1]
    return uniform_real_distribution<ld>(0, 1)(rng);
}

const ll mod = 1e9 + 7;

ll modexp(ll x, ll ex) {
    x = x%mod;
    ex = ex % (mod-1);
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

const int maxn = 1e6 + 7;

const ll inf = 1e9 + 7;
#define eps 1e-4
#define PI acos(-1.0)
double gcd(double x, double y)
{
    while (fabs(x) > eps && fabs(y) > eps)
    {
        if (x > y)
            x -= floor(x / y) * y;
        else
            y -= floor(y / x) * x;
    }
    return x + y;
}

double area(double a,double b,double c)
{
    double s=((double)a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

void solve()
{
    double x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    double a,b,c;
    a=sqrt(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));
    b=sqrt(((x1-x3)*(x1-x3))+((y1-y3)*(y1-y3)));
    c=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
    double S;
    S=area(a,b,c);
    double R=((double)a*b*c)/(4*S);
    double A,B,C;
    A=acos((b*b+c*c-a*a)/(2*b*c));
    B=acos((a*a+c*c-b*b)/(2*a*c));
    C=acos((a*a+b*b-c*c)/(2*a*b));
    double g=gcd(A,gcd(B,C));
    double n=(PI)/(g);
    double ans=((double)R*R*n*sin((2*PI)/n))/2;
    printf("%.6lf\n",ans);
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
    
    //PRELUDE;
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}