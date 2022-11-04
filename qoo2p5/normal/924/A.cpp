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

const int N = 55;

int n, m;
char a[N][N], b[N][N];
bool vis[N][N];
vector<int> col, row;

void dfs(int x, int y) {
    col.pb(y), row.pb(x);
    vis[x][y] = 1;
    rep(i, 0, n) {
        if (!vis[i][y] && a[i][y] == '#') {
            dfs(i, y);
        }
    }
    rep(j, 0, m) {
        if (!vis[x][j] && a[x][j] == '#') {
            dfs(x, j);
        }
    }
}

void run() {
    cin >> n >> m;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
        }
    }
    memset(b, '.', sizeof b);
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (a[i][j] == '#' && !vis[i][j]) {
                col.clear();
                row.clear();
                dfs(i, j);
                for (int y : col) {
                    for (int x : row) {
                        b[x][y] = '#';
                    }
                }
            }
        }
    }
    bool ok = 1;
    rep(i, 0, n) rep(j, 0, m) ok &= a[i][j] == b[i][j];
    cout << (ok ? "Yes\n" : "No\n");
}