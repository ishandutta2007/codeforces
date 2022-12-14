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

char s[MAXN], t[MAXN], ans[MAXN];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, k;
    scanf("%d%d\n", &n, &k);
    gets(s);
    gets(t);
    int cnt = 0, cnt2 = 0;
    forn (i, n)
        if (s[i] != t[i])
            cnt++;
    int minn = (cnt + 1) / 2;
    if (k < minn)
    {
        puts("-1");
        return 0;
    }         
    bool sw = 0;
    forn (i, n)
        if (s[i] == t[i])
            ans[i] = s[i];
        else
        {
            if (!sw)
                ans[i] = s[i];
            else
                ans[i] = t[i];
            if (sw == 0)
                k--;
            sw ^= 1;
            cnt2++;
            if (cnt2 == cnt && cnt % 2 == 1)
            {
                forn (g, 26)
                    if (s[i] != g + 'a' && t[i] != g + 'a')
                        ans[i] = g + 'a';
            }
        }
    forn (i, n)
        if (s[i] == t[i] && k > 0)
        {
            forn (g, 26)
                if (s[i] != g + 'a' && t[i] != g + 'a')
                    ans[i] = g + 'a';
            k--;
        }
    sw = 0;
    forn (i, n)
        if (k > 0 && s[i] != t[i])
        {
            forn (g, 26)
                if (s[i] != g + 'a' && t[i] != g + 'a')
                    ans[i] = g + 'a';
            sw ^= 1;
            if (sw == 0)
                k--;
        }
    puts(ans);
    return 0;
}