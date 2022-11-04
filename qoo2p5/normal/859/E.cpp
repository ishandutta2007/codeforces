#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
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

ll power(ll x, ll y, ll mod) {
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

inline void add(ll &x, ll y, ll mod) {
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}

inline ll sum(ll x, ll y, ll mod) {
    add(x, y, mod);
    return x;
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

const int N = (int) 2e5 + 123;

int n;
int a[N], b[N];
int p[N], s[N];
bool bad[N], flag[N];

int get(int v) {
    if (p[v] == v) {
        return v;
    }
    return (p[v] = get(p[v]));
}

void unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) {
        bad[u] = 1;
        return;
    }
    
    p[u] = v;
    bad[v] |= bad[u];
    flag[v] |= flag[u];
    s[v] += s[u];
}

void run() {
    rep(i, 0, N) p[i] = i, s[i] = 1;
    
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> a[i] >> b[i];
    }
    ll ans = 1;
    rep(i, 1, n + 1) {
        if (a[i] != b[i]) unite(a[i], b[i]);
        else flag[get(a[i])] = 1, bad[get(a[i])] = 1;
    }
    set<int> diff;
    rep(i, 1, 2 * n + 1) {
        diff.insert(get(i));
    }
    for (int u : diff) {
        if (!bad[u]) ans = (ans * 1LL * s[u]) % MOD;
        else {
            if (flag[u]) {
                ans = (ans * 1LL) % MOD;
            } else {
                ans = (ans * 2LL) % MOD;
            }
        }
    }
    cout << ans << "\n";
}