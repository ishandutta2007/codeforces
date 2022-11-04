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

const int N = (int) 1e6 + 123;

int n,a ,b;
int ans[N];

void run() {
    cin >> n >> a >> b;
    for (int x = 0; x <= n; x += a) {
        int y = n - x;
        if (y % b != 0) continue;
        rep(i, 1, n + 1) {
            ans[i - 1] = i;
        }
        int ptr = 0;
        rep(i, 0, x / a) {
            if (a > 1) rotate(ans + ptr, ans + ptr + 1, ans + ptr + a);
            ptr += a;
        }
        rep(i, 0, y / b) {
            if (b > 1) rotate(ans + ptr, ans + ptr + 1, ans + ptr + b);
            ptr += b;
        }
        rep(i, 0, n) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    cout << "-1\n";
}