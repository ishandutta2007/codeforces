#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 1e6;
const ll LINF = (ll) 1e18 + 1e9;
const ld EPS = (ld) 1e-7;
const ll MOD = (ll) 1e9 + 7;

#define sz(x) (int) (x).size()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)
#define rep(i, f, t) for (auto i = f; i < t; ++(i))
#define per(i, f, t) for (auto i = (f); i >= (t); --(i))

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

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

void add(ll &x, ll y) {
    x += y;
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
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

const int N = (int) 1 << 17;

ll div_up(ll x, ll y) {
    if (y < 0) {
        x = -x;
        y = -y;
    }
    if (x < 0) {
        return x / y;
    } else {
        return (x + y - 1) / y;
    }
}

struct Line {
    ll k, b;
    
    Line() : k(0), b(0) {}
    
    Line(ll k, ll b) : k(k), b(b) {}
    
    ll val(ll x) {
        return k * x + b;
    }
    
    bool operator<(const Line &b) const {
        return k > b.k;
    }
};

ll inter(const Line &a, const Line &b) {
    return div_up(a.b - b.b, b.k - a.k);
}

struct CHT {
    vector<Line> lines;
    vector<ll> points;
    
    void add(const Line &l) {
        if (sz(lines) && lines.back().k == l.k && l.b >= lines.back().b) {
            return;
        }
        while (sz(lines) && lines.back().k == l.k && l.b < lines.back().b) {
            lines.pop_back();
            if (sz(points)) points.pop_back();
        }
        while (sz(points) && points.back() >= inter(l, lines.back())) {
            lines.pop_back();
            points.pop_back();
        }
        if (sz(lines)) {
            points.pb(inter(l, lines.back()));
        }
        lines.pb(l);
    }
    
    ll get(ll x) {
        if (sz(lines) == 0) return LINF;
        int pos = (int) (upper_bound(all(points), x) - points.begin());
        return lines[pos].val(x);
    }
};

int n;
vector<int> g[N];
ll a[N], b[N];

vector<Line> what[N * 2];
CHT tree[N * 2];

ll get(int i, int tl, int tr, int l, int r, ll x) {
    if (tl >= r || tr <= l) {
        return LINF;
    }
    if (l <= tl && tr <= r) {
        return tree[i].get(x);
    }
    int tm = (tl + tr) / 2;
    return min(get(2 * i + 1, tl, tm, l, r, x), get(2 * i + 2, tm, tr, l, r, x));
}

void build(int i) {
    for (Line &l : what[i]) tree[i].add(l);
}

void upd(int i, int tl, int tr, int ind, const Line &l) {
    if (tl == tr - 1) {
        what[i].pb(l);
        build(i);
        return;
    }
    int tm = (tl + tr) / 2;
    if (ind < tm) upd(2 * i + 1, tl, tm, ind, l);
    else upd(2 * i + 2, tm, tr, ind, l);
    if (!sz(what[i]) && sz(what[2 * i + 1]) && sz(what[2 * i + 2])) {
        what[i].resize(sz(what[2 * i + 1]) + sz(what[2 * i + 2]));
        merge(all(what[2 * i + 1]), all(what[2 * i + 2]), what[i].begin());
        build(i);
    }
}

int tmr;
int tin[N], tout[N];
ll dp[N];

void dfs(int v, int f = -1) {
    tin[v] = tmr++;
    for (int u : g[v]) {
        if (u == f) continue;
        dfs(u, v);
    }
    tout[v] = tmr - 1;
    if (f != -1 && sz(g[v]) == 1) {
        dp[v] = 0;
    } else {
        dp[v] = get(0, 0, N, tin[v] + 1, tout[v] + 1, a[v]);
    }
    upd(0, 0, N, tin[v], Line(b[v], dp[v]));
}

void run() {
    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, n + 1) cin >> b[i];
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    rep(i, 1, n + 1) cout << dp[i] << " ";
    cout << "\n";
}