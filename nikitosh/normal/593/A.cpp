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

const int MAXN = 105, MAXL = 1005;

char s[MAXN][MAXL];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, maxx = 0;
    scanf("%d", &n);
    forn (i, n)
        scanf("%s", s[i]);
    forn (i, 26)
        forn (j, 26)
        {
            int cur = 0;
            forn (k, n)
            {
                int l = strlen(s[k]);
                bool ok = 1;
                forn (g, l)
                    if (s[k][g] != 'a' + i && s[k][g] != 'a' + j)
                        ok = 0;
                if (ok)
                    cur += l;
            }
            maxx = max(maxx, cur);
        }
    printf("%d\n", maxx);
    return 0;
}