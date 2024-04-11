#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const int INF = (int) 1e9 + 1e6;
const ll LINF = (ll) 1e18 + 1e9;
const ld EPS = (ld) 1e-10;
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

const int N = (int) 1 << 19;

int n, m, q;
vector<int> g[N];
int vis[N];
vector<pair<int, int>> segs;
ll ans[N];

vector<int> st;

ll sum[2 * N];
ll toadd[2 * N];

void push(int i, int tl, int tr) {
    sum[i] += toadd[i] * (tr - tl);
    if (tl != tr - 1) {
        toadd[2 * i + 1] += toadd[i];
        toadd[2 * i + 2] += toadd[i];
    }
    toadd[i] = 0;
}

void add(int i, int tl, int tr, int l, int r, ll v) {
    push(i, tl, tr);
    if (tl >= r || tr <= l) {
        return;
    }
    if (l <= tl && tr <= r) {
        toadd[i] += v;
        push(i, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    add(2 * i + 1, tl, tm, l, r, v);
    add(2 * i + 2, tm, tr, l, r, v);
    sum[i] = sum[2 * i + 1] + sum[2 * i + 2];
}

void add(int l, int r, ll v) {
    add(0, 0, N, l, r + 1, v);
}

ll get(int i, int tl, int tr, int l, int r) {
    push(i, tl, tr);
    if (tl >= r || tr <= l) {
        return 0;
    }
    if (l <= tl && tr <= r) {
        return sum[i];
    }
    int tm = (tl + tr) / 2;
    return get(2 * i + 1, tl, tm, l, r) + get(2 * i + 2, tm, tr, l, r);
}

ll get(int l, int r) {
    return get(0, 0, N, l, r + 1);
}

void dfs(int v, int p = -1) {
    vis[v] = 1;
    st.pb(v);
    for (int u : g[v]) {
        if (u == p || vis[u] == 2) {
            continue;
        }
        if (vis[u]) {
            int mi = u;
            int ma = u;
            int ptr = sz(st) - 1;
            while (st[ptr] != u) {
                mini(mi, st[ptr]);
                maxi(ma, st[ptr]);
                ptr--;
            }
            segs.pb({mi, ma});
        } else {
            dfs(u, v);
        }
    }
    vis[v] = 2;
    st.pop_back();
}

vector<int> bord[N];
vector<pair<int, int>> za[N];

void run() {
    cin >> n >> m;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    rep(i, 1, n + 1) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    
    for (auto &it : segs) {
        bord[it.second].pb(it.first);
    }
    
    cin >> q;
    rep(i, 0, q) {
        int l, r;
        cin >> l >> r;
        za[r].pb({l, i});
    }
    
    int L = 0;
    
    rep(r, 1, n + 1) {
        for (int l : bord[r]) {
            maxi(L, l);
        }
        add(L + 1, r, +1);
        
        for (auto &ev : za[r]) {
            ans[ev.second] = get(ev.first, r);
        }
    }
    
    rep(i, 0, q) {
        cout << ans[i] << "\n";
    }
}