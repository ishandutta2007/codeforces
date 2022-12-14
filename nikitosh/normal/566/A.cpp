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

const int mod1 = 1e9 + 7, mod2 = 1e9 + 9, p = 239017;
const int MAXN = 8e5 + 5;

char t[MAXN];
vector <char> s[MAXN];
int len[MAXN], perm[MAXN], pr[MAXN], type[MAXN];
set <int> ss;
set <pii> diff;

inline int takePlus(int p, int mod)
{
    if (p >= mod)
        p -= mod;
    return p;
}

inline int takeMinus(int p, int mod)
{
    if (p < 0)
        p += mod;
    return p;
}

struct Hash
{
    int p, q;
    Hash(): p(0), q(0) {}
    Hash(int p): p(p), q(p) {}
    Hash(int p, int q): p(p), q(q) {}
    Hash& operator = (const Hash &a)
    {
        p = a.p;
        q = a.q;
        return *this;
    }
    Hash& operator = (int a)
    {
        p = a;
        q = a;
        return *this;
    }
    bool operator == (const Hash &a) const
    {
        return (p == a.p && q == a.q);
    }
    bool operator != (const Hash &a) const
    {
        return (p != a.p || q != a.q);
    }
    bool operator < (const Hash &a) const
    {
        return (p < a.p || (p == a.p && q < a.q));
    }
    Hash operator + (const Hash &a) const
    {
        return Hash(takePlus(p + a.p, mod1), takePlus(q + a.q, mod2));
    }
    Hash operator - (const Hash &a) const
    {
        return Hash(takeMinus(p - a.p, mod1), takeMinus(q - a.q, mod2));
    }
    Hash operator * (int a) const
    {
        return Hash((p * 1ll * a) % mod1, (q * 1ll * a) % mod2);
    }
    Hash operator * (const Hash &a) const
    {
        return Hash((p * 1ll * a.p) % mod1, (q * 1ll * a.q) % mod2);
    }
};

vector <Hash> h[MAXN + 5];
Hash ps[MAXN + 5];

inline Hash getHash(int ind, int l, int r) //[l;r)
{
    return h[ind][r] - h[ind][l] * ps[r - l];
}

int lcp(int i, int j)
{
    int l = 0, r = min(len[i], len[j]) + 1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (getHash(i, 0, m) == getHash(j, 0, m))
            l = m;
        else
            r = m;
    } 
    return l;
}

bool comp(int i, int j)
{
    int l = lcp(i, j);
    if (l == len[i] && l == len[j])
        return 0;
    if (l == len[i] || (l < len[j] && s[i][l] < s[j][l]))
        return 1;
    return 0;
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    ps[0] = 1;
    for (int i = 1; i < MAXN; i++)
        ps[i] = ps[i - 1] * p; 
    int n;
    scanf("%d\n", &n);
    forn (i, 2 * n)
    {
        gets(t);
        len[i] = strlen(t);
        s[i].resize(len[i]);
        forn (j, len[i])
            s[i][j] = t[j];
        h[i].resize(len[i] + 1);
        forn (j, len[i])
            h[i][j + 1] = h[i][j] * p + t[j];
    }
    forn (i, 2 * n)
        perm[i] = i;
    sort(perm, perm + 2 * n, comp);
    forn (i, 2 * n)
        if (perm[i] < n)
            type[i] = 0;
        else
            type[i] = 1;
    forn (i, 2 * n)
        ss.insert(i); 
    forab (i, 1, 2 * n)
        if (type[i] + type[i - 1] == 1)
            diff.insert(mp(lcp(perm[i], perm[i - 1]), i - 1));
    LL ans = 0;
    forn (qq, n)
    {
        auto deleteIt = diff.end();
        deleteIt--;
        int lc = deleteIt->fs, v = deleteIt->sc;
        diff.erase(deleteIt);
        auto it = ss.find(v);
        if (it != ss.begin())
        {
            auto it2 = it;
            it2--;
            if (type[*it] != type[*it2])
                diff.erase(mp(lcp(perm[*it], perm[*it2]), *it2));
        }
        auto endIt = ss.end();
        endIt--;
        it++;
        ans += lc;
        if (type[v] == 0)
            pr[perm[v]] = perm[*it] - n;
        else
            pr[perm[*it]] = perm[v] - n;
        if (it != endIt)
        {
            auto it2 = it;
            it2++;
            if (type[*it] != type[*it2])
                diff.erase(mp(lcp(perm[*it], perm[*it2]), *it));
        }
        ss.erase(it);
        ss.erase(v);
        it = ss.lower_bound(v);
        if (it != ss.begin() && it != ss.end())
        {
            auto it2 = it;
            it2--;
            if (type[*it] != type[*it2])
            {
                diff.insert(mp(lcp(perm[*it], perm[*it2]), *it2));
            }
        }
    }
    printf(I64 "\n", ans);
    forn (i, n)
        printf("%d %d\n", i + 1, pr[i] + 1);
    return 0;
}