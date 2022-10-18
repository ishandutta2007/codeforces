#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)
#define union union________________

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const ld EPS = 1e-9;
const int MAXN = 3e5 + 10;

struct DSU {
    vi p;
    vi sz;

    DSU(int n = 0) {
        p.assign(n, 0);
        sz.assign(n, 0);
        forn(i, n) {
            sz[i] = 1;
            p[i] = i;
        }
    }

    int get(int x) {
        return x == p[x] ? x : p[x] = get(p[x]);
    }

    void union(int x, int y) {
        x = get(x);
        y = get(y);
        if  (x == y) return;
        if  (sz[x] > sz[y]) swap(x, y);
        sz[y] += sz[x];
        p[x] = y;
    }
};

int n, m, q;
vi g[MAXN];
int diam[MAXN];
DSU dsu;

bool read() {
    if  (scanf("%d%d%d", &n, &m, &q) < 3) {
        return false;
    }
    forn(i, n) {
        g[i].clear();
    }
    forn(i, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    return true;
}

pii dfs_longest(int v, int p) {
    pii res(v, 0);
    for (int to : g[v]) {
        if  (to == p) continue;
        pii cur = dfs_longest(to, v);
        ++cur.snd;
        if  (cur.snd > res.snd) res = cur;
    }
    return res;
}

int find_diam(int v) {
    pii t1 = dfs_longest(v, -1);
    int u = t1.fst;
    return dfs_longest(u, -1).snd;
}

void precalc() {
    dsu = DSU(n);
    forn(i, n) for (int to : g[i]) dsu.union(i, to);

    forn(i, n) {
        if  (dsu.get(i) == i) {
            diam[i] = find_diam(i);
        }
    }
}

void solve() {
    precalc();
    forn(it, q) {
        int t;
        scanf("%d", &t);
        if  (t == 1) {
            int x;
            scanf("%d", &x);
            --x;
            printf("%d\n", diam[dsu.get(x)]);
        } else {
            assert(t == 2);
            int x, y;
            scanf("%d%d", &x, &y);
            --x;
            --y;
            x = dsu.get(x);
            y = dsu.get(y);
            if  (x == y) {
                continue;
            }
            int dx = diam[x];
            int dy = diam[y];
            dsu.union(x, y);
            int r = dsu.get(x);
            assert(r == dsu.get(y));
            diam[r] = (dx + 1) / 2 + (dy + 1) / 2 + 1;
            diam[r] = max(diam[r], max(dx, dy));
        }
    }
}

int main() {
#ifdef DEBUG
    freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif
    
    while (read()) {
        solve();
    }

    return 0;
}