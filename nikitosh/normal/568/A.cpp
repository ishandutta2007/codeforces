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

const int MAX = 2e6;

int pr[MAX + 5];

bool pal(int n)
{
    vi v;
    while (n > 0)
        v.pb(n % 10), n /= 10;
    bool ok = 1;
    forn (i, sz(v))
        if (v[i] != v[sz(v) - i - 1])
            ok = 0;
    return ok;
}                

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int p, q;
    scanf("%d%d", &p, &q);
    int cnt1 = 0, cnt2 = 1;
    int maxx = 1;
    forab (i, 2, MAX)
        pr[i] = 1;
    forab (i, 2, MAX)
        if (pr[i])
            for (int j = i + i; j < MAX; j += i)
                pr[j] = 0;

    forab (i, 2, MAX)
    {
        if (pr[i])
            cnt1++;
        if (pal(i))
            cnt2++;
        if (p * cnt2 >= q * cnt1)
            maxx = i;
        //printf("%d %d\n", cnt1, cnt2);
    }
    if (maxx == 0)
        puts("Palindromic tree is better than splay tree");
    else
        printf("%d\n", maxx);
    return 0;
}