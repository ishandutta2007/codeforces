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
const int maxN = 3e5 + 20;

struct FSegTree {
    struct Node {
        ll value;

        Node(ll _val = -INF) : value(_val) {}

        void combine(const Node &a, const Node &b) {
            value = max(a.value, b.value);
        }

        void apply(ll x) {
            value = x;
        }
    };

    Node combine(const Node &a, const Node &b) {
        Node res;
        res.combine(a, b);
        return res;
    }

    vector<Node> t;
    int n;
    template<typename T>
    void build(vector<T> &v) {
        n = v.size();
        t.resize(n * 2 + 2);
        range(i, n) t[i + n].apply(v[i]);
        for (int i = n - 1; i >= 0; --i) t[i].combine(t[i << 1], t[i << 1 | 1]);
    }

    // [l, r)
    Node get(int l, int r) {
        Node result;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) result = combine(result, t[l++]);
            if (r & 1) result = combine(result, t[--r]);
        }
        return result;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> events;
    vi x(n), p(n);
    rep(i, n) cin >> x[i] >> p[i];
    rep(i, n) {
        events.emplace_back(x[i] - p[i], 1);
        events.emplace_back(x[i], -2);
        events.emplace_back(x[i] + p[i], 1);
    }
    ll val = 0;
    ll valp = 0;
    sort(all(events));
    vector<pair<int, ll>> vals;
    ll pos = -INFi;
    for (auto[x, d] : events) {
        if (pos < x) {
            val += valp * (x - pos);
            pos = x;
            vals.emplace_back(pos, val);
        }
        valp += d;
    }
    int sz = vals.size();
    vl A(sz);
    rep(i, sz) A[i] = vals[i].second;
    vl Ap(sz);
    rep(i, sz) Ap[i] = vals[i].second + vals[i].first;
    vl Am(sz);
    rep(i, sz) Am[i] = vals[i].second - vals[i].first;
    FSegTree stA, stAp, stAm;
    stA.build(A);
    stAp.build(Ap);
    stAm.build(Am);
    rep(i, n) {
        pair<int, ll> kek = {x[i], -1};
        int j = lower_bound(all(vals), kek) - vals.begin();
        kek.first += p[i];
        int r = lower_bound(all(vals), kek) - vals.begin();
        kek.first -= p[i] * 2;
        int l = lower_bound(all(vals), kek) - vals.begin();
        assert(l != j && j != r);
        bool ok = true;
        if (r != sz) {
            ok &= (stA.get(r, sz).value <= m);
        }
        if (l != 0) {
            ok &= (stA.get(0, l).value <= m);
        }
        ok &= (stAp.get(j, r).value - x[i] - p[i] <= m);
        ok &= (stAm.get(l, j).value + x[i] - p[i] <= m);
        if (ok) cout << 1;
        else cout << 0;
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}