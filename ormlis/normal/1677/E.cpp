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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 1e6 + 20;
const int LG = 100;


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


struct SmartFenwick {
    fenwick f1, f2;

    void build(int n) {
        f1.build(n);
        f2.build(n);
    }

    // [l, r)
    void upd(int l, int r, ll w) {
        // (i - (l - 1)) * w
        f2.upd(l, w);
        f2.upd(r, -w);
        f1.upd(l, -(l - 1) * w);
        f1.upd(r, (r - 1) * w);
    }

    ll get(int r) {
        return f2.get(r) * r + f1.get(r);
    }

    ll get(int l, int r) {
        return get(r - 1) - get(l - 1);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vi p(n);
    rep(i, n) cin >> p[i];
    vi pos(n + 1);
    rep(i, n) {
        pos[p[i]] = i;
    }
    vector<vpi> to(n + 1);
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y < x && y * x <= n; ++y) {
            int z = x * y;
            int l = min({pos[x], pos[y], pos[z]});
            int r = max({pos[x], pos[y], pos[z]});
            to[z].emplace_back(r, l);
        }
    }
    set<int> alive;
    alive.insert(-1);
    alive.insert(n);
    vector<ar<int, 4>> rects;
    vector<ar<int, 3>> events;
    for (int z = n; z >= 1; --z) {
        int pz = pos[z];
        auto it = alive.lower_bound(pz);
        int R = *it;
        int L = *prev(it);
        alive.insert(pz);
        sort(all(to[z]));
        vpi need;
        for (auto &[r, l] : to[z]) {
            if (r >= R || l <= L) continue;
            if (!need.empty() && need.back().first > l) continue;
            need.emplace_back(l, r);
        }
        int prv = L;
        for (auto &[l, r] : need) {
            rects.push_back({prv + 1, l, r, R - 1});
            prv = l;
        }
    }
    rep(i, (int) rects.size()) {
        events.push_back({rects[i][0], -1, i});
        events.push_back({rects[i][1], 1, i});
    }
    vi lq(q), rq(q);
    rep(i, q) {
        cin >> lq[i] >> rq[i];
        lq[i]--;
        rq[i]--;
        events.push_back({lq[i] - 1, 2, i});
        events.push_back({rq[i], 3, i});
    }
    vl ans(q);
    sort(all(events));
    SmartFenwick fx, fa;
    fx.build(n + 2);
    fa.build(n + 2);
    for (auto &[x, tp, i] : events) {
        if (tp > 1) {
            ll res = 1ll * fx.get(lq[i], rq[i] + 1) * x + fa.get(lq[i], rq[i] + 1);
            if (tp == 2) {
                ans[i] -= res;
            } else {
                assert(tp == 3);
                ans[i] += res;
            }
        } else {
            if (tp == -1) {
                fx.upd(rects[i][2], rects[i][3] + 1, 1);
                fa.upd(rects[i][2], rects[i][3] + 1, -(x - 1));
            } else {
                fx.upd(rects[i][2], rects[i][3] + 1, -1);
                fa.upd(rects[i][2], rects[i][3] + 1, x);
            }
        }
    }
    rep(i, q) cout << ans[i] << '\n';
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