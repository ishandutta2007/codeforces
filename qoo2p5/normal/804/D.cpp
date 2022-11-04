/*

      #     #     #####  #####  #           #  #
     # #   # #    #      #   #  #     #     #  #
    #   # #   #   #####  #   #   #   # #   #   #
   #     #     #  #      #   #    # #   # #     
   #           #  #####  #####     #     #     @

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = (ld) 1e-7;
const ll MOD = (ll) 1e9 + 7;

#define sz(x) (int) (x).size()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)
#define rep(i, f, t) for (int i = f; i < t; i++)

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
    cout << fixed << setprecision(10);
    run();
    return 0;
}

// == SOLUTION == //

const int N = (int) 1e5 + 123;
const int M = (int) sqrt(N) + 4;

int n, m, q;
vector<int> g[N];
int comp[N];
int cnt[N];
float precalc[M][N];
bool vis[N];
int far[N], dp[N];
int cool[N];
vector<int> le[N];
vector<int> su[N];
int big[N];
int cc[N];
ll ss[N];

double calc(int u, int v) { // u is light
    int X = max(dp[u], dp[v]);
    int ptr = 0;
    ld sum = 0;
    for (int i = sz(le[u]) - 1; i >= 0; i--) {
        int y = le[u][i];
        while (ptr < sz(le[v]) && le[v][ptr] + y + 1 < X) ptr++;
        if (ptr == sz(le[v])) {
            sum += X * 1LL * cnt[v];
        } else {
            sum += X * 1LL * ptr;
            sum += su[v][ptr] + (cnt[v] - ptr) * 1LL * (y + 1);
        }
    }
    return (double) (sum / cnt[u] / cnt[v]);
}

double calc2(int u, int v) { // v is heavy
    int X = max(dp[u], dp[v]);
    ld sum = 0;
    for (int y : le[u]) {
        int need = X - 1 - y;
        maxi(need, 0);
        sum += (cnt[v] - cc[need]) * 1LL * X;
        sum += ss[need] + cc[need] * 1LL * (y + 1);
    }
    return (double) (sum / cnt[u] / cnt[v]);
}

void upd(pair<int, int> &x, int y) {
    int q[3] = {x.first, x.second, y};
    sort(q, q + 3);
    x = {q[2], q[1]};
}

void upd(pair<int, int> &x, pair<int, int> y) {
    upd(x, y.first);
    upd(x, y.second);
}

void dfs(int v, int root, int p = -1) {
    vis[v] = 1;
    comp[v] = root;
    cnt[root]++;
    dp[v] = 0;
    pair<int, int> mx = {0, 0};
    for (int u : g[v]) {
        if (u == p) continue;
        dfs(u, root, v);
        maxi(dp[v], dp[u]);
        upd(mx, far[u] + 1);
    }
    far[v] = mx.first;
    maxi(dp[v], mx.first + mx.second);
}

void epic(int v, int p = -1, int up = -1) {
    vector<pair<int, int>> L(sz(g[v]) + 1), R(sz(g[v]) + 1);
    cool[v] = max(up + 1, far[v]);
    le[comp[v]].pb(cool[v]);
    
    for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (i > 0) {
            L[i] = L[i - 1];
        }
        if (u == p) {
            upd(L[i], up + 1);
        } else {
            upd(L[i], far[u] + 1);
        }
    }
    
    for (int i = sz(g[v]) - 1; i >= 0; i--) {
        int u = g[v][i];
        if (i != sz(g[v]) - 1) {
            R[i] = R[i + 1];
        }
        if (u == p) {
            upd(R[i], up + 1);
        } else {
            upd(R[i], far[u] + 1);
        }
    }
    
    for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (u == p) continue;
        pair<int, int> best = {0, 0};
        if (i > 0) {
            upd(best, L[i - 1]);
        }
        if (i < sz(g[v]) - 1) {
            upd(best, R[i + 1]);
        }
        epic(u, v, best.first);
    }
}

void run() {
    cin >> n >> m >> q;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> roots;
    rep(i, 1, n + 1) {
        if (vis[i]) continue;
        dfs(i, i);
        g[i].pb(-1);
        epic(i);
        roots.pb(i);
    }
    
    int k = sz(roots);
    rep(i, 0, k) {
        int v = roots[i];
        sort(all(le[v]));
        su[v].resize(sz(le[v]) + 1);
        for (int j = sz(le[v]) - 1; j >= 0; j--) {
            if (j != sz(le[v]) - 1) {
                su[v][j] = su[v][j + 1];
            }
            su[v][j] += le[v][j];
        }
    }
    int big_cnt = 0;
    vector<int> bigs;
    rep(i, 0, k) {
        int v = roots[i];
        if (cnt[v] >= M) {
            big[v] = big_cnt++;
            bigs.pb(v);
        }
    }
    
    rep(i, 0, big_cnt) {
        int u = bigs[i];
        
        fill(cc, cc + N, 0);
        fill(ss, ss + N, 0);
        for (int x : le[u]) {
            cc[x]++;
        }
        for (int t = N - 2; t >= 0; t--) {
            ss[t] = ss[t + 1] + cc[t] * 1LL * t;
        }
        for (int t = N - 2; t >= 0; t--) {
            cc[t] += cc[t + 1];
        }
        
        for (int v : roots) {
            if (v == u) continue;
            precalc[i][v] = calc2(v, u);
        }
    }
    
    rep(i, 0, q) {
        int u, v;
        cin >> u >> v;
        u = comp[u];
        v = comp[v];
        if (u == v) {
            cout << "-1\n";
            continue;
        }
        
        if (cnt[u] < cnt[v]) {
            swap(u, v);
        }
        
        if (cnt[u] >= M) {
            cout << precalc[big[u]][v] << "\n";
            continue;
        }
        
        cout << calc(v, u) << "\n";
    }
}