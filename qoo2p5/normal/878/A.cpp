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
#define per(i, f, t) for (int i = f; i >= t; i--)

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

const int K = 10;
const int N = (int) 5e5 + 123;
const int T = 5;

int n;
int t[N], x[N];
int to[K][2];

vector<int> cur;

int op(int type, int x, int y) {
    if (type == 0) {
        return x & y;
    } else if (type == 1) {
        return x | y;
    } else {
        return x ^ y;
    }
}

void check() {
    int res[5];
    fill(res, res + 5, 0);
    rep(bit, 0, 10) {
        int ok = -1;
        rep(seq, 0, 1 << T) {
            int meow[2] = {0, 1};
            rep(step, 0, T) {
                rep(z, 0, 2) {
                    meow[z] = op(cur[step], meow[z], bool(seq & (1 << step)));
                }
            }
            if (meow[0] == to[bit][0] && meow[1] == to[bit][1]) {
                ok = seq;
            }
        }
        if (ok == -1) {
            return;
        }
        rep(step, 0, T) {
            if (ok & (1 << step)) {
                res[step] |= (1 << bit);
            }
        }
    }
    
    cout << T << "\n";
    rep(i, 0, T) {
        if (cur[i] == 0) {
            cout << "& ";
        } else if (cur[i] == 1) {
            cout << "| ";
        } else {
            cout << "^ ";
        }
        cout << res[i];
        cout << "\n";
    }
    
    exit(0);
}

void solve() {
    if (sz(cur) == T) {
        check();
        return;
    }
    
    rep(i, 0, 3) {
        cur.pb(i);
        solve();
        cur.pop_back();
    }
}

void run() {
    cin >> n;
    rep(i, 0, n) {
        char tp;
        cin >> tp >> x[i];
        if (tp == '&') {
            t[i] = 0;
        } else if (tp == '|') {
            t[i] = 1;
        } else {
            t[i] = 2;
        }
    }
    rep(i, 0, K) {
        to[i][0] = 0;
        to[i][1] = 1;
    }
    rep(i, 0, n) {
        rep(j, 0, K) {
            rep(z, 0, 2) {
                to[j][z] = op(t[i], to[j][z], bool(x[i] & (1 << j)));
            }
        }
    }
    
    solve();
}