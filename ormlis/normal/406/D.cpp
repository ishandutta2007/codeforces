#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5 + 1;
const int P = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

struct pt {
    ll x = 0, y = 0;
};

pt operator+(pt a, pt b) {
    return {a.x + b.x, a.y + b.y};
}

pt operator-(pt &a, pt &b) {
    return {a.x - b.x, a.y - b.y};
}

double dist(pt &a, pt &b) {
    pt c = a - b;
    return sqrt((double) (c.x * c.x + c.y * c.y));
}

double dist(pt &a) {
    return sqrt((double) (a.x * a.x + a.y * a.y));
}

double EPS = 0.0000001;

bool eq(double a, double b) {
    return abs(a - b) < EPS;
}

bool operator==(pt &a, pt &b) {
    return eq(a.x, b.x) && eq(a.y, b.y);
}

bool operator!=(pt &a, pt &b) {
    return !(a == b);
}

bool check(pt v1, pt v2) {
    return v2.x * v1.y < v1.x * v2.y;
}

vector<int> g[maxN];
int h[maxN];
int up[maxN][18];

void dfs(int v, int p) {
    up[v][0] = p;
    for (int i = 1; i < 18; ++i) {
        if (~up[v][i - 1]) up[v][i] = up[up[v][i - 1]][i - 1];
        else up[v][i] = -1;
    }
    for (auto &u: g[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        dfs(u, v);
    }
}

int lca(int v, int u) {
    if (u == v) return u;
    if (h[u] > h[v]) swap(u, v);
    for (int i = 17; i >= 0; --i) {
        if (~up[v][i]) {
            if (h[up[v][i]] >= h[u]) v = up[v][i];
        }
    }
    if (u == v) return u;
    for (int i = 17; i >= 0; --i) {
        if (~up[v][i] && ~up[u][i]) {
            if (up[v][i] != up[u][i]) {
                u = up[u][i], v = up[v][i];
            }
        }
    }
    return up[u][0];
}

void solve() {
    int n;
    cin >> n;
    vector<pt> a(n);
    range(i, n) cin >> a[i].x >> a[i].y;
    vector<int> p(n, -1);
    for (int i = n - 2; i >= 0; --i) {
        p[i] = i + 1;
        while (p[p[i]] != -1 && check(a[p[i]] - a[i], a[p[p[i]]] - a[i])) {
            p[i] = p[p[i]];
        }
    }
    range(i, n - 1) {
        g[p[i]].push_back(i);
    }
    dfs(n - 1, -1);
    int m; cin >> m;
    range(_, m) {
        int u, v; cin >> v >> u;
        cout << lca(u-1, v-1) + 1 << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}