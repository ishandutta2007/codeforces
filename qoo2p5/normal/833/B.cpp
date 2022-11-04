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
#define rep(i, f, t) for (auto i = f; i < t; i++)
#define per(i, f, t) for (auto i = f; i >= t; i--)

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

const int N = 1 << 16;
const int K = 52;

struct Tree {
    int to_add[2 * N];
    int tree[2 * N];
    
    void push(int i, int tl, int tr) {
        tree[i] += to_add[i];
        
        if (tl == tr - 1) {
            to_add[i] = 0;
            return;
        }
        
        to_add[2 * i + 1] += to_add[i];
        to_add[2 * i + 2] += to_add[i];
        to_add[i] = 0;
    }
    
    void add(int i, int tl, int tr, int l, int r, int d) {
        push(i, tl, tr);
        if (tl >= r || tr <= l) {
            return;
        }
        
        if (l <= tl && tr <= r) {
            to_add[i] += d;
            push(i, tl, tr);
            return;
        }
        
        int tm = (tl + tr) / 2;
        add(2 * i + 1, tl, tm, l, r, d);
        add(2 * i + 2, tm, tr, l, r, d);
        tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
    }
    
    void add(int l, int r, int d) {
        add(0, 0, N, l, r + 1, d);
    }
    
    int get(int i, int tl, int tr, int l, int r) {
        push(i, tl, tr);
        if (tl >= r || tr <= l) {
            return -INF;
        }
        
        if (l <= tl && tr <= r) {
            return tree[i];
        }
        
        int tm = (tl + tr) / 2;
        return max(get(2 * i + 1, tl, tm, l, r), get(2 * i + 2, tm, tr, l, r));
    }
    
    int get(int l, int r) {
        return get(0, 0, N, l, r + 1);
    }
};

int n, k;
int a[N];
Tree dp[K];
int prv[N];

void run() {
    cin >> n >> k;
    read(a + 1, a + n + 1);
    
    rep(i, 1, n + 1) {
        rep(j, 1, k + 1) {
            if (prv[a[i]]) {
                dp[j - 1].add(0, prv[a[i]] - 1, -1);
            }
            dp[j - 1].add(0, i - 1, +1);
            dp[j].add(i, i, dp[j - 1].get(0, i - 1));
        }
        prv[a[i]] = i;
    }
    
    cout << dp[k].get(n, n) << "\n";
}