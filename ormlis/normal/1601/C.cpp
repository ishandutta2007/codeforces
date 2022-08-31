#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
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

const ll INF = 2e18;
struct SegTree {
    struct Node {
        ll mn;
        ll upd;

        Node() : mn(INF), upd(0) {}

        void combine(const Node &a, const Node &b) {
            mn = min(a.mn, b.mn) + upd;
        }

        void check(ll x) {
            mn = x;
            upd = 0;
        }

        void update(ll x) {
            upd += x;
            mn += x;
        }
    };

    vector<Node> t;
    int n;

    void build(int sz) {
        n = 2;
        while (n < sz) n *= 2;
        t.resize(n * 2 + 5);
        range(i, sz) {
            t[i + n].check(i);
        }
        for(int i = n - 1; i >= 1; --i) {
            t[i].combine(t[i << 1], t[i << 1 | 1]);
        }
    }

    void upd(int v, int l, int r, int lq, int rq, ll x) {
        if (lq >= r || l >= rq) return;
        if (lq <= l && r <= rq) {
            t[v].update(x);
            return;
        }
        upd(v << 1, l, (l + r) >> 1, lq, rq, x);
        upd(v << 1 | 1, (l + r) >> 1, r, lq, rq, x);
        t[v].combine(t[v << 1], t[v << 1 | 1]);
    }

    // [l, r)
    void upd(int l, int r, ll x) {
        upd(1, 0, n, l, r, x);
    }

    Node get(int v, int l, int r, int lq, int rq) {
        Node result;
        if (l >= rq || lq >= r) return result;
        if (lq <= l && r <= rq) {
            result = t[v];
            return result;
        }
        auto L = get(v << 1, l, (l + r) >> 1, lq, rq);
        auto R = get(v << 1 | 1, (l + r) >> 1, r, lq, rq);
        result.combine(L, R);
        result.update(t[v].upd);
        return result;
    }

    Node get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};

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

void solve() {
    int n, m; cin >> n >> m;
    vi a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    sort(all(b));
    SegTree st;
    st.build(n + 1);
    int l = 0, r = 0;
    vector<pair<int, int>> c(n);
    rep(i, n) c[i] = {a[i], i};
    sort(all(c));
    ll ans = 0;
    rep(i, m) {
        while(r < n && c[r].first <= b[i]) {
            st.upd(c[r].second + 1, n + 1, -1);
            r++;
        }
        while(l < n && c[l].first < b[i]) {
            st.upd(c[l].second + 1, n + 1, -1);
            l++;
        }
        ll cur = l;
        cur += st.get(0, n + 1).mn;
        ans += cur;
    }
    ll ans2 = 0;
    fenwick f;
    f.build(n);
    for(int i = 0, j = 0; i < n; i = j) {
        while(j < n && c[j].first == c[i].first) j++;
        for(int e = i; e < j; ++e) {
            ans2 += f.get(c[e].second + 1, n - 1);
        }
        for(int e = i; e < j; ++e) {
            f.upd(c[e].second, 1);
        }
    }
    cout << ans + ans2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}