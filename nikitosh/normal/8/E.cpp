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

const int MAXN = (1 << 16);

int rev[MAXN];

int revers(int k, int n)
{
    if (n % 2 == 0)
        return (rev[k & ((1 << (n / 2)) - 1)] << (n / 2)) + rev[k >> (n / 2)];
    return (rev[k & ((1 << (n / 2)) - 1)] << (n / 2 + 1)) + rev[k >> (n / 2 + 1)] + (k & (1 << (n / 2)));
}

void print(int k, int n)
{
    vi v;
    forn (i, n)
        v.pb(k % 2), k /= 2;
    reverse(all(v));
    for (auto k : v)
        printf("%d", k);
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    LL k;
    scanf("%d" I64, &n, &k);
    k++;
    for (int i = 0; i < (1 << (n / 2 / 2)); i++)
    {
        int k = i;
        int ans = 0;
        forn (j, n / 2 / 2)
            ans = ans * 2 + k % 2, k /= 2;
        rev[i] = ans;
    }
    if (n % 2 == 0)
    {
        int N = 1 << (n / 2);
        for (int i = 0; i < N; i++)
            if (k > N - 2 * i)
                k -= N - 2 * i;
            else
            {
                forn (j, N)
                    if (revers(j, n / 2) >= i && revers(N - j - 1, n / 2) >= i)
                    {
                        k--;
                        if (k == 0)
                        {
                            print(i, n / 2);
                            print(j, n / 2);
                            return 0;
                        }
                    }
            } 
    }
    else
    {
        int N = 1 << (n / 2);
        for (int i = 0; i < N; i++)
            if (k > 2 * (N - 2 * i) - 1)
                k -= 2 * (N - 2 * i) - 1;
            else
            {
                forn(g, 2)
                forn (j, N)
                    if (revers(j, n / 2) >= i && revers(N - j - 1, n / 2) >= i + g)
                    {
                        k--;
                        if (k == 0)
                        {
                            print(i, n / 2);
                            printf("%d", g);
                            print(j, n / 2);
                            return 0;
                        }
                    }
            } 
    }
    if (k > 0)
        puts("-1");
    return 0;
}