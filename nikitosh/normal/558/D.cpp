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

vector <pair <LL, LL> > v;
vector <LL> ans;

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int h, q;
    scanf("%d%d", &h, &q);
    LL maxL = 1ll << (h - 1), minR = (1LL << h) - 1;
    forn (qq, q)
    {
        int ind, ans;
        LL l, r;
        scanf("%d" I64 I64 "%d", &ind, &l, &r, &ans);
        for (int i = ind; i < h; i++)
            l *= 2, r = (2 * r + 1);
        if (ans)
        {
            maxL = max(maxL, l);
            minR = min(minR, r);
        }
        else
            v.pb(mp(l, r));
    }
    if (maxL > minR)
    {
        puts("Game cheated!");
        return 0;
    }
    sort(all(v));
    for (auto s : v)
    {
        if (s.fs > maxL)
        {
            if (s.fs > maxL + 1 && minR >= maxL + 1)
            {
                puts("Data not sufficient!");
                return 0;
            }
            ans.pb(maxL);
        }
        maxL = max(maxL, s.sc + 1);
        if (maxL > minR)
            break;
    }
    if (maxL <= minR)
    {
        if (maxL + 1 <= minR)
        {
            puts("Data not sufficient!");
            return 0;
        }
        ans.pb(maxL);
    }
    if (sz(ans) == 0)
    {
        puts("Game cheated!");
        return 0;
    }
    if (sz(ans) > 1)
    {
        puts("Data not sufficient!");
        return 0;
    }
    printf("%I64d\n", ans[0]);
    return 0;
}