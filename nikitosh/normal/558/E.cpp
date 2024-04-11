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

const int MAXN = 1e5 + 5;
const int INF = 1e9;

set <pair <pair <int, int>, int> > s;
char a[MAXN];
int cnt[MAXN];
vector <pair <pair <int, int>, int> > ans;

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, q;
    scanf("%d%d\n", &n, &q);
    gets(a);
    int last = 0;
    forn (i, n + 1)
        if (i != 0 && a[i] != a[i - 1])        
        {
            s.insert(mp(mp(last, i - 1), a[i - 1] - 'a'));
            last = i;
        }
    forn (qq, q)
    {
        int i, j, k;
        ans.clear();
        scanf("%d%d%d", &i, &j, &k);
        i--;
        j--;
        auto it = s.lower_bound(mp(mp(i, INF), INF));
        it--;
        auto it2 = s.lower_bound(mp(mp(j, INF), INF));
        it2--;
        if (*it == *it2)
            continue;
        //printf("%d %d\n", it2->fs.fs, it2->fs.sc);
        forn (j, 26)
            cnt[j] = 0;
        cnt[it->sc] += it->fs.sc - i + 1;
        if (i != it->fs.fs)
            ans.pb(mp(mp(it->fs.fs, i - 1), it->sc));
        cnt[it2->sc] += j - it2->fs.fs + 1;
        if (j != it->fs.sc)
            ans.pb(mp(mp(j + 1, it2->fs.sc), it2->sc));
        auto it3 = it;
        it3++;
        for (; it3 != it2; it3++)
            cnt[it3->sc] += it3->fs.sc - it3->fs.fs + 1;    
        it2++;
        s.erase(it, it2);
        int last = i;
        forn (g, 2)
            if (sz(ans) >= g + 1 && ans[g].fs.fs < i)
                s.insert(ans[g]);
        it = s.lower_bound(mp(mp(i, INF), INF));
        if (it != s.begin())
            it--;
        if (k == 1) 
        {
            forn (g, 26)
                if (cnt[g] != 0)
                    it = s.insert(it, mp(mp(last, last + cnt[g] - 1), g)), last += cnt[g];
        }
        else
        {
            fornr (g, 26)
                if (cnt[g] != 0)
                    it = s.insert(it, mp(mp(last, last + cnt[g] - 1), g)), last += cnt[g];
        }
        //printf("%d %d %d\n", sz(ans), ans[0].fs.fs, ans[0].fs.sc);
        forn (g, 2)
            if (sz(ans) >= g + 1 && ans[g].fs.sc > j)
                s.insert(it, ans[g]);
    }
    for (auto k : s)
    {
        forab (i, k.fs.fs, k.fs.sc + 1)
            printf("%c", k.sc + 'a');
    }
    puts("");
    return 0;
}