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
typedef pair <pair <int, int>, int> piii;

#define FNAME ""

const int MAXN = 2e5 + 5;

pii a[MAXN], b[MAXN];
piii c[MAXN];
vector <piii> st;

bool comp(piii a, piii b)
{
    if (a.fs.sc * 1ll * b.fs.fs == a.fs.fs * 1ll * b.fs.sc)
        return a.fs < b.fs;
    return a.fs.sc * 1ll * b.fs.fs > a.fs.fs * 1ll * b.fs.sc;
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    scanf("%d%d", &x, &y);
    forn (i, n)
        scanf("%d%d", &a[i].fs, &a[i].sc);
    int maxX = 0, maxY = 0;
    forn (i, m)
    {
        scanf("%d%d", &b[i].fs, &b[i].sc);
        maxX = max(maxX, b[i].fs);
        maxY = max(maxY, b[i].sc);
    }
    b[m++] = mp(0, maxY);
    b[m++] = mp(maxX, 0);
    forn (i, n)
        c[i] = mp(a[i], 0);
    forn(i, m)
        c[n + i] = mp(b[i], 1); 
    sort(c, c + n + m, comp);
    forn (i, n + m)
    {
        if (sz(st) > 0 && c[i].fs == st.back().fs)
        {
            st.back().sc = min(st.back().sc, c[i].sc);
            continue;
        }
        while (sz(st) > 1 && (st[sz(st) - 1].fs.fs - st[sz(st) - 2].fs.fs) * 1ll * (c[i].fs.sc - st[sz(st) - 1].fs.sc) > 
                             (st[sz(st) - 1].fs.sc - st[sz(st) - 2].fs.sc) * 1ll * (c[i].fs.fs - st[sz(st) - 1].fs.fs))
            st.pop_back();
        st.push_back(c[i]);
    }
    for (auto np : st)
        if (np.sc == 0)
        {
            puts("Max");
            return 0;
        }
    puts("Min");
    return 0;
}