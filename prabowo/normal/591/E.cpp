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
#define sqr(x) (LL)x * (LL)x
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

int n, m;
char s[1002][1002];
queue <pii> q1, q2, q3;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int one[1002][1002];
int two[1002][1002];
int three[1002][1002];

bool vis[1002][1002];

int main () {
    scanf("%d %d", &n, &m);

    gets(s[0]);
    FORR(i, n) gets(s[i]);

    FORR(i, n) FORR(j, m) {
        if (s[i][j] == '1') q1.push(mp(i, j)), vis[i][j] = 1;
    }

    while (q1.size()) {
        pii now = q1.front();
        q1.pop();

        FORR(i, 4) {
            int x = now.fi + dx[i];
            int y = now.se + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && s[x][y] != '#') {
                vis[x][y] = 1;
                one[x][y] = one[now.fi][now.se] + 1;
                q1.push(mp(x, y));
            }
        }
    }

    FORR(i, n) FORR(j, m) if (vis[i][j] == 0) one[i][j] = INF2;

    memset(vis, 0, sizeof vis);

    FORR(i, n) FORR(j, m) {
        if (s[i][j] == '2') q2.push(mp(i, j)), vis[i][j] = 1;
    }

    while (q2.size()) {
        pii now = q2.front();
        q2.pop();

        FORR(i, 4) {
            int x = now.fi + dx[i];
            int y = now.se + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && s[x][y] != '#') {
                vis[x][y] = 1;
                two[x][y] = two[now.fi][now.se] + 1;
                q2.push(mp(x, y));
            }
        }
    }

    FORR(i, n) FORR(j, m) if (vis[i][j] == 0) two[i][j] = INF2;

    memset(vis, 0, sizeof vis);

    FORR(i, n) FORR(j, m) {
        if (s[i][j] == '3') q3.push(mp(i, j)), vis[i][j] = 1;
    }

    while (q3.size()) {
        pii now = q3.front();
        q3.pop();

        FORR(i, 4) {
            int x = now.fi + dx[i];
            int y = now.se + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && s[x][y] != '#') {
                vis[x][y] = 1;
                three[x][y] = three[now.fi][now.se] + 1;
                q3.push(mp(x, y));
            }
        }
    }

    FORR(i, n) FORR(j, m) if (vis[i][j] == 0) three[i][j] = INF2;

/*
    FORR(i, n) {
        FORR(j, m) printf("%d ", one[i][j]);
        printf("\n");
    }

    printf("\n");

    FORR(i, n) {
        FORR(j, m) printf("%d ", two[i][j]);
        printf("\n");
    }

    printf("\n");

    FORR(i, n) {
        FORR(j, m) printf("%d ", three[i][j]);
        printf("\n");
    }

    printf("\n");
*/
    int d[3];
    d[0] = d[1] = d[2] = INF;

    FORR(i, n) FORR(j, m) {
        MIN(d[0], one[i][j] + two[i][j] - 1);
        MIN(d[1], one[i][j] + three[i][j] - 1);
        MIN(d[2], two[i][j] + three[i][j] - 1);
    }



    sort(d, d+3);

    LL mini = INFLL;
    FORR(i, n) FORR(j, m) {
        MIN(mini, (LL) one[i][j] + (LL) two[i][j] + (LL) three[i][j] - 2);
    }

    if (min((LL)d[1] + (LL) d[0], mini) > 100000000) puts("-1");
    else printf("%d\n", min( (LL) d[0] + (LL) d[1], mini));

    return 0;
}