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

int n, w;
ll x[N], v[N];

struct F {
    ll p, q;
    
    F() {}
    
    F(ll pp, ll qq) {
        p = pp;
        q = qq;
        if (q < 0) {
            p = -p;
            q = -q;
        }
        assert(p >= 0);
        assert(q > 0);
    }
    
    bool operator<(const F &b) const {
        return p * b.q < b.p * q;
    }
    
    bool operator==(const F &b) const {
        return p * b.q == b.p * q;
    }
};

pair<F, int> a[N], b[N];
int valb[N];
int f[N];

void add(int x, int y) {
    x++;
    for (; x < N; x += x & (-x)) f[x] += y;
}

int get(int r) {
    r++;
    int res = 0;
    for (; r > 0; r -= r & (-r)) {
        res += f[r];
    }
    return res;
}

void run() {
    cin >> n >> w;
    rep(i, 0, n) {
        cin >> x[i] >> v[i];
        a[i] = {F(-x[i], v[i] + w), i};
        b[i] = {F(-x[i], v[i] - w), i};
    }
    sort(a, a + n);
    sort(b, b + n);
    int qq = 0;
    rep(i, 0, n) {
        int j = i;
        while (j + 1 < n && b[j + 1].first == b[j].first) {
            j++;
        }
        rep(k, i, j + 1) valb[b[k].second] = qq;
        qq++;
        i = j;
    }
    ll ans = 0;
    map<int, int> shit;
    rep(i, 0, n) {
        int j = i;
        while (j + 1 < n && a[j + 1].first == a[j].first) {
            j++;
        }
        rep(k, i, j + 1) {
            add(valb[a[k].second], +1);
        }
        rep(k, i, j + 1) {
            ans += (j + 1) - get(valb[a[k].second] - 1);
        }
        shit.clear();
        rep(k, i, j + 1) {
            shit[valb[a[k].second]]++;
        }
        for (auto &it : shit) {
            ans -= it.second * 1LL * (it.second - 1) / 2;
        }
        i = j;
    }
    ans -= n;
    cout << ans << "\n";
}