#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int D = 22;
const int M = 62;
const int B = 62;
const int N = 30228;

int n, d, m;

ll MASK;

int gen[D];
int b[N];

ll rot(ll x, int y) {
    return ((x >> y) + (x << (m - y))) & MASK;
}

struct LBorder {
    ll g[N];
    ll len;

    LBorder() : g{}, len(0) {
        fill(g, g + n + 1, MASK);
    }

    ll at(ll x) const {
        return (x < n) ? g[x] : MASK;
    }

    LBorder rot(int y) const {
        LBorder ans;
        ans.len = len;

        for (int i = 0; i < n; ++i) {
            ans.g[i] = ::rot(g[i], y);
        }

        return ans;
    }

    friend LBorder operator + (const LBorder& lhs, const LBorder& rhs) {
        LBorder ans;
        ans.len = lhs.len + rhs.len;

        for (int i = 0; i <= n; ++i) {
            ans.g[i] = lhs.at(i) & rhs.at(i + lhs.len);
        }

        return ans;
    }
};

struct RBorder {
    ll g[N];
    ll len;

    RBorder() : g{}, len(0) {
        fill(g, g + n + 1, MASK);
    }

    ll at(ll x) const {
        return (x > 0) ? g[x] : MASK;
    }

    RBorder rot(int y) const {
        RBorder ans;
        ans.len = len;

        for (int i = 0; i < n; ++i) {
            ans.g[i] = ::rot(g[i], y);
        }

        return ans;
    }

    friend RBorder operator + (const RBorder& lhs, const RBorder& rhs) {
        RBorder ans;
        ans.len = lhs.len + rhs.len;

        for (int i = 0; i <= n; ++i) {
            ans.g[i] = rhs.at(i) & lhs.at(i - rhs.len);
        }

        return ans;
    }
};

struct Value {
    LBorder l;
    RBorder r;
    ll a[M];

    Value() : a{} {
    }

    void solo() {
        for (int i = 0; i < n; ++i) {
            l.g[i] = r.g[i + 1] = (1ll << (b[i] + 1)) - 1;
        }

        l.len = r.len = 1;

        if (n == 1) {
            for (int i = 0; i <= b[0]; ++i) {
                ++a[i];
            }
        }
    }

    ll len() const {
        return l.len;
    }

    Value rot(int y) const {
        Value res;
        res.l = l.rot(y);
        res.r = r.rot(y);
        for (int i = 0; i < m; ++i) {
            res.a[i] = a[(i + y) % m];
        }

        return res;
    }

    friend Value operator + (const Value& lhs, const Value &rhs) {
        Value ans;
        ans.l = lhs.l + rhs.l;
        ans.r = lhs.r + rhs.r;
        for (int i = 0; i < m; ++i) {
            ans.a[i] = lhs.a[i] + rhs.a[i];
        }

        for (int i = 1; i < n; ++i) {
            if (i <= lhs.len() && i + rhs.len() >= n) {
                ll cur = lhs.r.at(i) & rhs.l.at(i);
                for (int j = 0; j < m; ++j) {
                    ans.a[j] += (cur >> j) & 1;
                }
            }
        }

        return ans;
    }
};

Value f[B];
ll pw[B];

int k;

void precalc(ll r) {
    f[0].solo();

    pw[0] = 1;
    while (r / pw[k] >= d) {
        ++k;
        f[k] = Value();

        pw[k] = pw[k - 1] * d;
        for (int i = 0; i < d; ++i) {
            f[k] = f[k] + f[k - 1].rot(gen[i]);
        }
    }
}

ll eval(ll x) {
    int y = 0;
    Value cur;
        
    for (int i = k; i >= 0; --i) {
        int cn = x / pw[i];
        assert(cn < d);
        for (int j = 0; j < cn; ++j) {
            cur = cur + f[i].rot((y + gen[j]) % m);
        }

        y = (y + gen[cn]) % m;
        x %= pw[i];
    }

    return cur.a[0];
}

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
    cin >> d >> m;
    MASK = (1ll << m) - 1;
    for (int i = 0; i < d; ++i) {
        cin >> gen[i];
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    ll l, r;
    cin >> l >> r;
    precalc(r);

    ll ar = eval(r);
    ll al = eval(l + n - 2);

    cout << ar - al << "\n";
}