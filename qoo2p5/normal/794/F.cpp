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

void add(ll &x, ll y, ll mod = MOD) {
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}

/*ll sum(ll x, ll y, ll mod = MOD) {
    add(x, y, mod);
    return x;
}*/

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

const int N = 1 << 17;
const int D = 10;

struct Modif {
    int to[D];
    
    Modif() {
        clear();
    }
    
    void clear() {
        rep(i, 0, D) to[i] = i;
    }
};

int n, q;
int a[N];
ll sum[2 * N][D];
Modif mod[2 * N];

void recalc(int i) {
    rep(d, 0, D) sum[i][d] = sum[2 * i + 1][d] + sum[2 * i + 2][d];
}

void apply(int i) {
    static ll tmp[D];
    fill(tmp, tmp + D, 0);
    rep(d, 0, D) tmp[mod[i].to[d]] += sum[i][d];
    copy(tmp, tmp + D, sum[i]);
}

void add(Modif &a, Modif &b) {
    static int tmp[D];
    rep(d, 0, D) tmp[d] = b.to[a.to[d]];
    copy(tmp, tmp + D, a.to);
}

void push(int i, int tl, int tr) {
    apply(i);
    if (tl != tr - 1) {
        add(mod[2 * i + 1], mod[i]);
        add(mod[2 * i + 2], mod[i]);
    }
    mod[i].clear();
}

void upd(int i, int tl, int tr, int l, int r, int x, int y) {
    push(i, tl, tr);
    
    if (tl >= r || tr <= l) {
        return;
    }
    
    if (l <= tl && tr <= r) {
        mod[i].to[x] = y;
        push(i, tl, tr);
        return;
    }
    
    int tm = (tl + tr) / 2;
    upd(2 * i + 1, tl, tm, l, r, x, y);
    upd(2 * i + 2, tm, tr, l, r, x, y);
    recalc(i);
}

ll calc(int i) {
    ll res = 0;
    rep(d, 0, D) res += sum[i][d] * d;
    return res;
}

ll get(int i, int tl, int tr, int l, int r) {
    push(i, tl, tr);
    
    if (tl >= r || tr <= l) {
        return 0;
    }
    
    if (l <= tl && tr <= r) {
        return calc(i);
    }
    
    int tm = (tl + tr) / 2;
    return get(2 * i + 1, tl, tm, l, r) + get(2 * i + 2, tm, tr, l, r);
}

void build(int i, int tl, int tr) {
    if (tl == tr - 1) {
        int cur = 1;
        while (a[tl]) {
            sum[i][a[tl] % 10] += cur;
            cur *= 10;
            a[tl] /= 10;
        }
        return;
    }
    
    int tm = (tl + tr) / 2;
    build(2 * i + 1, tl, tm);
    build(2 * i + 2, tm, tr);
    recalc(i);
}

void run() {
    cin >> n >> q;
    read(a, a + n);
    build(0, 0, n);
    rep(i, 0, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x, y;
            cin >> l >> r >> x >> y;
            l--; r--;
            upd(0, 0, n, l, r + 1, x, y);
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << get(0, 0, n, l, r + 1) << "\n";
        }
    }
}