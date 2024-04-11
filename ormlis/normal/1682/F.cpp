#include <bits/stdc++.h>


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
const int maxN = 1e5 + 30;
const int LG = 20;


const int md = 1e9 + 7;

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}


struct fenwick {
    int n{};
    vector<int> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, int x) {
        for (; i < n; i = i | (i + 1)) fenw[i] = add(fenw[i], x);
    }

    int get(int i) {
        int res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res = add(res, fenw[i]);
        return res;
    }

    void upd(int l, int r, int x) {
        // [l, r)
        upd(l, x);
        upd(r, sub(0, x));
    }
};

int normalize_mod(ll x) {
    x %= md;
    return x < 0 ? x + md : x;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vl have = {0};
    {
        ll cur = 0;
        rep(i, n) {
            cur += b[i];
            have.push_back(cur);
            have.push_back(-cur);
        }
    }
    sort(all(have));
    have.resize(unique(all(have)) - have.begin());

    auto get_idx = [&](ll x) {
        return lower_bound(all(have), x) - have.begin();
    };


    int sz = have.size();
    fenwick f1, f0;
    f1.build(sz);
    f0.build(sz);

    ll cur = 0;
    vi res(n + 1);
    rep(i, n) {
        int x = b[i];
        if (x > 0) {
            int L = get_idx(cur - x);
            int R = get_idx(cur);
            f0.upd(0, L, mul(x, a[i]));
            f0.upd(R, sz, sub(0, mul(x, a[i])));
            f1.upd(L, R, sub(0, mul(2, a[i])));
            // - 2 * a[i] * cur + t == -x * a[i]
            // t == a[i] * (2 * cur - x)
            ll val = cur * 2 - x;
            val %= md;
            if (val < 0) val += md;
            f0.upd(L, R, mul(a[i], val));
        } else {
            x = -x;
            int R = get_idx(cur + x);
            int L = get_idx(cur);
            f0.upd(0, L, sub(0, mul(x, a[i])));
            f0.upd(R, sz, mul(x, a[i]));
            f1.upd(L, R, mul(2, a[i]));
            // 2 * a[i] * cur + t == -x * a[i]
            // t == a[i] * (-2 * cur - x)
            ll val = -cur * 2 - x;
            val %= md;
            if (val < 0) val += md;
            f0.upd(L, R, mul(a[i], val));
            x = -x;
        }
        cur -= x;
        ll h = cur % md;
        if (h < 0) h += md;
        int idx = get_idx(cur);
        res[i + 1] = add(mul(f1.get(idx), h), f0.get(idx));
    }
    rep(_, q) {
        int l, r;
        cin >> l >> r;
        cout << sub(res[r], res[l - 1]) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}