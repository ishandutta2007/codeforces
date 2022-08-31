#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
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
using namespace __gnu_pbds;

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

struct FSegTree {
    struct Node {
        int value;

        Node(int _val = -INFi) : value(_val) {}

        void combine(const Node &a, const Node &b) {
            value = max(a.value, b.value);
        }

        void apply(int x) {
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
        Node result;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) result = combine(result, t[l++]);
            if (r & 1) result = combine(result, t[--r]);
        }
        return result;
    }
};


struct dsu {
    vector<int> dsu;
    vector<set<int>> q;
    vector<int> ans;
    int n;

    int get_dsu(int a) {
        if (dsu[a] == a) return a;
        return dsu[a] = get_dsu(dsu[a]);
    }

    void build(int k) {
        n = k;
        dsu.resize(n);
        q.resize(n);
        range(i, n)dsu[i] = i;
    }

    void addq(int x, int y) {
        int i = ans.size();
        ans.emplace_back(-1);
        q[x].insert(i);
        q[y].insert(i);
    }

    bool unio(int a, int b, int c) {
        a = get_dsu(a), b = get_dsu(b);
        if (rand() % 2) swap(a, b);
        if (a == b) return false;
        if (q[a].size() > q[b].size()) swap(q[a], q[b]);
        for (auto x : q[a]) {
            if (q[b].count(x)) {
                ans[x] = c;
                q[b].erase(x);
            } else {
                q[b].insert(x);
            }
        }
        q[a].clear();
        dsu[a] = b;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    int q;
    cin >> q;
    dsu d;
    d.build(n);
    rep(i, n - 1) d.addq(i, i + 1);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        d.unio(u, v, i + 1);
    }
    FSegTree st;
    st.build(d.ans);
    rep(_, q) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << max(0, st.get(l, r).value) << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}