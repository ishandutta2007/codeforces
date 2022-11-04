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

void add(ll &x, ll y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
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

int cnt[16];
int cur[4];

int n, k;

void solve(int step, int all) {
    if (step == 16) {
        if (all == 0) {
            return;
        }
        bool ok = 1;
        rep(i, 0, k) {
            ok &= cur[i] * 2 >= all;
        }
        if (ok) {
            cout << "YES\n";
            exit(0);
        }
        return;
    }
    
    if (cnt[step]) {
        rep(j, 0, k) {
            if (!(step & (1 << j))) {
                cur[j]++;
            }
        }
        solve(step + 1, all + 1);
        rep(j, 0, k) {
            if (!(step & (1 << j))) {
                cur[j]--;
            }
        }
        solve(step + 1, all);
    } else {
        solve(step + 1, all);
    }
}

void run() {
    cin >> n >> k;
    rep(i, 0, n) {
        int mask = 0;
        rep(j, 0, k) {
            int x;
            cin >> x;
            mask |= (x << j);
        }
        cnt[mask]++;
    }
    
    solve(0, 0);
    
    cout << "NO\n";
}