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

const int MAXN = 1e5 + 5;
const int INF = 1e9;

int l[MAXN], d[MAXN];
pii a[MAXN];
multiset <int> s;

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    scanf("%d", &n);
    forn (i, n)
        scanf("%d", &l[i]);
    int sum = 0;
    forn (i, n)
        scanf("%d", &d[i]), sum += d[i];
    forn (i, n)
        a[i] = mp(l[i], d[i]);
    sort(a, a + n);
    a[n] = mp(0, 0);
    int ans = INF;
    forn (i, n)
    {
        int ind = n;
        int res = 0;
        for (int j = i; j < n; j++)
        {
            if (a[j].first != a[i].first)
            {
                ind = j;
                break;
            }    
            res += a[j].second;
        }
        int k = ind - i;
        int cnt = min((int) s.size(), k - 1);
        for (auto    it = s.begin(); it != s.end() && cnt > 0; it++, cnt--)
            res -= *it;
        ans = min(ans, sum - res);
        for (int j = i; j < n; j++)
        {
            if (a[j].first != a[i].first)
                break;
            s.insert(-a[j].second);
        }
        i = ind - 1;
    }
    printf("%d\n", ans);
    return 0;
}