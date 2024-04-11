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

const int N = 1 << 19;
const int L = 21;

int up1[N][L], up2[N][L];
ll ma[N][L], sum[N][L];
ll w[N];
int h1[N], h2[N];
int cnt = 1;

int get_cool(int v) {
    int u = v;
    per(i, L - 1, 0) {
        if (ma[u][i] < w[v]) {
            u = up1[u][i];
        }
    }
    u = up1[u][0];
    if (w[u] >= w[v]) {
        return u;
    } else {
        return v;
    }
}

void add(int p, ll we) {
    int v = ++cnt;
    w[v] = we;
    h1[v] = h1[p] + 1;
    up1[v][0] = p;
    ma[v][0] = w[p];
    rep(i, 1, L) {
        up1[v][i] = up1[up1[v][i - 1]][i - 1];
        ma[v][i] = max(ma[v][i - 1], ma[up1[v][i - 1]][i - 1]);
    }
    
    int from = get_cool(v);
    h2[v] = h2[from] + 1;
    up2[v][0] = from;
    sum[v][0] = w[from];
    rep(i, 1, L) {
        up2[v][i] = up2[up2[v][i - 1]][i - 1];
        sum[v][i] = sum[up2[v][i - 1]][i - 1] + sum[v][i - 1];
    }
}

int get(int v, ll x) {
    if (w[v] > x) {
        return 0;
    }
    int was = v;
    x -= w[v];
    per(i, L - 1, 0) {
        if (sum[v][i] <= x) {
            x -= sum[v][i];
            v = up2[v][i];
        }
    }
    return h2[was] - h2[v] + 1;
}

void run() {
    rep(i, 0, L) up1[1][i] = 1;
    
    int q;
    cin >> q;
    int last = 0;
    while (q--) {
        int t;
        ll p, q;
        cin >> t >> p >> q;
        if (t == 1) {
            int r = p ^ last;
            ll w = q ^ last;
            // cerr << ": " << t << " " << r << " " << w << "\n";
            add(r, w);
        } else {
            int r = p ^ last;
            ll x = q ^ last;
            // cerr << ": " << t << " " << r << " " << x << "\n";
            last = get(r, x);
            cout << last << "\n";
        }
    }
}