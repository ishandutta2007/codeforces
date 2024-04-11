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

int v[MAXN], u[MAXN], w[MAXN], cntS1[MAXN], cntT1[MAXN], cntS2[MAXN], cntT2[MAXN];
vector <pii> g[MAXN], gr[MAXN];
LL distS[MAXN], distT[MAXN];
set <pair <LL, int> > setDist;
vi primes;

bool prime(int k)
{
    for (int i = 2; i * i <= k; i++)
        if (k % i == 0)
            return 0;
    return 1;
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int cur = 1e9;
    for (;sz(primes) < 100; cur++)
        if (prime(cur))
            primes.pb(cur);
    int MOD1, MOD2;
    while (1)
    {
        int l = rand() % sz(primes), r = rand() % sz(primes);
        if (l == r)
            continue;
        MOD1 = primes[l], MOD2 = primes[r];
        break;
    }
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    s--, t--;
    forn (i, m)
    {
        scanf("%d%d%d", &v[i], &u[i], &w[i]);
        v[i]--, u[i]--;
        g[v[i]].pb(mp(u[i], w[i]));
        gr[u[i]].pb(mp(v[i], w[i]));
    }
    
    forn (i, n)
        distS[i] = INF, cntS1[i] = 0, cntS2[i] = 0;
    distS[s] = 0, cntS1[s] = 1, cntS2[s] = 1;
    forn (i, n)
        setDist.insert(mp(distS[i], i));
    forn (i, n)
    {
        int v = setDist.begin()->sc;
        setDist.erase(setDist.begin());
        for (auto np : g[v])
        {
            if (distS[np.fs] == distS[v] + np.sc)
            {
                cntS1[np.fs] = (cntS1[np.fs] + cntS1[v]) % MOD1;
                cntS2[np.fs] = (cntS2[np.fs] + cntS2[v]) % MOD2;
            }
            if (distS[np.fs] > distS[v] + np.sc)
            {
                setDist.erase(mp(distS[np.fs], np.fs));
                cntS1[np.fs] = cntS1[v];
                cntS2[np.fs] = cntS2[v];
                distS[np.fs] = distS[v] + np.sc;
                setDist.insert(mp(distS[np.fs], np.fs));
            }
        }
    }

    forn (i, n)
        distT[i] = INF, cntT1[i] = 0, cntT2[i] = 0;
    distT[t] = 0, cntT1[t] = 1, cntT2[t] = 1;
    forn (i, n)
        setDist.insert(mp(distT[i], i));
    forn (i, n)
    {
        int v = setDist.begin()->sc;
        setDist.erase(setDist.begin());
        for (auto np : gr[v])
        {
            if (distT[np.fs] == distT[v] + np.sc)
            {
                cntT1[np.fs] = (cntT1[np.fs] + cntT1[v]) % MOD1;
                cntT2[np.fs] = (cntT2[np.fs] + cntT2[v]) % MOD2;
            }
            if (distT[np.fs] > distT[v] + np.sc)
            {
                setDist.erase(mp(distT[np.fs], np.fs));
                cntT1[np.fs] = cntT1[v];
                cntT2[np.fs] = cntT2[v];
                distT[np.fs] = distT[v] + np.sc;
                setDist.insert(mp(distT[np.fs], np.fs));
            }
        }
    }

    forn (i, m)
    {
        if (distS[v[i]] + distT[u[i]] + w[i] == distS[t] && (cntS1[v[i]] * 1ll * cntT1[u[i]]) % MOD1 == cntS1[t] && (cntS2[v[i]] * 1ll * cntT2[u[i]]) % MOD2 == cntS2[t])
            puts("YES");
        else
        {
            LL dlt = distS[v[i]] + distT[u[i]] + w[i] - distS[t] + 1;
            if (w[i] >= dlt + 1)
                printf("CAN %I64d\n", dlt);
            else
                puts("NO");
        }
    }

    return 0;
}