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

void add(ll &x, ll y, ll mod = MOD) {
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}

ll sum(ll x, ll y, ll mod = MOD) {
    add(x, y, mod);
    return x;
}

ll mult(ll x, ll y, ll mod = MOD) {
    return (x * y) % mod;
}

ll div(ll x, ll y, ll mod) {
    return x * power(y, mod - 2, mod);
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

template<typename T> void read(T first, T last) {
    while (first != last) {
        cin >> *(first++);
    }
}

template<typename T> void print(T first, T last) {
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

const int N = (int) 3e5 + 123;

int n, m;
int d[N];
vector<pair<int, int>> g[N];
bool must[N];
int cnt[N];
bool vis[N];

void dfs(int v) {
    vis[v] = 1;
    cnt[v] = d[v];
    for (auto &e : g[v]) {
        int u = e.first;
        if (vis[u]) continue;
        dfs(u);
        cnt[v] += cnt[u];
        if (cnt[u] % 2 != 0) must[e.second] = 1;
    }
}

void run() {
    cin >> n >> m;
    read(d, d + n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    int sum = 0;
    bool have = 0;
    rep(i, 0, n) {
        if (d[i] == -1) {
            have = 1;
        } else {
            sum += d[i];
        }
    }
    sum %= 2;
    if (sum == 1 && !have) {
        cout << "-1\n";
        return;
    }
    if (sum == 1) {
        bool f = 0;
        rep(i, 0, n) {
            if (d[i] != -1) continue;
            if (!f) {
                d[i] = 1;
                f = 1;
            } else {
                d[i] = 0;
            }
        }
    } else {
        rep(i, 0, n) if (d[i] == -1) d[i] = 0;
    }
    dfs(1);
    int k = 0;
    rep(i, 0, m) k += must[i];
    cout << k << "\n";
    rep(i, 0, m) {
        if (must[i]) cout << i + 1 << "\n";
    }
}