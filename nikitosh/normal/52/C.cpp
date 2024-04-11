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

const int MAXN = 2e5 + 5;
const LL INF = 1e18;

int a[MAXN];
char s[MAXN];
vector <pii> seg;
LL t[4 * MAXN], add[4 * MAXN];

void push(int v, int ll, int rr)
{
    if (ll != rr - 1)
        forn (j, 2)
            add[2 * v + j] += add[v];
    t[v] += add[v];
    add[v] = 0;
}

LL get(int v, int ll, int rr, int l, int r)
{
    push(v, ll, rr);
    if (ll >= l && rr <= r)
        return t[v];
    if (ll >= r || l >= rr)
        return INF;
    int mm = (ll + rr) / 2;
    return min(get(2 * v, ll, mm, l, r), get(2 * v + 1, mm, rr, l, r));
}

void update(int v, int ll, int rr, int l, int r, int x)
{
    if (ll >= l && rr <= r)
    {
        add[v] += x;
        push(v, ll, rr);
        return;       
    }
    push(v, ll, rr);
    if (ll >= r || l >= rr)
        return;
    int mm = (ll + rr) / 2;
    update(2 * v, ll, mm, l, r, x);
    update(2 * v + 1, mm, rr, l, r, x);
    t[v] = min(t[2 * v], t[2 * v + 1]);
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, q;
    scanf("%d", &n);
    forn (i, n)
        scanf("%d", &a[i]);
    int N = 1;
    while (N < n)
        N *= 2;
    forn (i, 2 * N)
        t[i] = INF;
    forn (i, n)
        t[N + i] = a[i];
    forba (i, 1, N)
        t[i] = min(t[2 * i], t[2 * i + 1]);
    scanf("%d", &q);
    forn (qq, q)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        seg.clear();
        if (l <= r)
            seg.pb(mp(l, r + 1));
        else
        {
            seg.pb(mp(l, n));
            seg.pb(mp(0, r + 1));
        } 
        gets(s);
        int len = strlen(s);
        bool flag = 0;
        forn (i, len)
            if (s[i] >= '0' && s[i] <= '9')
                flag = 1;
        if (flag)
        {
            int x;
            sscanf(s, "%d", &x);
            for (auto np : seg)
                update(1, 0, N, np.fs, np.sc, x);
        }
        else
        {
            LL minn = INF;
            for (auto np : seg)
                minn = min(minn, get(1, 0, N, np.fs, np.sc));
            printf(I64 "\n", minn);
        }
    }
    return 0;
}