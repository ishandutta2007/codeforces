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

const int P = 1e9 + 7, Q = 1073676287;
const int MAXN = 1e5 + 5;
const int PRIME = 239017;

int toPush[4 * MAXN];
char s[MAXN];

inline int add(int x, int mod)
{
    return x >= mod ? x - mod : x;
}

inline int sub(int x, int mod)
{
    return x < 0 ? x + mod : x;
}

struct H
{
    int a, b;
    H(): a(0), b(0) {}
    H(int a): a(a), b(a) {}
    H(int a, int b): a(a), b(b) {}
    H operator+(const H &h) const
    {
        return H(add(a + h.a, P), add(b + h.b, Q));
    }
    H operator-(const H &h) const
    {
        return H(sub(a - h.a, P), sub(b - h.b, Q));
    }
    H operator*(const H &h) const
    {
        return H((a * 1ll * h.a) % P, (b * 1ll * h.b) % Q);
    }
    bool operator==(const H &h) const
    {
        return a == h.a && b == h.b;
    }
};

H divHash;
H t[4 * MAXN], power[MAXN], h[MAXN];

int binPower(int a, int n, int mod)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        int s = binPower(a, n / 2, mod);
        return (s * 1ll * s) % mod;
    }
    return (binPower(a, n - 1, mod) * 1ll * a) % mod;
}

void push(int v, int ll, int rr)
{
    if (toPush[v] != -1)
    {
        if (ll != rr - 1)
            forn (j, 2)
                toPush[2 * v + j] = toPush[v];
        //printf("push %d %d\n", ((power[rr - ll] - 1) * divHash).a, ((power[rr - ll] - 1) * divHash).b);
        t[v] = H(toPush[v]) * power[ll] * (power[rr - ll] - 1) * divHash;
        toPush[v] = -1;
    } 
}

H get(int v, int ll, int rr, int l, int r)
{
    push(v, ll, rr);
    if (ll >= l && rr <= r)
    {
        //printf("%d %d %d %d %d %d\n", ll, rr, l, r, t[v].a, t[v].b);
        return t[v];
    }
    if (ll >= r || l >= rr)
        return 0;
    int mm = (ll + rr) / 2;
    return get(2 * v, ll, mm, l, r) + get(2 * v + 1, mm, rr, l, r);
}

void update(int v, int ll, int rr, int l, int r, int x)
{
    if (ll >= l && rr <= r)
    {
        toPush[v] = x;
        push(v, ll, rr);
        return;
    }
    push(v, ll, rr);
    if (ll >= r || l >= rr)
        return;
    int mm = (ll + rr) / 2;
    update(2 * v, ll, mm, l, r, x);
    update(2 * v + 1, mm, rr, l, r, x);
    t[v] = t[2 * v] + t[2 * v + 1];
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, m, k;
    scanf("%d%d%d\n", &n, &m, &k);
    int q = m + k;
    gets(s);
    power[0] = 1;
    forab (i, 1, n + 1)
        power[i] = power[i - 1] * H(PRIME);
    divHash = H(binPower(PRIME - 1, P - 2, P), binPower(PRIME - 1, Q - 2, Q));
    forn (i, n)
        h[i + 1] = power[i] * s[i];
    int tSize = 1;
    while (tSize <= n)
        tSize *= 2;
    forn (i, 2 * tSize)
        toPush[i] = -1;
    forn (i, n + 1)
        t[tSize + i] = h[i + 1];
    forba (i, 1, tSize)
        t[i] = t[2 * i] + t[2 * i + 1];
    //forn (i, 2)
    //    printf("%d %d\n", (get(1, 0, tSize, i, i + 1) * power[1 - i]).a, (get(1, 0, tSize, i, i + 1) * power[1 - i]).b);
    //puts("STOP IT"); 
    forn (qq, q)
    {
        int type, l, r, x;
        scanf("%d%d%d%d", &type, &l, &r, &x);
        l--;
        if (type == 2)
        {
            H hash1 = get(1, 0, tSize, l, r - x) * power[x], hash2 = get(1, 0, tSize, l + x, r);
            if (get(1, 0, tSize, l, r - x) * power[x] == get(1, 0, tSize, l + x, r))
                puts("YES");
            else
                puts("NO");    
        }
        else
        {
            update(1, 0, tSize, l, r, int(x + '0'));
        }
    }                    
    return 0;
}