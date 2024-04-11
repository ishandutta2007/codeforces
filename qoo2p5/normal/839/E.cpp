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
#define rep(i, f, t) for (auto i = (f); i < (t); i++)
#define per(i, f, t) for (auto i = (f); i >= (t); i--)

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

const int N = 42;
const int K = 21;

int n;
ld k;
bool g[N][N];
bool isfull[1 << K], isok[1 << K];
int dp[1 << K];
int id[1 << K];
int adj[1 << K];

void run() {
    cin >> n >> k;
    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> g[i][j];
        }
    }
    
    rep(i, 0, K) {
        id[1 << i] = i;
    }
    
    int left = (n + 1) / 2;
    int right = n - left;
    
    int res = 1;
    
    isfull[0] = 1;
    rep(mask, 1, 1 << right) {
        int prv = mask & (mask - 1);
        int last = id[mask ^ prv];
        bool ok = isfull[prv];
        if (ok) {
            rep(i, 0, right) {
                if (prv & (1 << i)) {
                    ok &= g[i + left][last + left];
                }
            }
        }
        isfull[mask] = ok;
        
        if (!ok) {
            rep(i, 0, right) {
                if (mask & (1 << i)) {
                    maxi(dp[mask], dp[mask ^ (1 << i)]);
                }
            }
        } else {
            dp[mask] = __builtin_popcount(mask);
        }
        maxi(res, dp[mask]);
    }
    
    isok[0] = 1;
    adj[0] = (1 << K) - 1;
    rep(mask, 1, 1 << left) {
        int prv = mask & (mask - 1);
        int last = id[mask ^ prv];
        bool ok = isok[prv];
        if (ok) {
            rep(i, 0, left) {
                if (prv & (1 << i)) {
                    ok &= g[i][last];
                }
            }
        }
        isok[mask] = ok;
        int cnt = __builtin_popcount(mask);
        if (cnt > 1) {
            adj[mask] = adj[prv] & adj[mask ^ prv];
        } else {
            rep(i, 0, right) {
                if (g[last][left + i]) adj[mask] |= (1 << i);
            }
        }
        if (ok) {
            maxi(res, cnt + dp[adj[mask]]);
        }
    }
    //cerr << res << endl;
    ld ans = (k / res) * (k / res) * res * (res - 1) / 2;
    cout << ans << "\n";
}