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

const int MAXN = 1e3;

int x[MAXN], y[MAXN], r[MAXN];

string intTo(int k)
{
    if (k == 0)
        return "0";
    
    string s = "";
    while (k > 0)
        s += '0' + k % 10, k /= 10;    
    reverse(all(s));
    return s;
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
        scanf("%d%d%d", &x[i], &y[i], &r[i]);
    string f = "0", g = "0";
    forn (i, n)
    {
        string t = intTo(i);
        f = "(" + f + "+(" + intTo(x[i] / 2) + "*" + "(abs((abs((t-" + t + "))-1))-(abs((t-" + t + "))-1))" + "))";
        g = "(" + g + "+(" + intTo(y[i] / 2) + "*" + "(abs((abs((t-" + t + "))-1))-(abs((t-" + t + "))-1))" + "))";       
    }
    cout << f << endl;
    cout << g << endl; 
    return 0;
}