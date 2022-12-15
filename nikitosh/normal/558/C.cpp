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

const int MAX = 1e5 + 5;
const int INF = 1e9;

int q[MAX + 10], used[MAX + 10], d[MAX + 10], ans[MAX + 10];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    scanf("%d", &n);
    forn (i, MAX)
        d[i] = INF;
    forn (i, n)
    {
        int k;
        scanf("%d", &k);
        int head = 0, tail = 0;
        q[tail++] = k;
        d[k] = 0;
        while (tail > head)
        {
            int v = q[head++];
            if (2 * v < MAX && d[2 * v] > d[v] + 1)
            {
                q[tail++] = 2 * v;
                d[2 * v] = d[v] + 1;
            }
            if (v != 1 && d[v / 2] > d[v] + 1)
            {
                q[tail++] = v / 2;
                d[v / 2] = d[v] + 1;
            }
        }
        forn (i, tail)
            used[q[i]]++, ans[q[i]] += d[q[i]], d[q[i]] = INF;
    }
    int minn = INF;
    forn (i, MAX)
        if (used[i] == n)
            minn = min(minn, ans[i]);
    printf("%d\n", minn);
    return 0;
}