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

const int MAXN = 2e5 + 5, ALPHA = 30, INF = 1e9;

char a[MAXN], s[2][MAXN];
int len[2], cnt[2][ALPHA], cntA[ALPHA], curCnt[ALPHA];

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    gets(a);
    forn (j, 2)
    {
        gets(s[j]);
        len[j] = strlen(s[j]);
        forn (i, len[j])
            cnt[j][s[j][i] - 'a']++;        
    }
    int n = strlen(a);
    forn (i, n)
        cntA[a[i] - 'a']++;
    int ans = 0, x = 0, y = 0;
    forn (i, n + 1)
    {
        bool ok = 1;
        forn (j, 26)
        {
            curCnt[j] = cntA[j] - i * cnt[0][j];
            if (curCnt[j] < 0)
            {
                ok = 0;
                break;
            }
        }
        if (!ok)
            break;
        int maxx = INF;
        forn (j, 26)
        {
            if (cnt[1][j] > 0)
                maxx = min(maxx, curCnt[j] / cnt[1][j]);
        }
        if (i + maxx > ans)
        {
            ans = i + maxx;
            x = i;
            y = maxx;
        }
    }
    forn (i, x)
        printf("%s", s[0]);
    forn (i, y)
        printf("%s", s[1]);
    forn (i, 26)
        forn (j, cntA[i] - x * cnt[0][i] - y * cnt[1][i])
            printf("%c", 'a' + i);
    puts("");
    return 0;
}