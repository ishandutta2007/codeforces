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

const int N = 2005;
int n, m, c;
int a[N];

bool ok() {
    rep(i, 1, n + 1) {
        if (a[i] == -1) return 0;
    }
    rep(i, 1, n) {
        if (a[i] > a[i + 1]) {
            assert(0);
        }
    }
    return 1;
}

void run() {
    fill(a, a + N, -1);
    cin >> n >> m >> c;
    if (c % 2 == 1) {
        c++;
    }
    assert(n * c / 2 <= m);
    int l = 1;
    int r = n;
    while (!ok()) {
        assert(l <= r);
        int x;
        cin >> x;
        int res = -1;
        if (x <= c / 2) {
            rep(i, 1, l) {
                if (x < a[i]) {
                    res = i;
                    break;
                }
            }
            if (res == -1) res = l++;
        } else {
            per(i, n, r + 1) {
                if (x > a[i]) {
                    res = i;
                    break;
                }
            }
            if (res == -1) res = r--;
        }
        assert(res != -1);
        cout << res << endl;
        a[res] = x;
    }
}