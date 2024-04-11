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
#define int long long

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
const int maxN = 2e5 + 20;
const int LG = 30;

struct pers_seg_tree {
    struct Node {
        ll k;
        ll a;
        int l, r;

        Node() : k(0), a(0), l(-1), r(-1) {}
    };

    vector<Node> tree{};
    vector<int> starts{};
    int cur_start{};
    int n{};

    void build(int k, vector<int> &a) {
        n = k;
        starts.push_back(0);
        cur_start = 0;
        make(0, n, a);
    }

    int make(int l, int r, vector<int> &a) {
        int e = tree.size();
        tree.emplace_back();
        if (l + 1 == r) {
            tree[e].k = a[l];
            return e;
        }
        int x = make(l, (l + r) >> 1, a);
        tree[e].l = x;
        x = make((l + r) >> 1, r, a);
        tree[e].r = x;
        tree[e].a = tree[tree[e].l].a + tree[tree[e].r].a;
        tree[e].k = tree[tree[e].l].k + tree[tree[e].r].k;
        return e;
    }

    int upd(int v, int l, int r, int pos, int x) {
        if (pos < l || pos >= r) return v;
        int e = tree.size();
        tree.push_back({});
        if (l + 1 == r) {
            tree[e] = tree[v];
            tree[e].k = 0;
            tree[e].a = x;
            return e;
        }
        tree[e] = tree[v];
        int w = upd(tree[v].l, l, (l + r) >> 1, pos, x);
        tree[e].l = w;
        w = upd(tree[v].r, (l + r) >> 1, r, pos, x);
        tree[e].r = w;
        tree[e].a = tree[tree[e].l].a + tree[tree[e].r].a;
        tree[e].k = tree[tree[e].l].k + tree[tree[e].r].k;
        return e;
    }

    void change_version(int k) {
        cur_start = starts[k];
    }

    int get(int v, int l, int r, int lq, int rq, ll C, ll &have) {
        if (l >= rq || r <= lq) return -1;
        ll val = 1ll * C * tree[v].k + tree[v].a;
        if (lq <= l && r <= rq && val <= have) {
            have -= val;
            return -1;
        }
        if (l + 1 == r) return l;
        auto x = get(tree[v].l, l, (l + r) >> 1, lq, rq, C, have);
        if (x != -1) return x;
        return get(tree[v].r, (l + r) >> 1, r, lq, rq, C, have);
    }

    int get(int lq, int rq, ll C, ll &have) {
        return get(cur_start, 0, n, lq, rq, C, have);
    }

    void upd(int pos, int x) {
        int s = upd(cur_start, 0, n, pos, x);
        cur_start = s;
    }

    void save_version() {
        starts.push_back(cur_start);
    }
} ST;

void solve() {
    int n;
    cin >> n;
    vi c(n), r(n);
    rep(i, n) cin >> c[i] >> r[i];
    int q;
    cin >> q;
    vl t(q), h(q);
    rep(i, q) cin >> t[i] >> h[i];
    ST.build(n, r);
    int S = t[q - 1];
    {
        vi ord(n);
        iota(all(ord), 0);
        sort(all(ord), [&](const int &i, const int &j) {
            return (c[i] + r[i] - 1) / r[i] < (c[j] + r[j] - 1) / r[j];
        });
        int j = 0;
        for (int dt = 1; dt <= S; ++dt) {
            while (j < n) {
                int val = (c[ord[j]] + r[ord[j]] - 1) / r[ord[j]];
                if (val != dt) break;
                ST.upd(ord[j], c[ord[j]]);
                j++;
            }
            ST.save_version();
        }
        while (j < n) {
            ST.upd(ord[j], c[ord[j]]);
            j++;
        }
        ST.save_version();
    }
    vector<ar<ll, 3>> stk;
    stk.push_back({n, INF, -INFi});
    for (int i = 0; i < q; ++i) {
        int l = 0;
        ll hp = h[i];
        int tt = t[i];
        while (hp > 0) {
            auto[j, have, t] = stk.back();
            int dt = min(tt - t, 1ll * S + 1);
            if (l < j) {
                ST.change_version(dt);
                int d = ST.get(l, j, dt, hp);
                if (d != -1) {
                    assert(l <= d && d < j);
                    ll was;
                    if (dt == S + 1) {
                        was = c[d];
                    } else {
                        was = min(c[d], dt * r[d]);
                    }
                    assert(was >= hp);
                    stk.push_back({d, was - hp, tt});
                    hp = 0;
                    break;
                }
            }
            stk.pop_back();
            if (j != n) {
                have = min(have + 1ll * r[j] * dt, 1ll * c[j]);
            }
            t = tt;
            if (have >= hp) {
                have -= hp;
                stk.push_back({j, have, t});
                break;
            }
            hp -= have;
            l = j + 1;
        }
    }
    cout << INF - stk[0][1] << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}