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

const int COUNT = 100;

struct Line
{
    int a, b, c, ind;
    Line(int a, int b, int c, int ind): a(a), b(b), c(c), ind(ind) {}
};

pair <bool, vector <pii> > get(vector <Line> v, int k)
{
    if (sz(v) <= k)
    {
        vector <pii> ans;
        for (Line l : v)
            ans.pb(mp(l.ind, -1));
        return mp(1, ans);    
    }
    if (k == 0)
        return mp(0, vector<pii>({}));
    forn (qq, COUNT)
    {
        int p = rand() % sz(v), q = rand() % sz(v);
        if (p != q && v[p].b * 1ll * v[q].a != v[p].a * 1ll * v[q].b)
        {
            LL y = (v[p].a * 1ll * v[q].c - v[p].c * v[q].a);            
            LL x = -(v[p].b * 1ll * v[q].c - v[p].c * v[q].b);
            LL z = (v[p].b * 1ll * v[q].a - v[p].a * v[q].b);
            int cnt = 0;
            for (Line l : v)
                if (l.a * 1ll * x + l.b * 1ll * y + l.c * 1ll * z == 0)
                    cnt++;

            if (cnt > k || (sz(v) <= 30 * k * k))
            {
                vector <Line> u;
                for (Line l : v)
                    if (l.a * 1ll * x + l.b * 1ll * y + l.c * 1ll * z != 0)
                        u.pb(l);
                auto ans = get(u, k - 1);
                if (ans.fs)
                {
                    ans.sc.pb(mp(v[p].ind, v[q].ind));
                    return mp(1, ans.sc);
                }
                else if (cnt > k)
                    return mp(0, vector<pii>({}));                        
            }
        }
    }
    return mp(0, vector<pii>({}));
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, k;
    scanf("%d%d", &n, &k);    
    vector <Line> v;
    forn (i, n)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        v.pb(Line(a, b, c, i + 1));
    }
    auto ans = get(v, k);
    if (!ans.fs)
    {
        puts("NO");
        return 0;
    }   
    puts("YES");
    printf("%d\n", sz(ans.sc));
    for (auto np : ans.sc)
        printf("%d %d\n", np.fs, np.sc);
    return 0;
}