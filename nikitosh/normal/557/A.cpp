#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for ( int i = 0 ; (i) < (n) ; ++i )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; ++it )
 
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

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    int Max[3], Min[3];
    scanf("%d", &n);
    forn (i, 3)
        scanf("%d%d", &Min[i], &Max[i]);
    int s = min(Max[0], n - Min[1] - Min[2]);
    n -= s;
    int t = min(Max[1], n - Min[2]);
    n -= t;
    printf("%d %d %d\n", s, t, n);
    return 0;
}