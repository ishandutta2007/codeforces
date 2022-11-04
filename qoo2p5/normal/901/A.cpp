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

const int N = (int) 2e5 + 123;

int n;
int a[N];
bool ok[N];
int p[N];

void run() {
    cin >> n;
    ++n;
    rep(i, 0, n) {
        cin >> a[i];
        ok[i] = (a[i] >= 2);
    }
    bool one = 1;
    int pos = -1;
    rep(i, 0, n - 1) {
        if (ok[i] && ok[i + 1]) {
            one = 0;
            pos = i + 1;
        }
    }
    if (one) {
        cout << "perfect\n";
        return;
    } else {
        cout << "ambiguous\n";
        a[pos - 1]--;
        a[pos]--;
        rep(i, 1, n + 1) {
            p[i] = i - 1;
        }
        int cur = n + 1;
        rep(i, 0, n) {
            rep(j, 0, a[i] - 1) {
                p[cur++] = i;
            }
        }
        rep(i, 1, cur) {
            cout << p[i] << " ";
        }
        cout << pos - 1 << " " << cur << "\n";
        rep(i, 1, cur) {
            cout << p[i] << " ";
        }
        cout << pos - 1 << " " << pos << "\n";
    }
}