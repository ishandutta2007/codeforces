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

const int N = (int) 1e5 + 123;

int n, m, q;
string s, t;
int sb[N], tb[N];
int s_a[N], t_a[N];

int get(int *a, int l, int r) {
    int res = a[r];
    if (l > 0) res -= a[l - 1];
    return res;
}

void run() {
    cin >> s >> t;
    n = sz(s);
    m = sz(t);
    for (auto &c : s) if (c == 'C') c = 'B';
    for (auto &c : t) if (c == 'C') c = 'B';
    rep(i, 0, n) if (s[i] == 'B') sb[i]++;
    rep(i, 1, n) sb[i] += sb[i - 1];
    rep(i, 0, m) if (t[i] == 'B') tb[i]++;
    rep(i, 1, m) tb[i] += tb[i - 1];

    rep(i, 0, n) {
        if (s[i] == 'B') {
            s_a[i] = 0;
            continue;
        }
        s_a[i] = 1;
        if (i > 0) s_a[i] += s_a[i - 1];
    }
    rep(i, 0, m) {
        if (t[i] == 'B') {
            t_a[i] = 0;
            continue;
        }
        t_a[i] = 1;
        if (i > 0) t_a[i] += t_a[i - 1];
    }

    cin >> q;
    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1--; r1--; l2--; r2--;
        int b1 = get(sb, l1, r1);
        int b2 = get(tb, l2, r2);
        if (b1 % 2 != b2 % 2) {
            cout << "0";
            continue;
        }
        if (b1 > b2) {
            cout << "0";
            continue;
        }

        if (b2 > b1) {
            int cnt_s = min(r1 - l1 + 1, s_a[r1]);
            int cnt_t = min(r2 - l2 + 1, t_a[r2]);
            if (cnt_s == cnt_t && cnt_s == r1 - l1 + 1) {
                cout << "0";
                continue;
            }
            if (cnt_s >= cnt_t) {
                cout << "1";
                continue;
            }

            cout << "0";
        } else {
            int cnt_s = min(r1 - l1 + 1, s_a[r1]);
            int cnt_t = min(r2 - l2 + 1, t_a[r2]);
            if (cnt_s >= cnt_t && cnt_s % 3 == cnt_t % 3) {
                cout << "1";
                continue;
            }

            cout << "0";
        }
    }
}