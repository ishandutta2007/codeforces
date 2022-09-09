/* --- Author: Vladimir Smykalov, enot.1.10@gmail.com --- */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;

/* --- main part --- */

#define TASK "a"

const int maxn = 110;
char s1[maxn];
char s2[maxn];
char vv[maxn];

int x[maxn][26];
int dp[maxn][maxn][maxn];
pair<pi, int> prev[maxn][maxn][maxn];

char res[maxn];
int resc = 0;

char tmp[maxn];

inline void upd(int x, int y, int k, int val, int xx, int yy, int kk)
{
    if (dp[x][y][k] < val)
    {
        dp[x][y][k] = val;
        prev[x][y][k] = mp(mp(xx, yy), kk);
    }
}
void go(int x, int y, int k)
{
    if (x == 0 || y == 0) return;
    int xx = prev[x][y][k].fs.fs;
    int yy = prev[x][y][k].fs.sc;
    int kk = prev[x][y][k].sc;
    if (xx != x && yy != y)
    {
        res[resc++] = s1[xx];
    }
    go(xx, yy, kk);
}
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    scanf("%s%s%s", s1, s2, vv);
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int nv = strlen(vv);
    forn(i, nv) forn(ii, 26)
    {
        char c = 'A' + ii;
        forn(j, i) tmp[j] = vv[j];
        tmp[i] = c;
        bool ok = false;
        int l = 0;
        while (!ok)
        {
            ok = true;
            for (int k = l; k <= i; ++k) if (tmp[k] != vv[k - l])
            {
                ok = false;
                break;
            }
            if (!ok) l += 1;
        }
        x[i][ii] = i - l + 1;
    }
    forn(i, n1 + 1) forn(j, n2 + 1) forn(k, nv + 1) dp[i][j][k] = -inf;
    dp[0][0][0] = 0;
    forn(i, n1 + 1) forn(j, n2 + 1) forn(k, nv)
    {
        upd(i + 1, j, k, dp[i][j][k], i, j, k);
        upd(i, j + 1, k, dp[i][j][k], i, j, k);
        if (s1[i] == s2[j] && x[k][s1[i] - 'A'] != nv)
        {
            int next = x[k][s1[i] - 'A'];
            upd(i + 1, j + 1, next, dp[i][j][k] + 1, i, j, k);
        }
    }
    int mx = -1;
    int kk = -1;
    for (int i = 0; i < nv; ++i) if (dp[n1][n2][i] > mx)
    {
        mx = dp[n1][n2][i];
        kk = i;
    }
    if (kk >= 0 && mx > 0)
    {
        go(n1, n2, kk);
        reverse(res, res + resc);
        printf("%s\n", res);
    }
    else printf("0\n");
        
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}