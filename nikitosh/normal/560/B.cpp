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

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int a, b, c1, d1, c2, d2;
    scanf("%d%d%d%d%d%d", &a, &b, &c1, &d1, &c2, &d2);
    bool flag = 0;
    forn (i, 2)
    {
        forn (j, 2)
        {
            if (c1 + c2 <= a && d1 <= b && d2 <= b)
                flag = 1;
            if (d1 + d2 <= b && c1 <= a && c2 <= a)
                flag = 1;
            swap(c2, d2);
        }
        swap(c1, d1);
    }
    if (flag)
        puts("YES");
    else
        puts("NO");
    return 0;
}