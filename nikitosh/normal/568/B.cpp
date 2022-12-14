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

const int MOD = 1e9 + 7, MAX = 4e3 + 5;

int two[MAX * MAX / 2 + 5], c[MAX + 5][MAX + 5], b[MAX + 5];

inline int add(int x)
{
    if (x >= MOD)
        x -= MOD;
    return x;
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    scanf("%d", &n);
    two[0] = 1;
    forab (i, 1, MAX * MAX / 2)
        two[i] = add(two[i - 1] + two[i - 1]);
    c[0][0] = 1;
    forab (i, 1, MAX)
    {
        c[i][0] = 1;
        forab (j, 1, i + 1)
            c[i][j] = add(c[i - 1][j - 1] + c[i - 1][j]);
    }
    b[0] = 1;
    forab (i, 1, MAX)
        forn (j, i)
            b[i] = (b[i] + c[i - 1][j] * 1ll * b[j]) % MOD;
    int ans = 0;
    forab (i, 1, n + 1)
    {
        ans = (ans + c[n][i] * 1ll * b[n - i]) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}