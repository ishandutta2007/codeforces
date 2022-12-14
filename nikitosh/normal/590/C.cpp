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

const int INF = 1e8;

const int MAXN = 1005, MAXK = 4;
const int turn[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char s[MAXN][MAXN];
int d[MAXN][MAXN], dist[MAXK][MAXN][MAXN], used[MAXN][MAXN], betw[MAXK][MAXK];
pii q[MAXN * MAXN];

bool good(int x, int y, int n, int m)
{
    return x >= 0 && y >= 0 && x < n && y < m && s[x][y] != '#';
}

void bfs(char c, int n, int m)
{
    int head = 0, tail = 0;
    forn (i, n)
        forn (j, m)
            d[i][j] = INF, used[i][j] = 0;
    forn (i, n)
        forn (j, m)
            if (s[i][j] == c)
                q[tail++] = mp(i, j), d[i][j] = 0, used[i][j] = 1;
    while (tail > head)
    {
        auto np = q[head++];
        int x = np.fs, y = np.sc;
        forn (g, 4)
        {
            int dx = x + turn[g][0], dy = y + turn[g][1];
            if (good(dx, dy, n, m) && !used[dx][dy])
            {
                used[dx][dy] = 1;
                d[dx][dy] = d[x][y] + 1;
                q[tail++] = mp(dx, dy);
            }
        }
    }
    forn (i, n)
        forn (j, m)
        {
            if (d[i][j] > 0)
                d[i][j]--;
            dist[c - '1'][i][j] = d[i][j];
            if (s[i][j] >= '1' && s[i][j] <= '3')
                betw[c - '1'][s[i][j] - '1'] = min(betw[c - '1'][s[i][j] - '1'], d[i][j]);
        }
}

int main() 
{
#ifdef LOCAL    
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
#endif    
    int n, m;
    scanf("%d%d\n", &n, &m);
    forn (i, n)
        gets(s[i]);
    forn (i, 3)
        forn (j, 3)
            betw[i][j] = INF;
    for (char c = '1'; c <= '3'; c++)
        bfs(c, n, m);
    int ans = INF;
    ans = min(ans, betw[0][1] + betw[0][2]);         
    ans = min(ans, betw[1][0] + betw[1][2]);         
    ans = min(ans, betw[2][0] + betw[2][1]);
    forn (i, n)
        forn (j, m)
            ans = min(ans, 1 + dist[0][i][j] + dist[1][i][j] + dist[2][i][j]);        
    if (ans >= INF - 10)
        ans = -1;
    printf("%d\n", ans);
    return 0;
}