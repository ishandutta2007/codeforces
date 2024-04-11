#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <istream>
#include <ostream>
#include <deque>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define MOD 1000000007
#define MOD9 1000000009
#define INF 2000000000
#define INF2 1000000000
#define INFLL 9000000000000000000LL
#define INFLL2 4500000000000000000LL
#define EPS 1e-7
#define debug puts("ganteng")
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORR(i, n) FOR(i, 0, n)
#define REV(i, a, b) for (int i=a-1; i>=b; i--)
#define REVV(i, n) REV(i, n, 0)
#define ALL(x) x.begin(), x.end()
#define UNIK(x) unique(ALL(x)) - x.begin()
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define sqr(x) (((LL)x) * ((LL)x))
#define SYNC ios_base::sync_with_stdio(0), cin.tie(0)
#define TLE using
#define RTE namespace
#define WA std

TLE RTE WA;

typedef long long LL;
typedef pair <int, int> pii;
typedef pair <int, pii> pipii;

typedef vector <int> vi;
typedef vector <pii> vii;
typedef pair <LL, LL> pll;
typedef vector <LL> vl;
typedef vector <pll> vll;

//////// End of Template ////////

int n, m, cnt;
char lab[1002][1002];
int vis [1002][1002];
int dp[1000002];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int bfs (int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return -1;
    if (lab[x][y] == '*') return -1;
    if (~vis[x][y]) return vis[x][y];

    queue < pii > q1;

    q1.push(mp(x, y));
    int ans = 1;
    vis[x][y] = cnt;
    while (q1.size()) {
        pii now = q1.front();
        q1.pop();

        FORR(i, 4) {
            pii nxt = mp(now.fi + dx[i], now.se + dy[i]);
            if (nxt.fi >= 0 && nxt.fi < n && nxt.se >= 0 && nxt.se < m && lab[nxt.fi][nxt.se] != '*' && vis[nxt.fi][nxt.se] == -1) {
                vis[nxt.fi][nxt.se] = cnt;
                q1.push(nxt);
                ans++;
            }
        }
    }

    ans %= 10;
    dp[cnt] = ans;

    return cnt++;
}

int query (int x, int y) {
    int ret = 1;
    set <int> s;
    FORR(i, 4) s.insert (bfs(x + dx[i], y + dy[i]));

    for (set <int> :: iterator it = s.begin(); it != s.end(); ++it) {
        if (*it != -1) ret += dp[*it];
    }

    return ret % 10;
}

int main () {
    scanf ("%d %d ", &n, &m);
    FORR(i, n) gets(lab[i]);

    memset (vis, -1, sizeof vis);

    FORR(i, n) {
        FORR(j, m) if (lab[i][j] == '.') printf("."); else printf("%d", query(i, j));
        printf("\n");
    }

    return 0;
}