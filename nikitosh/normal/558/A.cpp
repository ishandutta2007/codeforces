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

const int MAXN = 105;

pii a[MAXN];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    scanf("%d", &n);
    forn (i, n)
        scanf("%d%d", &a[i].fs, &a[i].sc);
    sort(a, a + n);
    int cnt1 = 0, cnt2 = 0;
    forn (i, n)
        if (a[i].fs < 0)
            cnt1++;
        else
            cnt2++;
    int res = 0;
    if (cnt1 < cnt2)
    {
        int k = cnt1 + 1;
        forn (i, n)
            if (a[i].fs < 0)
                res += a[i].sc;
            else if (k > 0)
            {
                res += a[i].sc;
                k--;
            }
        printf("%d\n", res);
    }
    else
    {
        int k = cnt2 + 1;
        fornr (i, n)
            if (a[i].fs > 0)
                res += a[i].sc;
            else if (k > 0)
            {
                res += a[i].sc;
                k--;
            }
        printf("%d\n", res);
    }
    return 0;
}