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

pair <int, pii> a[MAXN];
vi close[MAXN];
int cnt[MAXN], used[MAXN];
set <int> s;

int balance(int ind, int k)
{
    int bal = 0;
    if (a[ind].fs == k)
        bal--;
    if (a[ind].sc.fs == k)
        bal++;
    if (a[ind].sc.sc == k)
        bal++;
    return bal;
}

bool ok(int ind)
{
    bool ok = 1;
    if (cnt[a[ind].fs] + balance(ind, a[ind].fs) > 9)
        ok = 0;
    if (cnt[a[ind].sc.fs] + balance(ind, a[ind].sc.fs) > 9)
        ok = 0;
    if (cnt[a[ind].sc.sc] + balance(ind, a[ind].sc.sc) > 9)
        ok = 0;
    return ok;
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n;
    scanf("%d", &n);
    forn (i, 4 * n)
    {
        scanf("%d%d%d", &a[i].fs, &a[i].sc.fs, &a[i].sc.sc);
        close[a[i].sc.fs].pb(i);
        close[a[i].sc.sc].pb(i);
        cnt[a[i].fs]++;
        s.insert(i);
    }
    puts("YES");
    while(sz(s) > 0)
    {
        int ind = *s.begin();
        printf("%d ", ind + 1);
        used[ind] = 1;
        s.erase(s.begin());
        cnt[a[ind].fs]--;
        cnt[a[ind].sc.fs]++;
        cnt[a[ind].sc.sc]++;
        for (int j : close[a[ind].fs])
        {
            if (used[j])
                continue;
            if (ok(j))
                s.insert(j);
            else
                s.erase(j);
        }
        for (int j : close[a[ind].sc.fs])
        {
            if (used[j])
                continue;
            if (ok(j))
                s.insert(j);
            else
                s.erase(j);
        }
        for (int j : close[a[ind].sc.sc])
        {
            if (used[j])
                continue;
            if (ok(j))
                s.insert(j);
            else
                s.erase(j);
        }
    }
    return 0;
}