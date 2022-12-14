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

const int MAXN = 1e6 + 5;

int a[MAXN], used[MAXN], cnt[MAXN], b[MAXN];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    scanf("%d", &n);
    forn (i, n)
        scanf("%d", &a[i]), b[i] = a[i];
    forab (i, 1, n - 1)
        if (a[i] != a[i - 1] && a[i] != a[i + 1])
            used[i] = 1;
    int ans = 0;
    forab (i, 1, n)
    {
        if (used[i])
            cnt[i] = cnt[i - 1] + 1;
        else
        {
            cnt[i] = 0;                
            if (used[i - 1])
            {
                int j = i - 1;
                while (used[j])
                    j--;
                if (a[j] == a[i])
                    forab (g, j, i)
                        b[g] = a[j];
                else
                {
                    forab (g, j + 1, (i + j) / 2 + 1)
                        b[g] = a[j];
                    forab (g, (i + j) / 2 + 1, i)
                        b[g] = a[i];
                }   
            }
        }
        ans = max(ans, (cnt[i] + 1) / 2);
    }
    printf("%d\n", ans);
    forn (i, n)
        printf("%d ", b[i]);
    return 0;
}