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
#define MOD 1000000007
#define MOD9 1000000009
#define INF 2000000000
#define INFLL 9000000000000000000LL
#define EPS 1e-7
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORR(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define UNIK(x) unique(ALL(x) - x.begin())
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SYNC ios_base::sync_with_stdio(0)
#define kita using
#define emang namespace
#define ganteng std

kita emang ganteng;

typedef long long LL;
typedef pair <int, int> pii;
typedef pair <int, pii> pipii;

typedef vector <int> vi;
typedef vector <pii> vii;
typedef pair <LL, LL> pll;
typedef vector <LL> vl;
typedef vector <pll> vll;

//////// End of Template ////////

int n;
int a[100002];
bool vis[100002];

int cycle (int x) {
    if (vis[x]) return 0;
    vis[x] = 1;
    return 1 + cycle(a[x]);
}

int main () {
    scanf("%d", &n);
    FORR(i, n) scanf("%d", &a[i]), a[i]--;

    pii edge = mp(-1, -1);
    bool no = 0;
    FORR(i, n) {
        int tmp = cycle(i);
        if (tmp == 0) continue;

        if (tmp == 1) {
            puts("YES");
            FORR(j, n) {
                if (j == i) continue;
                printf("%d %d\n", j+1, i+1);
            }
            return 0;
        }

        no |= (tmp & 1);
        if (tmp == 2) edge = mp(i, a[i]);
    }

    if (no || edge == mp(-1, -1)) {
        puts("NO");
        return 0;
    }

    memset(vis, 0, sizeof vis);
    puts("YES");
    printf("%d %d\n", edge.fi + 1, edge.se + 1);
    vis[edge.fi] = vis[edge.se] = 1;

    FORR(i, n) {
        if (!vis[i]) {
            pii now = mp(edge.fi, i);
            while (!vis[now.se]) {
                vis[now.se] = 1;
                printf("%d %d\n", now.fi + 1, now.se + 1);
                now = mp(a[now.fi], a[now.se]);
            }
        }
    }

    return 0;
}