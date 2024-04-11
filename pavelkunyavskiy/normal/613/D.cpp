//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>

#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x, ...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ((_WIN32 || __WIN32__) && __cplusplus < 201103L)
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "D"

#ifdef LOCAL

static struct __timestamper {
    string what;

    __timestamper(const char *what) : what(what) { };

    __timestamper(const string &what) : what(what) { };

    ~__timestamper() {
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");

#else
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

const int MAXN = 100100;
const int MAXLOG = 18;

int up[MAXLOG][MAXN];

vector<int> g[MAXN];
int h[MAXN];
int ord[MAXN];
int tin[MAXN];
int tout[MAXN];

int dfs0(int v, int p, int h) {
    static int timer = 0;
    tin[v] = ord[v] = timer++;
    ::h[v] = h;
    up[0][v] = p == -1 ? v : p;
    for (int u : g[v]) {
        if (u != p) {
            dfs0(u, v, h + 1);
        }
    }
    tout[v] = timer;
    return v;
}

bool is_parent(int p, int v) {
    return tin[p] <= ord[v] && ord[v] < tout[p];
}

int getup(int u, int dh) {
    for (int i = MAXLOG - 1; i >= 0; i--)
        if (dh & (1<<i))
            u = up[i][u];
    return u;
}

int lca(int a, int b) {
    if (h[a] > h[b]) swap(a, b);
    assert(h[a] <= h[b]);
    b = getup(b, h[b] - h[a]);
    if (a == b) return b;
    for (int i = MAXLOG - 1; i >= 0; i--)
        if (up[i][a] != up[i][b]) {
            a = up[i][a];
            b = up[i][b];
        }
    assert(up[0][a] == up[0][b]);
    return up[0][a];
}

int is_imp[MAXN];
int is_imp_val;

vector<vector<int>> ng;
int ans = 0;

int dfs1(int v) {
    if (is_imp[v] == is_imp_val) {
        for (int u : ng[v]) {
            eprintf("%d -> %d\n", v, u);
            if (dfs1(u)) {
                ans++;
            }
        }
        return true;
    } else {
        int have = 0;
        for (int u : ng[v]) {
            eprintf("%d -> %d\n", v, u);
            if (dfs1(u)) {
                have++;
                if (have == 2) ans++;
            }
        }
        return have == 1;
    }
}

void solve() {
    int k;
    scanf("%d", &k);
    vector<int> v(k);
    is_imp_val++;
    for (int i = 0; i < k; i++) {
        scanf("%d", &v[i]);
        v[i]--;
        is_imp[v[i]] = is_imp_val;
    }
    auto ordcmp = [] (int a, int b) { return ord[a] < ord[b];};
    sort(v.begin(), v.end(), ordcmp);

    for (int i = 0; i < k; i++) {
        if (v[i] != 0) {
            if (binary_search(v.begin(), v.end(), up[0][v[i]], ordcmp)) {
                printf("-1\n");
                return;
            }
        }
    }

    for (int i = 0; i < k - 1; i++) {
        v.push_back(lca(v[i], v[i+1]));
    }
    sort(v.begin(), v.end(), ordcmp);
    v.erase(unique(v.begin(), v.end()), v.end());

    stack<int> s;

    for (int u : v) {
        while (!s.empty() && !is_parent(s.top(), u))
            s.pop();
        if (!s.empty()) {
            ng[s.top()].push_back(u);
        }
        s.push(u);
    }

    ans = 0;
    dfs1(v[0]);
    printf("%d\n", ans);
    for (int i = 0; i < (int)v.size(); i++)
        ng[v[i]].clear();
}

int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    int n;
    scanf("%d",&n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d",&a, &b);
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs0(0, -1, 0);

    for (int i = 1; i < MAXLOG; i++)
        for (int j = 0; j < n; j++)
            up[i][j] = up[i-1][up[i-1][j]];

    ng = vector<vector<int>>(n);
    int q;
    scanf("%d",&q);
    for (int i = 0; i < q; i++)
        solve();


    return 0;
}