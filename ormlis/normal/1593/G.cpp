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

struct FSegTree {
    struct Node {
        int start;
        int len;

        Node(int _val = 0) : start(_val), len(0) {}

        void combine(const Node &a, const Node &b) {
            if (a.len == 0) {
                start = b.start;
                len = b.len;
                return;
            }
            if (b.len == 0) {
                start = a.start;
                len = a.len;
                return;
            }
            if ((a.start + a.len) % 2 == b.start) {
                start = a.start;
                len = a.len + b.len;
                return;
            }
            if (a.len == b.len) {
                start = 0;
                len = 0;
                return;
            }
            if (a.len > b.len) {
                start = a.start;
                len = a.len - b.len;
                return;
            }
            if (a.len < b.len) {
                start = a.start ^ 1;
                len = b.len - a.len;
            }
        }

        void apply(int x) {
            start = x;
            len = 1;
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
        n = v.size();
        t.resize(n * 2 + 2);
        range(i, n) t[i + n].apply(v[i]);
        for (int i = n - 1; i >= 0; --i) t[i].combine(t[i << 1], t[i << 1 | 1]);
    }

    void upd(int i, int x) {
        for (t[i += n].apply(x); i > 1; i >>= 1) t[i >> 1].combine(t[i], t[i ^ 1]);
    }

    // [l, r)
    Node get(int l, int r) {
        Node resL, resR;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resL = combine(resL, t[l++]);
            if (r & 1) resR = combine(t[--r], resR);
        }
        return combine(resL, resR);
    }
};

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vi a(n);
    rep(i, n) {
        if (s[i] == '(' || s[i] == ')') a[i] = 1;
    }
    FSegTree st;
    st.build(a);
    int q; cin >> q;
    rep(_, q) {
        int l, r; cin >> l >> r;
        l--;
        r--;
        cout << st.get(l, r + 1).len / 2 << '\n';
    }
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