#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>
#include <unordered_map>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 998244353, N = 200;

vector <int> lvl, sz;
vector <vector <int>> g;
vector <vector <pair <int, int>>> G;
int L, W, ans = 0;

void get_sz(int v, int p) {
    sz[v] = 1;
    for (auto u : g[v]) {
        if (lvl[u] or u == p) continue;
        get_sz(u, v);
        sz[v] += sz[u];
    }
}

int get_centr(int v, int p, int n) {
    for (auto u : g[v]) {
        if (u == p or lvl[u]) continue;
        if (sz[u] > n / 2)
            return get_centr(u, v, n);
    }
    return v;
}

void build(int v, int cur = 1) {
    get_sz(v, -1);
    v = get_centr(v, -1, sz[v]);
    lvl[v] = cur;
    for (auto u : g[v]) {
        if (lvl[u]) continue;
        build(u, cur + 1);
    }
}

struct query {
    int type, x, y;
    // type == 1 - point
    // type == 2 - query
    query(int type = 0, int x = 0, int y = 0) :
        type(type), x(x), y(y) {}
    bool operator<(const query& a) {
        if (x != a.x) return x < a.x;
        return type < a.type;
    }
};

struct Fenwick {
    vector <int> t;
    Fenwick(int n = 0) {
        t.resize(n);
    }
    void inc(int i) {
        for (; i < t.size(); i |= i + 1)
            t[i]++;
    }
    void dec(int i) {
        for (; i < t.size(); i |= i + 1)
            t[i]--;
    }
    int get(int i) {
        int res = 0;
        for (; i >= 0; i &= i + 1, --i)
            res += t[i];
        return res;
    }
};

vector <query> ask, points;

void dfs(int v, int p, int root, int w, int l) {
    if (l > L or w > W) return;
    ask.push_back(query(2, W - w, L - l));
    for (auto &u : G[v]) {
        if (lvl[u.first] <= lvl[root] or u.first == p)
            continue;
        dfs(u.first, v, root, w + u.second, l + 1);
    }
}

Fenwick tree;

void answer() {
    vector <query> qs;
    for (auto& x : ask)
        qs.push_back(x);
    for (auto& x : points)
        qs.push_back(x);
    sort(qs.begin(), qs.end());
    for (auto& x : qs) {
        if (x.type == 1)
            tree.inc(x.y);
        else
            ans += tree.get(x.y);
    }
    for (auto& x : points) {
        tree.dec(x.y);
    }
    for (auto& x : ask)
        points.push_back(query(1, W - x.x, L - x.y));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);

    int n; cin >> n >> L >> W;
    tree = Fenwick(L + 1);
    lvl.resize(n + 1);
    sz.resize(n + 1);
    g.resize(n + 1);
    G.resize(n + 1);

    for (int i = 2; i <= n; ++i) {
        int x, w; cin >> x >> w;
        g[i].push_back(x);
        g[x].push_back(i);
        G[i].push_back({ x, w });
        G[x].push_back({ i, w });
    }

    build(1);

    for (int i = 1; i <= n; ++i) {
        ask = {}, points = {};
        points.push_back(query(1, 0, 0));
        for (auto& x : G[i]) {
            if (lvl[x.first] <= lvl[i]) continue;
            dfs(x.first, -1, i, x.second, 1);
            answer();
            ask = {};
        }
    }

    cout << ans << '\n';

    return 0;
}