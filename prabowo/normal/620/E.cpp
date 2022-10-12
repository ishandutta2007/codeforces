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

const int N = 400000;
int c[N];
pii range[N];
int cnt;

struct ST {
    int lazy[N << 2];
    LL color[N << 2];

    void build (int node, int l, int r) {
        color[node] = 0;
        lazy[node] = -1;

        if (l == r) return;

        int mid = l + r >> 1;
        build (2 * node + 1, l, mid + 0);
        build (2 * node + 2, mid + 1, r);

        return;
    }

    void propagate (int node) {
        if (lazy[node] == -1) return;
        FORR(i, 2) {
            lazy[2 * node + i + 1] = lazy[node];
            color[2 * node + i + 1] = 1LL << lazy[node];
        }
        lazy[node] = -1;
        return;
    }

    void update (int node, int l, int r, int a, int b, int val) {
        if (l > b || r < a) return;
        if (l >= a && r <= b) {
            lazy[node] = val;
            color[node] = 1LL << val;
            return;
        }

        propagate (node);

        int mid = l + r >> 1;
        update (2 * node + 1, l, mid + 0, a, b, val);
        update (2 * node + 2, mid + 1, r, a, b, val);
        color[node] = color[2 * node + 1] | color[2 * node + 2];
        // cout << node << " " << color[2 * node + 1] << " " << color[2 * node + 2] << endl;
        return;
    }

    LL query (int node, int l, int r, int a, int b) {
        if (l > b || r < a) return 0;
        if (l >= a && r <= b) return color[node];

        propagate (node);

        int mid = l + r >> 1;
        return query (2 * node + 1, l, mid + 0, a, b) | query (2 * node + 2, mid + 1, r, a, b);
    }
} tree;

int n, m;

vi edge[N];

void dfs (int x, int par) {
    range[x].fi = cnt;
    FORR (i, edge[x].size()) {
        if (edge[x][i] == par) continue;
        cnt++;
        dfs (edge[x][i], x);
    }
    range[x].se = cnt;
    return;
}

int main () {
    scanf ("%d %d", &n, &m);
    FORR (i, n) scanf ("%d", c + i), c[i]--;

    int u, v;
    FORR (i, n - 1) {
        scanf ("%d %d", &u, &v);
        --u, v--;
        edge[u].pb(v);
        edge[v].pb(u);
    }

    dfs (0, 0);

    tree.build (0, 0, n - 1);
    FORR (i, n) tree.update (0, 0, n - 1, range[i].fi, range[i].fi, c[i]);

    while (m--) {
        int t, c;
        scanf ("%d", &t);
        if (t == 1) {
            scanf ("%d %d", &v, &c);
            v--, c--;
            tree.update (0, 0, n - 1, range[v].fi, range[v].se, c);
        } else if (t == 2) {
            scanf ("%d", &v);
            v--;
            // cout << __builtin_popcount(tree.query (0, 0, n - 1, range[v].fi, range[v].se)) << endl;
            printf ("%d\n", __builtin_popcountll(tree.query (0, 0, n - 1, range[v].fi, range[v].se)));
        }
    }

    return 0;
}