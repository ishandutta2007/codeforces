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

const int MAXN = 1024;

int size[MAXN], in[MAXN], deg[MAXN];
bitset <MAXN> a[MAXN], c;
vector <pii> edges;
set <pii> was;

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    scanf("%d", &n);
    bool star = 1;
    forn (i, n)
    {
        scanf("%d", &size[i]);
        if (size[i] != n)
            star = 0;
        forn (j, size[i])
        {
            int l;
            scanf("%d", &l);
            a[i][l - 1] = 1;
        }
    }
    if (star)
    {
        forn (i, n - 1)
            printf("%d %d\n", i + 1, n);
        return 0;
    }
    forn (i, n)
        forab (j, i + 1, n)
        {
            c = a[i] & a[j];
            unsigned int *cur = (unsigned int *) &c;
            vi v;
            forn (g, MAXN / 32)
            {
                if (*cur != 0)
                {
                    fornr (k, 32)
                        if (((*cur) >> k) & 1)
                            v.pb(g * 32 + k);
                    if (sz(v) > 2)
                        break;
                }
                cur++;
            }
            if (sz(v) == 2)
                edges.pb(mp(v[0], v[1]));
        }
    sort(all(edges));
    edges.resize(unique(all(edges)) - edges.begin());
    for (auto edge : edges)
    {
        in[edge.fs] = in[edge.sc] = 1;
        deg[edge.fs]++, deg[edge.sc]++;
        was.insert(mp(edge.fs, edge.sc));
        was.insert(mp(edge.sc, edge.fs));
    }
    forn (i, n)
        if (!in[i])
        {
            int minn = 2 * n, ind = -1;
            forn (j, n)
                if (a[j][i] == 1 && size[j] < minn)
                {
                    minn = min(minn, size[j]);
                    ind = j;
                }
            assert(ind != -1);
            vi vIn;
            forn (j, n)
                if (a[ind][j] && in[j])
                    vIn.pb(j);
            if (sz(vIn) > 2)
            {
                forn (j, sz(vIn))
                {
                    bool ok = 1;
                    forn (g, sz(vIn))
                    {
                        if (g != j && !was.count(mp(vIn[j], vIn[g])))
                        {
                            ok = 0;
                            break;
                        }
                    }
                    if (ok)
                    {
                        edges.pb(mp(vIn[j], i));
                        break;
                    }
                }
            }
            else
            {
                assert(sz(vIn) == 2);
                assert(deg[vIn[0]] == 1 || deg[vIn[1]] == 1);
                if (deg[vIn[0]] == 1 && deg[vIn[1]] == 1)
                {
                    int ind2 = -1;
                    forn (j, n)
                        if (size[j] != n)
                        {
                            ind2 = j;
                            break;
                        }
                    //printf("%d %d\n", ind, i);
                    assert(ind != -1);
                    if (a[ind2] == a[ind])
                        edges.pb(mp(vIn[0], i));
                    else
                        edges.pb(mp(vIn[1], i));
                }
                else
                {
                    forn (j, 2)
                        if (deg[vIn[j]] == 1)
                            edges.pb(mp(vIn[j], i));
                }
            }
        }
    for (auto edge : edges)
        printf("%d %d\n", edge.fs + 1, edge.sc + 1);
    return 0;
}