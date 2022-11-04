/*

      #     #     #####  #####  #           #  #
     # #   # #    #      #   #  #     #     #  #
    #   # #   #   #####  #   #   #   # #   #   #
   #     #     #  #      #   #    # #   # #     
   #           #  #####  #####     #     #     @

*/

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

void add(ll &x, ll y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

ll cnt[32][2][2][2];
ll sum[32][2][2][2];

bool get_bit(int x, int bit) {
    return x & (1 << bit);
}

ll get(int x, int y, int k) {
    if (x < 0 || y < 0) return 0;
    memset(cnt, 0, sizeof cnt);
    memset(sum, 0, sizeof sum);
    cnt[31][1][1][1] = 1;
    sum[31][1][1][1] = 0;
    for (int bit = 31; bit > 0; bit--) {
        rep(a, 0, 2) rep(b, 0, 2) rep(c, 0, 2) rep(wx, 0, 2) rep(wy, 0, 2) {
            int wk = wx ^ wy;
            int bx = get_bit(x, bit - 1);
            int by = get_bit(y, bit - 1);
            int bk = get_bit(k, bit - 1);
            
            if (a && wx > bx) continue;
            if (b && wy > by) continue;
            if (c && wk > bk) continue;
            
            add(cnt[bit - 1][a && (bx == wx)][b && (by == wy)][c && (bk == wk)], cnt[bit][a][b][c]);
            add(sum[bit - 1][a && (bx == wx)][b && (by == wy)][c && (bk == wk)], sum[bit][a][b][c]);
            add(sum[bit - 1][a && (bx == wx)][b && (by == wy)][c && (bk == wk)], (wk ? 1 << (bit - 1) : 0) * cnt[bit][a][b][c] % MOD);
        }
    }
    
    ll res = 0;
    rep(a, 0, 2) rep(b, 0, 2) rep(c, 0, 2) add(res, sum[0][a][b][c] + cnt[0][a][b][c]);
    return res;
}

void solve() {
    int x1, y1, x2, y2, k;
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    x1--; y1--; x2--; y2--; k--;
    ll ans = get(x2, y2, k) + get(x1 - 1, y1 - 1, k) - get(x2, y1 - 1, k) - get(x1 - 1, y2, k);
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << "\n";
}

void run() {
    int q;
    cin >> q;
    rep(i, 0, q) solve();
}