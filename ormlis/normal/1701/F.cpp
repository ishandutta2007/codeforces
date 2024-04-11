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
const int maxN = 2e5 + 30;
const int LG = 20;

struct segment_tree {
    int n{};
    struct Node {
        ll sum;
        ll cnt;
        ll upd;

        void apply(ll x) {
            upd += x;
            sum += cnt * x;
        }

        void change(ll x) {
            sum = x;
            cnt ^= 1;
        }

        void combine(const Node &a, const Node &b) {
            sum = a.sum + b.sum;
            cnt = a.cnt + b.cnt;
        }

        Node() : sum(0), cnt(0), upd(0) {}
    };
    vector<Node> t{};

    void build(int k) {
        n = k;
        t.resize(n * 4);
    }

    void push(int v) {
        if (!t[v].upd) return;
        t[v << 1].apply(t[v].upd);
        t[v << 1 | 1].apply(t[v].upd);
        t[v].upd = 0;
    }

    void change(int v, int l, int r, int pos, ll x) {
        if (l > pos || r <= pos) return;
        if (l + 1 == r) {
            t[v].change(x);
            return;
        }
        push(v);
        change(v << 1, l, (l + r) >> 1, pos, x);
        change((v << 1) + 1, (l + r) >> 1, r, pos, x);
        t[v].combine(t[v << 1], t[v << 1 | 1]);
    }
    void upd(int v, int l, int r, int lq, int rq, ll x) {
        if (l >= rq || r <= lq) return;
        if (lq <= l && r <= rq) {
            t[v].apply(x);
            return;
        }
        push(v);
        upd(v << 1, l, (l + r) >> 1, lq, rq, x);
        upd((v << 1) + 1, (l + r) >> 1, r, lq, rq, x);
        t[v].combine(t[v << 1], t[v << 1 | 1]);
    }

    Node get(int v, int l, int r, int lq, int rq) {
        if (l >= rq || r <= lq) return Node();
        if (lq <= l && r <= rq) return t[v];
        push(v);
        Node res;
        res.combine(get(v << 1, l, (l + r) >> 1, lq, rq),
                   get((v << 1) + 1, (l + r) >> 1, r, lq, rq));
        return res;
    }

    void change(int pos, ll x) {
        change(1, 0, n, pos, x);
    }

    void upd(int lq, int rq, ll x) {
        upd(1, 0, n, lq, rq, x);
    }

    Node get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};


void solve() {
    int q, d; cin >> q >> d;
    int A = 2e5 + 10;
    segment_tree st;
    st.build(A * 3);
    ll ans = 0;
    rep(_, q) {
        int x; cin >> x;
        x += A;
        auto p = st.get(x, x + 1);
        if (p.cnt == 0) {
            auto R = st.get(x + 1, x + d + 1);
            st.change(x, R.cnt);
            ans += R.cnt * (R.cnt - 1) / 2;
            ans += st.get(x - d, x).sum;
            st.upd(x - d, x, 1);
        } else {
            assert(p.cnt == 1);
            auto R = st.get(x + 1, x + d + 1);
            st.change(x, 0);
            st.upd(x - d, x, -1);
            ans -= R.cnt * (R.cnt - 1) / 2;
            ans -= st.get(x - d, x).sum;
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    range(i, t) {
        solve();
    }
    return 0;
}