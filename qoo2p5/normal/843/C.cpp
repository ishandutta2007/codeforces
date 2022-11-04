#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = (ld) 1e-12;
const ll MOD = (ll) 1e9 + 7;

#define sz(x) (int) (x).size()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)
#define rep(i, f, t) for (auto i = f; i < t; i++)
#define per(i, f, t) for (auto i = f; i >= t; i--)

ll power(ll x, ll y, ll mod = MOD) {
    if (y == 0) {
        return 1;
    }
    if (y & 1) {
        return power(x, y - 1, mod) * x % mod;
    } else {
        ll tmp = power(x, y / 2, mod);
        return tmp * tmp % mod;
    }
}

inline void add(ll &x, ll y, ll mod = MOD) {
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}

inline ll sum(ll x, ll y, ll mod = MOD) {
    add(x, y, mod);
    return x;
}

inline ll mult(ll x, ll y, ll mod = MOD) {
    return (x * y) % mod;
}

inline ll div(ll x, ll y, ll mod) {
    return x * power(y, mod - 2, mod);
}

template<typename A, typename B> inline bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> inline bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

template<typename T> inline void read(T first, T last) {
    while (first != last) {
        cin >> *(first++);
    }
}

template<typename T> inline void print(T first, T last) {
    while (first != last) {
        cout << *(first++) << " ";
    }
    cout << "\n";
}

void run();

#define TASK ""

int main() {
#ifdef LOCAL
    if (strlen(TASK) > 0) {
        cerr << "Reminder: you are using file i/o, filename: " TASK "!" << endl << endl;
    }
#endif
#ifndef LOCAL
    if (strlen(TASK)) {
        freopen(TASK ".in", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    cout << fixed << setprecision(12);
    run();
    return 0;
}

// == SOLUTION == //

const int N = (int) 2e5 + 123;

struct Q {
    int x, y1, y2;
};

int n;
vector<int> g[N];
int cnt[N];
vector<Q> res;

void calc_cnt(int v, int p = -1) {
    cnt[v] = 1;
    for (int u : g[v]) {
        if (u == p) continue;
        calc_cnt(u, v);
        cnt[v] += cnt[u];
    }
}

pair<int, int> find_edge(int v, int p = -1) {
    for (int u : g[v]) {
        if (u == p) continue;
        auto tmp = find_edge(u, v);
        if (tmp.first != -1) return tmp;
        if (2 * cnt[u] == n) {
            return {u, v};
        }
    }
    return {-1, -1};
}

int find_centroid(int v, int p = -1) {
    bool ok = 1;
    for (int u : g[v]) {
        if (u == p) {
            ok &= 2 * (n - cnt[v]) < n;
            continue;
        }
        int t = find_centroid(u, v);
        if (t != -1) {
            return t;
        }
        ok &= 2 * cnt[u] < n;
    }
    return (ok ? v : -1);
}

void dfs(int v, int p, int centr, int root, int &cur_root) {
    if (v != root && p != root) {
        res.pb({centr, cur_root, v});
        cur_root = v;
        res.pb({v, p, root});
    }
    
    for (int u : g[v]) {
        if (u == p) continue;
        dfs(u, v, centr, root, cur_root);
    }
}

void solve(int v, int p = -1) {
    for (int u : g[v]) {
        if (u == p) continue;
        int cur_root = u;
        dfs(u, v, v, u, cur_root);
        if (cur_root != u) res.pb({v, cur_root, u});
    }
}

void run() {
    cin >> n;
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    calc_cnt(1);
    auto tmp = find_edge(1);
    if (tmp.first != -1) {
        solve(tmp.first, tmp.second);
        solve(tmp.second, tmp.first);
    } else {
        solve(find_centroid(1));
    }
    
    cout << sz(res) << "\n";
    for (auto &q : res) {
        cout << q.x << " " << q.y1 << " " << q.y2 << "\n";
    }
}