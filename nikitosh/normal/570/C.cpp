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

const int MAXN = 3e5 + 5, INF = 1e9;
        
char s[MAXN];
set <pii> segm;

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, q;
    scanf("%d%d\n", &n, &q);
    gets(s);
    int last = 0, cnt = 0;
    forn (i, n)
    {
        if (s[i] == '.')
            cnt++;
        if (s[i] == '.' && (i == 0 || s[i - 1] != '.'))
            last = i;
        if (s[i] == '.' && (i == n - 1 || s[i + 1] != '.'))
            segm.insert(mp(last, i)); 
    }
    forn (qq, q)
    {
        int ind;
        char ch;
        scanf("%d %c", &ind, &ch);
        ind--;
        if (s[ind] == '.')
        {
            auto it = segm.lower_bound(mp(ind, INF));
            it--;
            int l = it->fs, r = it->sc;
            segm.erase(it);
            if (l != ind)
                segm.insert(mp(l, ind - 1));
            if (r != ind)
                segm.insert(mp(ind + 1, r));    
            cnt--;
        }
        if (ch == '.')
        {
            int l = ind, r = ind;
            auto it = segm.lower_bound(mp(ind, INF));
            if (it != segm.begin())
            {
                it--;
                if (it->sc == ind - 1)
                {
                    l = it->fs;
                    segm.erase(it);
                    it = segm.lower_bound(mp(ind, INF));
                }
                else
                    it++;
            }
            if (it != segm.end() && it->fs == ind + 1)
                r = it->sc, segm.erase(it);    
            segm.insert(mp(l, r));
            cnt++;            
        }
        s[ind] = ch;
        printf("%d\n", cnt - sz(segm));
    }
    return 0;
}