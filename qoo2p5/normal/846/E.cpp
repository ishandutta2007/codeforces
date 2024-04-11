#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
//const ll LINF = (ll) 1e18 + 123;
const ld EPS = (ld) 1e-8;
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
    cout << fixed << setprecision(15);
    run();
    return 0;
}

// == SOLUTION == //

const int N = (int) 1e5 + 123;

int n;
vector<int> g[N];
int x[N];
ll a[N], b[N], k[N], dp[N];
const ll LINF = (ll) 2e18 + 1e10;

void NO() {
    cout << "NO\n";
    exit(0);
}

void dfs(int v) {
    b[v] -= a[v];
    for (int u : g[v]) {
        dfs(u);
        if (dp[u] > 0) {
            b[v] += dp[u];
        } else {
            ll w = -dp[u];
            if (w >= LINF / k[u]) {
                NO();
            }
            b[v] -= w * k[u];
            if (b[v] < -LINF) {
                NO();
            }
        }
    }
    dp[v] = b[v];
}

void run() {
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> b[i];
    }
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    rep(i, 2, n + 1) {
        cin >> x[i] >> k[i];
        g[x[i]].pb(i);
    }
    dfs(1);
    cout << (dp[1] >= 0 ? "YES\n" : "NO\n");
}