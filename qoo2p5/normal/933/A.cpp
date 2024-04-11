/*#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("sse4,tune=native")*/
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

const int N = 2005;

int n;
int a[N];
int cnt[N];
int best_suff[N], best_pref[N];

int get1(int l, int r) {
    if (l > r) return 0;
    return cnt[r] - cnt[l - 1];
}

int get2(int l, int r) {
    if (l > r) return 0;
    return (r - l + 1) - get1(l, r);
}

void run() {
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> a[i];
        cnt[i] = cnt[i - 1] + (a[i] == 1);
    }
    
    rep(i, 1, n + 1) {
        maxi(best_pref[i], get1(1, i));
        maxi(best_pref[i], best_pref[i - 1]);
        if (a[i] == 2) {
            maxi(best_pref[i], best_pref[i - 1] + 1);
        }
    }
    per(i, n, 1) {
        maxi(best_suff[i], get2(i, n));
        maxi(best_suff[i], best_suff[i + 1]);
        if (a[i] == 1) {
            maxi(best_suff[i], best_suff[i + 1] + 1);
        }
    }
    
    int ans = 0;
    rep(l, 1, n + 1) {
        int tmp = 0;
        rep(r, l, n + 1) {
            if (a[r] == 1) {
                tmp++;
            }
            maxi(tmp, get2(l, r));
            maxi(ans, get1(1, r) + best_suff[r + 1]);
            maxi(ans, best_pref[l - 1] + get2(l, n));
            maxi(ans, get1(1, l - 1) + tmp + get2(r + 1, n));
        }
    }
    cout << ans << "\n";
}