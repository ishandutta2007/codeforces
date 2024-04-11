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

const int INFi = 2e9;

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
        return get(r) - get(l - 1);
    }
};


template<class T, class Fun = function<T(const T &, const T &)>>
struct SparseTable {
    vector<vector<T>> sp;
    Fun f;

    SparseTable(vector<T> &a, const Fun &g) : f(g) {
        int n = a.size();
        int lg = __lg(n) + 1;
        sp.resize(lg, vector<T>(n));
        rep(i, n) sp[0][i] = a[i];
        rep(j, lg - 1) {
            rep(i, n) {
                if (i + (1 << (j + 1)) > n) break;
                sp[j + 1][i] = f(sp[j][i], sp[j][i + (1 << j)]);
            }
        }
    }

    // [l, r)
    T get(int l, int r) {
        int k = __lg(r - l);
        return f(sp[k][l], sp[k][r - (1 << k)]);
    }
};

void solve() {
    int n, q, k;
    cin >> n >> q >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi l(q), r(q);
    vvi to(n);
    rep(i, q) {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
        to[l[i]].push_back(i);
    }
    vl ans(q);
    SmartFenwick f;
    f.build(n);
    SparseTable st(a, [&](const int &x, const int &y) {
        return min(x, y);
    });
    rep(w, k) {
        int start = n - 1 - w;
        if (start < 0) break;
        vector<pair<int, int>> stk;
        stk.emplace_back(-INFi, n);
        for (int i = start, j = n - 1; i >= 0; i -= k, j--) {
            if (j + 1 != n) {
                int cur = st.get(i, min(i + k + 1, n));
                int p = j + 1;
                f.upd(p, p + 1, cur);
                while (!stk.empty() && stk.back().first >= cur) {
                    int L = stk.back().second;
                    int v = stk.back().first;
                    stk.pop_back();
                    int R = stk.back().second;
                    f.upd(L, R, -v + cur);
                }
                stk.emplace_back(cur, j + 1);
            }
            for(auto &e : to[i]) {
                ans[e] = a[i];
                int len = (r[e] - l[e]) / k;
                if (len >= 1) {
                    ans[e] += f.get(j + 1, j + len);
                }
            }
        }
        reverse(all(stk));
        for(int i = 1; i < (int)stk.size(); ++i) {
            f.upd(stk[i - 1].second, stk[i].second, -stk[i - 1].first);
        }
    }
    rep(i, q) cout << ans[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}