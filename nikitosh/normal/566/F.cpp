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

const int MAX = 1e6 + 5;

int pr[MAX + 5], a[MAX + 5], dp[MAX + 5];
vector <pair <int, int> > v;

void gen(int n, int k, int cur)
{
    if (k == (int) v.size())
    {
        if (cur == n)
            return;
        dp[n] = max(dp[n], dp[cur] + 1);
        return;
    }
    for (int i = 0; i <= v[k].sc; i++)
    {
        gen(n, k + 1, cur);
        cur *= v[k].fs;    
    }
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    forn (i, MAX + 1)
        pr[i] = i, dp[i] = -1;
    for (int i = 2; i <= MAX; i++)
    {
        if (pr[i] == i)
            for (int j = i + i; j <= MAX; j += i)
                if (pr[j] == j)
                    pr[j] = i;                
    }
    int n;
    scanf("%d", &n);
    forn (i, n)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int maxx = 0;
    forn (i, n)
    {
        int k = a[i];
        v.clear();
        while (k > 1)
        {
            int p = pr[k], cnt = 0;
            while (k % p == 0)
                 k /= p, cnt++;
            v.pb(mp(p, cnt));
        }
        dp[a[i]] = 1;
        gen(a[i], 0, 1);
        maxx = max(maxx, dp[a[i]]);        
    }
    printf("%d\n", maxx);
    return 0;                   
}