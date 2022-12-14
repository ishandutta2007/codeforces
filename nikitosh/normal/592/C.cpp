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

void print(LL a, LL b)
{
    LL g = __gcd(a, b);
    a /= g, b /= g;
    printf(I64 "/" I64, a, b);
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif
    LL t, b, w; 
    scanf(I64 I64 I64, &t, &w, &b);
    if (w < b)
        swap(w, b);
    LL g = __gcd(w, b);
    LL lcm = w / g;
    if (lcm > t / b)
    {
        LL ans = min(b - 1, t);
        print(ans, t);        
    }
    else
    {
        lcm *= b;
        LL k = t / lcm;
        LL ans = k * b - 1;
        LL s = k * lcm;
        ans += min(b, t - s + 1);
        print(ans, t);
    }
    return 0;
}