#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

using ll = long long;

const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};

const int maxn = 5e5 + 100;
const int inf = 1e15;

int ans = 0;
int n;
vector<int> graph[maxn];
int rk[maxn];
int dp[maxn];

inline int square(int x) {
    return x * x;
}

void dfs_size(int v, int parent) {
    rk[v] = 1;
    for (auto to: graph[v]) {
        if (to != parent) {
            dfs_size(to, v);
            rk[v] += rk[to];
        }
    }
}

void dfs(int v, int parent) {
    if (parent && sz(graph[v]) == 1) {
        dp[v] = 1;
        return;
    }
    int sumsq = inf;
    HullDynamic hull;
    dp[v] = inf;
    for (auto to: graph[v]) {
        if (to != parent) {
            dfs(to, v);
            dp[v] = min(dp[v], dp[to] + square(rk[v] - rk[to]));
            if (!hull.empty()) {
                int c = dp[to] + n * n - 2 * n * rk[to] + square(rk[to]);
                sumsq = min(sumsq, c - hull.eval(2 * rk[to]));
            };
            int k = rk[to];
            int b = -(2 * n * rk[to]) + square(rk[to]) + dp[to];
            hull.insert_line(-k, -b);
        }
    }
    ans = max(ans, (n * n - sumsq + n * (n - 1)) / 2);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if (n == 2) {
        cout << 2 << '\n';
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (sz(graph[i]) > 1) {
            dfs_size(i, 0);
            dfs(i, 0);
            break;
        }
    }
    cout << ans << '\n';
}