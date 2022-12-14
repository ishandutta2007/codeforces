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

vector <vi> v1, v2;
char s[MAXN], t[MAXN];
int a[MAXN], b[MAXN];
map <string, int> m;

bool foo(int n, int len)
{
    if (n == 0)
        return 1;
    for (int i = 0; i < len; i += n)
    {
        vi cnt1(n), cnt2(n);
        forab (j, i, i + n)
            cnt1[j - i] = a[j], cnt2[j - i] = b[j];
        sort(all(cnt1));
        sort(all(cnt2));
        v1.pb(cnt1), v2.pb(cnt2);
    } 
    sort(all(v1));
    sort(all(v2));
    bool ok = 1;
    forn (i, sz(v1))
        if (v1[i] != v2[i])
            ok = 0;
    if (!ok)
        return 0;
    return foo(n / 2, len);
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    gets(s);
    gets(t);
    int n = strlen(s);
    int n2 = n;
    int curCnt = 0;
    while (n2 % 2 == 0)
        n2 /= 2;
    for (int i = 0; i < n; i += n2)
    {
        string r1, r2;
        r1.resize(n2);
        r2.resize(n2);
        forab (j, i, i + n2)
            r1[j - i] = s[j], r2[j - i] = t[j];
        if (!m.count(r1))
            m[r1] = curCnt++;
        if (!m.count(r2))
            m[r2] = curCnt++;
        a[i / n2] = m[r1];
        b[i / n2] = m[r2];
    }       
    if (foo(n / n2, n / n2))
        puts("YES");
    else
        puts("NO");
    return 0;
}