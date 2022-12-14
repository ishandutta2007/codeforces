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
const int MAXK = 5;

int type[MAXN], res[MAXN], num[MAXN], last[MAXN], first[MAXN];
char s[MAXN];
vi u[2][2], v[2][2], cnt[MAXK], lst[MAXN];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    gets(s);
    int n = strlen(s);
    forn (i, n)
        if (s[i] == 'L')
            type[i] = 0;
        else
            type[i] = 1;
    int ans = 0;
    forn (i, n)
    {
        if (sz(cnt[type[i]]) > 0)
        {
            int k = cnt[type[i]].back();
            num[i] = num[k];
            last[num[i]] = i;
            cnt[type[i]].pop_back();
            cnt[type[i] ^ 1].push_back(i);
        }
        else
        {
            ans++, cnt[type[i] ^ 1].push_back(i);
            num[i] = ans;
            first[ans] = i;
        }
        lst[num[i]].pb(i);
    } 
    forab (i, 1, ans + 1)
    {
        v[type[first[i]]][type[last[i]]].pb(i);
        //printf("%d %d\n", first[i], last[i]);
    }
    while (sz(v[0][1]) > 0 && sz(v[1][0]) > 0)
    {
        int k = v[0][1].back();
        v[0][1].pop_back();
        int l = v[1][0].back();
        v[1][0].pop_back();
        //printf("k = %d l = %d\n", k, l);
        if (last[k] > last[l])
        {
            int num = lst[k].back();
            lst[k].pop_back();
            lst[l].pb(num);
            v[0][0].pb(k);
            v[1][1].pb(l);
        }
        else
        {
            int num = lst[l].back();
            lst[l].pop_back();
            lst[k].pb(num);
            v[0][0].pb(k);
            v[1][1].pb(l);
        }
    }
    printf("%d\n", ans - 1);
    forn (j, 2)
    {
        int mov = 0;
        forn (x, 2)
            forn (y, 2)
                u[x][y] = v[x][y];
        int cur = j;
        //eprintf("sz %d %d\n", sz(u[cur][0]), sz(u[cur][1]));
        while(1)
        {

        if (sz(u[cur][0]) == 0 && sz(u[cur][1]) == 0)
        {
            if (sz(u[cur ^ 1][0]) == 0 && sz(u[cur ^ 1][1]) == 0)
            {
                forn (i, n)
                    printf("%d ", res[i] + 1);
                puts("");
                return 0;
            }
            else
                break;
        }
        int cur2 = cur ^ 1;
        if (sz(u[cur][cur2]) == 0)
            cur2 = cur; 
        //eprintf("%d %d\n", cur, cur2);
        int k = u[cur][cur2].back();
        u[cur][cur2].pop_back();
        for (int z : lst[k])
            res[mov++] = z;
        cur = type[lst[k].back()] ^ 1;
        //printf("%d\n", cur);
        }
    }
    assert(0);
    return 0;
}