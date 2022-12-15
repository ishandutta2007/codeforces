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

const int MAXN = 10;

char s[MAXN][MAXN];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n = 8;
    forn (i, n)
        gets(s[i]);
    int ans1 = n, ans2 = n;
    forn (i, n)
        forn (j, n)
        {
            if (s[i][j] == 'W')
            {
                bool ok = 1;
                forn (g, i)
                    if (s[g][j] != '.')
                        ok = 0;
                if (ok)
                    ans1 = min(ans1, i);                                                            
            } 
            if (s[i][j] == 'B')
            {
                bool ok = 1;
                forab (g, i + 1, n)
                    if (s[g][j] != '.')
                        ok = 0;
                if (ok)
                    ans2 = min(ans2, n - 1 - i);                                                            
            } 
        }
    //printf("%d %d\n", ans1, ans2);
    if (ans1 <= ans2)
        puts("A");
    else
        puts("B");
    return 0;
}