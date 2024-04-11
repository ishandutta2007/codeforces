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

const int MAXN = 5e5 + 5;

int pr[MAXN], rk[MAXN], nex[MAXN];
int n;
vi was;

int get(int v)
{
    if (v == pr[v])
        return v;
    return pr[v] = get(pr[v]);
}

int getNext(int v)
{
    if (nex[v] == n)
        return nex[v];
    if (get(v) != get(nex[v]))
        return nex[v];
    return nex[v] = getNext(nex[v]);
}
    
void join(int a, int b)
{
    a = get(a), b = get(b);
    if (a == b)
        return;
    if (rk[a] < rk[b])
        swap(a, b);
    pr[b] = a;
    if (rk[a] == rk[b])
        rk[a]++;
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int q;
    scanf("%d%d", &n, &q);
    forn (i, n)
        pr[i] = i, rk[i] = 0, nex[i] = i + 1;
    forn (qq, q)
    {
        int type, x, y;
        scanf("%d%d%d", &type, &x, &y);
        x--, y--;
        if (type == 3)
        {
            if (get(x) == get(y))
                puts("YES");
            else
                puts("NO");
        }
        if (type == 1)
            join(x, y); 
        if (type == 2)
        {
            was.clear();
            int cur = x;
            while (cur <= y)
            {
                was.pb(get(cur));
                cur = getNext(cur);
            }
            int maxx = -1, minK = -1;
            for (int k : was)
                if (rk[k] > maxx)
                {
                    maxx = rk[k];
                    minK = k;
                } 
            for (int k : was)
                if (k != minK)
                {
                    pr[k] = minK;
                    if (rk[k] == rk[minK])
                        rk[minK]++;
                } 
        }
    }
    return 0;
}