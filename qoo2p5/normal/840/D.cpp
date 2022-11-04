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

const int N = (int) 3e5 + 123;
const int TRY = 65;

struct Q {
    int l, r, k, id;
};

int n, q;
int a[N];
vector<int> p[N];
vector<Q> tmp[N];
int res[N];

inline int get(int l, int x) {
    return (int) (p[x].end() - lower_bound(p[x].begin(), p[x].end(), l));
}

void run() {
    mt19937 rnd(rand() * 2 + 4132);
    cin >> n >> q;
    read(a, a + n);
    rep(qq, 0, q) {
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;
        tmp[r].pb({l, r, k, qq});
    }
    
    rep(r, 0, n) {
        p[a[r]].pb(r);
        for (Q &t : tmp[r]) {
            int l = t.l;
            int k = t.k;
            int ans = INF;
            int len = r - l + 1;
            
            if (len <= TRY) {
                rep(i, l, r + 1) {
                    if (get(l, a[i]) * k > len) mini(ans, a[i]);
                }
            } else {
                rep(i, 0, TRY) {
                    int toadd = (((int) rnd()) % len);
                    if (toadd < 0) toadd += len;
                    int pos = l + toadd;
                    if (get(l, a[pos]) * k > len) mini(ans, a[pos]);
                }
            }
            
            res[t.id] = (ans == INF ? -1 : ans);
        }
    }
    
    rep(i, 0, q) cout << res[i] << "\n";
}