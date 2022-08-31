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

// a, b, c, ab, bc
int get_mask(int maskL, int maskR) {
    if (Bit(maskL, 0) && Bit(maskR, 4)) return -1;
    if (Bit(maskL, 3) && Bit(maskR, 2)) return -1;
    int mask = (maskL | maskR);
    if (Bit(maskL, 0) && Bit(maskR, 1)) mask |= (1 << 3);
    if (Bit(maskL, 1) && Bit(maskR, 2)) mask |= (1 << 4);
    return mask;
}

int to[1 << 5][1 << 5];
const int INFi = 2e9;

struct FSegTree {
    struct Node {
        vector<int> have;

        Node() {
            have.resize(1 << 5, 0);
        }

        void combine(const Node &l, const Node &r) {
            have.assign(1 << 5, INFi);
            rep(maskL, 1 << 5) {
                rep(maskR, 1 << 5) {
                    int mask = to[maskL][maskR];
                    if (mask == -1) continue;
                    have[mask] = min(have[mask], l.have[maskL] + r.have[maskR]);
                }
            }
        }

        void apply(int x) {
            have.assign(1 << 5, 1);
            have[1 << x] = 0;
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
        n = 1;
        while(n < (int)v.size()) n <<= 1;
        t.resize(n * 2);
        range(i, (int)v.size()) {
            t[i + n].apply(v[i]);
        }
        for (int i = n - 1; i >= 0; --i) t[i].combine(t[i << 1], t[i << 1 | 1]);
    }

    void upd(int i, int x) {
        t[i += n].apply(x);
        for (i >>= 1; i >= 1; i >>= 1) t[i].combine(t[i << 1], t[i << 1 | 1]);
    }

    int get() {
        return *min_element(all(t[1].have));
    }
};


void solve() {
    int n, q; cin >> n >> q;
    rep(i, 1 << 5) {
        rep(j, 1 << 5) {
            to[i][j] = get_mask(i, j);
        }
    }
    string s; cin >> s;
    vi v(n);
    rep(i, n) v[i] = s[i] - 'a';
    FSegTree st;
    st.build(v);
    rep(_, q) {
        int i;
        char c; cin >> i >> c;
        st.upd(i - 1, c - 'a');
        cout << st.get() << '\n';
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