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

pair <pii, int> a[MAXN];

bool cmp2(pair<pii, int> a, pair<pii, int> b)
{
    return a.fs.sc < b.fs.sc;
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
        scanf("%d%d", &a[i].fs.fs, &a[i].fs.sc), a[i].sc = i;
    sort(a, a + n);            
    int k = 500;
    bool sw = 0;
    forn (i, n)
    {
        int j = i;
        while (j < n && a[j].fs.fs > k - 1000 && a[j].fs.fs <= k)
            j++;
        sort(a + i, a + j, cmp2);
        if (sw)
            reverse(a + i, a + j);
        i = j - 1;
        sw ^= 1;
        k += 1000; 
    }
    forn (i, n)
        printf("%d ", a[i].sc + 1);
    return 0;
}