#include "bits/stdc++.h"


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 2e9;
const ll INF = 2e18;
const int LG = 20;
const int md = 1e9 + 7;



struct fenwick {
    int n{};
    vector<ll> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, ll x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    ll get(int i) {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    ll get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, q; cin >> n >> q;
    const int C = 50;
    map<int, ll> to;
    vi a(n);
    vector<fenwick> f(C);
    auto set = [&] (int i, int x, int v) {
        if (!to.count(x)) {
            to[x] = rng();
        }
        ll val = to[x];
        for(ll b = 0; b < C; ++b) {
            if ((1ll << b) & val) {
                f[b].upd(i, v);
            }
        }
    };
    rep(i, C) f[i].build(n);
    rep(i, n) {
        cin >> a[i];
        set(i, a[i], 1);
    }
    rep(_, q) {
        int tp; int x, y; cin >> tp >> x >> y;
        if (tp == 1) {
            // a[x] = y
            x--;
            set(x, a[x], -1);
            a[x] = y;
            set(x, a[x], 1);
        } else {
            int k; cin >> k;
            x--;
            // [x, y) %= k;
            bool ok = true;
            rep(i, C) {
                ok &= ((f[i].get(x, y - 1)) % k == 0);
            }
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}