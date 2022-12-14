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

const int MAXN = 1005;
const char* ALPHA = "VC";

int was[MAXN], used[MAXN], comp[MAXN], wasSymb[2];
char s[MAXN], t[MAXN];
vi g[MAXN], curG[MAXN], curGr[MAXN], st;

void color(int v, bool &bad)
{
    //printf("colro %d\n", v);
    if (was[v ^ 1])
        bad = 1;
    used[v / 2] = v % 2;
    was[v] = 1;
    for (int u : g[v])
        if (was[u] == 0)
            color(u, bad);
}

void dfs(int v)
{
    was[v] = 1;
    for (int u : curG[v])
        if (!was[u])
            dfs(u);
    st.pb(v);
}

void revDfs(int v, int compNumber)
{
    was[v] = 1;
    comp[v] = compNumber;
    for (int u : curGr[v])
        if (!was[u])
            revDfs(u, compNumber);
}

bool solve(int i, int num, int n)
{
    //printf("%d %d\n", i, num);
    forn (j, n)
        used[j] = -1;
    forn (j, 2 * n)
        was[j] = 0;
    bool bad = 0;
    forn (j, i)
        color(2 * j + (strchr(ALPHA, s[t[j] - 'a']) - ALPHA), bad);
    color(2 * i + num, bad);
    if (bad)
        return 0;
    forn (j, 2 * n)
        curG[j].clear(), curGr[j].clear();
    forn (j, 2 * n)
    {
        if (used[j / 2] == -1)
            for (int u : g[j])
                if (used[u / 2] == -1)
                    curG[j].pb(u), curGr[u].pb(j);        
    }
    st.clear();
    forn (j, 2 * n)
        was[j] = 0;
    forn (j, 2 * n)
        if (used[j / 2] == -1 && !was[j])
            dfs(j);
    forn (j, 2 * n)
        was[j] = 0;
    reverse(all(st));
    int compNumber = 0;
    for (int v : st)
        if (!was[v])
            revDfs(v, compNumber++);
    bool ok = 1;
    forn (j, n)
        if (used[j] == -1 && comp[2 * j] == comp[2 * j + 1])
            ok = 0;    
    return ok;        
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    gets(s);
    int len = strlen(s);
    bool wasV = 0, wasC = 0;
    forn (i, len)
    {
        if (s[i] == 'V')
            wasV = 1;
        if (s[i] == 'C')
            wasC = 1;
    }         
    int n, m;
    scanf("%d%d", &n, &m);    
    forn (i, m)
    {
        int v, u;
        char c1, c2;
        scanf("%d %c %d %c", &v, &c1, &u, &c2);
        v--, u--;
        int bool1 = strchr(ALPHA, c1) - ALPHA;
        int bool2 = strchr(ALPHA, c2) - ALPHA;
        g[2 * v + bool1].pb(2 * u + bool2);
        g[2 * u + 1 - bool2].pb(2 * v + 1 - bool1);
    }
    scanf("\n");
    gets(t);
    bool ok = 1;
    forn (i, n)
    {
        int v = 2 * i + (strchr(ALPHA, s[t[i] - 'a']) - ALPHA);
        for (int u : g[v])
            if (strchr(ALPHA, s[t[u / 2] - 'a']) - ALPHA != u % 2)
                ok = 0;
    }
    if (ok)
    {
        puts(t);
        return 0;
    }
    if (!wasV || !wasC)
    {
        puts("-1");
        return 0;
    }
    int pref = -1;
    fornr (i, n)
    {
        wasSymb[0] = wasSymb[1] = 0;
        int beg = t[i] - 'a';
        bool found = 0;
        forab (g, beg + 1, len)
        {
            int num = strchr(ALPHA, s[g]) - ALPHA;
            if (!wasSymb[num])
            {
                wasSymb[num] = 1;
                if (solve(i, num, n))
                {
                    t[i] = 'a' + g;
                    found = 1;
                    break;
                }
            }
        }
        if (found)
        {
            pref = i;
            break;
        }
    }
    if (pref == -1)
    {
        puts("-1");
        return 0;
    }
    //printf("pref = %d\n", pref);
    forab (i, pref + 1, n)
    {
        wasSymb[0] = wasSymb[1] = 0;
        forab (g, 0, len)
        {
            int num = strchr(ALPHA, s[g]) - ALPHA;
            if (!wasSymb[num])
            {
                wasSymb[num] = 1;
                if (solve(i, num, n))
                {
                    t[i] = 'a' + g;
                    break;
                }
            }
        }
    }
    puts(t);
    return 0;
}