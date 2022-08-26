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
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = double;
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


struct FSegTree {
    struct Node {
        ll value;
        ll upd;

        Node(ll _val = 0) : value(_val), upd(0) {}

        void combine(const Node &a, const Node &b) {
            value = max(a.value, b.value) + upd;
        }

        void apply(int x) {
            value += x;
            upd += x;
        }
    };

    Node combine(const Node &a, const Node &b) {
        Node res;
        res.combine(a, b);
        return res;
    }

    vector<Node> t;
    int n;

    void build(int k) {
        n = k;
        t.resize(n * 2 + 2);
    }

    template<typename T>
    void build(vector<T> &v) {
        n = 1;
        while (n < (int) v.size()) n <<= 1;
        t.resize(n * 2 + 2);
        range(i, (int) v.size()) {
            t[i + n].apply(v[i]);
        }
        for (int i = n - 1; i >= 0; --i) t[i].combine(t[i << 1], t[i << 1 | 1]);
    }

    void upd(int v, int l, int r, int lq, int rq, int x) {
        if (lq >= r || rq <= l) return;
        if (lq <= l && r <= rq) {
            t[v].apply(x);
            return;
        }
        upd(v << 1, l, (l + r) >> 1, lq, rq, x);
        upd(v << 1 | 1, (l + r) >> 1, r, lq, rq, x);
        t[v].combine(t[v << 1], t[v << 1 | 1]);
    }

    void upd(int lq, int rq, int x) {
        upd(1, 0, n, lq, rq, x);
    }

    int get(int v, int l, int r, int x) {
        if (t[v].value <= x) return -1;
        if (l + 1 == r) return l;
        x -= t[v].upd;
        int a = get(v << 1, l, (l + r) >> 1, x);
        if (a != -1) return a;
        return get(v << 1 | 1, (l + r) >> 1, r, x);
    }

    int get(int x) {
        return get(1, 0, n, x);
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vl a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    for (int i = n - 1; i >= 1; --i) a[i] -= a[i - 1];
    for (int i = m - 1; i >= 1; --i) b[i] -= b[i - 1];
    fenwick fs0, fs1;
    fs0.build(m);
    fs1.build(m);
    rep(i, m) fs0.upd(i, b[i]);

    FSegTree st;
    b[0] = -1;
    st.build(b);

    auto get_sum = [&](int r) {
        if (r <= -1) return 0ll;
        return fs1.get(r) * r + fs0.get(r);
    };

    auto get_s = [&](int l, int r) {
        return get_sum(r) - get_sum(l - 1);
    };
    ll s2 = 0;
    rep(i, m) s2 += 1ll * b[i] * 2 * i;

    auto answer = [&]() {
        int c = 0;
        ll res = 1ll * get_s(0, 0) * (n + m - 1);
        res -= s2 / 2;
        //rep(i, m) cout << get_s(i, i) << ' ';
        //cout << '\n';
        //rep(i, m) cout << get_s2(i, i) << ' ';
        //cout << '\n';
        rep(i, n) {
            res += 1ll * a[i] * (n - i + m - c - 1);
            int nxt;
            if (i == n - 1) nxt = m;
            else nxt = st.get(a[i + 1]);
            if (nxt == -1) nxt = m;
            if (c < nxt - 1) {
                int l = c + 1;
                int r = nxt - 1;
                ll sum = get_s(l, r);
                res += sum * (n + m - i - 1);
                c = r;
            }
        }
        return res;
    };
    // f[l] += d
    // f[l + 1] += d * 2
    // f[i] += (i - l) * d
    // f[i] += d * i - l * d;

    // g[i] += (i - l) * (i - l + 1) / 2 * d
    rep(_, q) {
        int t, k, d;
        cin >> t >> k >> d;
        if (t == 1) {
            for (int i = n - k; i < n; ++i) a[i] += d;
        } else {
            int l = m - k;
            fs0.upd(l, -(l - 1) * d);
            fs1.upd(l, d);
            
            // l, m s2 += i * 2 * d
            s2 += (1ll * (m - 1) * m - 1ll * l * (l - 1)) * d;
            st.upd(l, m, d);
        }
        cout << answer() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(_, t) {
        solve();
    }
    return 0;
}