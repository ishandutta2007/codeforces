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

const int MAXN = 4e5;

pii a[MAXN], b1[MAXN], b2[MAXN];
int sumPr[MAXN], sumSuf[MAXN];

bool cmp(pii a, pii b)
{
    if (a.sc == 0)
        return 0;
    if (b.sc == 0)
        return 1;
    int cur = 0;
    if (a.sc < 0)
        cur ^= 1;
    if (b.sc < 0)
        cur ^= 1;
    LL s = a.fs * 1ll * b.sc;
    LL r = a.sc * 1ll * b.fs;
    if (s == r)
        return 0;
    return (s < r) ^ cur;  
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, c, d;
    LL ans = 0;
    scanf("%d%d%d", &n, &c, &d);
    forn (i, n)
        scanf("%d%d", &a[i].fs, &a[i].sc), a[i].fs -= c, a[i].sc -= d;
    sort(a, a + n, cmp);
    int last = n;
    forn (i, n)
        if (a[i].sc == 0)
        {
            last = i;
            break;
        }
    forn (i, n)
        sumPr[i + 1] = sumPr[i] + (a[i].sc < 0);
    fornr (i, last)
        sumSuf[i] = sumSuf[i + 1] + (a[i].sc < 0);
    forn (i, last)
    {
        if (a[i].sc > 0)
        {
            int l = 0, r = 0;
            int k = lower_bound(a, a + last, a[i], cmp) - a;
            if (k != 0)
                l = sumPr[k];
            k = upper_bound(a, a + last, a[i], cmp) - a;
            if (k != last)
                r = sumSuf[k];
            ans += l * 1ll * r;
        }
        else
        {
            int l = 0, r = 0;
            int k = lower_bound(a, a + last, a[i], cmp) - a;
            if (k != 0)
                l = (k - sumPr[k]);
            k = upper_bound(a, a + last, a[i], cmp) - a;
            if (k != last)
                r = (last - k - sumSuf[k]);
            ans += l * 1ll * r;
        }
    }
    int pos1 = 0, pos2 = 0;
    forn (i, last)
        if (a[i].sc > 0)
            b1[pos1++] = a[i];
        else
            b2[pos2++] = a[i];
    LL ans1 = 0, ans2 = 0;
    forn (i, pos1)
    {
        int l = upper_bound(b2, b2 + pos2, b1[i], cmp) - b2;
        ans1 += pos2 - l;
    }
    forn (i, pos2)
    {
        int l = upper_bound(b1, b1 + pos1, b2[i], cmp) - b1;
        ans2 += pos1 - l;
    }
    forab (i, last, n)
    {
        if (a[i].fs > 0)
            ans += ans1;
        if (a[i].fs < 0)
            ans += ans2;
    }
    printf(I64 "\n", ans);
    return 0;
}