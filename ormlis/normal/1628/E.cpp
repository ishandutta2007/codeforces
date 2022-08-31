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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 3e5 + 5;
const int LG = 19;

const int maxM = 1e6;
vector<int> g[maxM];
int value[maxM];
int tin[maxN];
vector<int> a;

void dfs(int v) {
    if (v < maxN) tin[v] = a.size();
    a.push_back(value[v]);
    for (auto &u : g[v]) {
        dfs(u);
        a.push_back(value[v]);
    }
}


struct SparseTable {
    vector<vector<int>> sp;

    void build(vector<int> &a) {
        int n = a.size();
        int lg = __lg(n) + 1;
        sp.resize(lg, vector<int>(n));
        rep(i, n) sp[0][i] = a[i];
        rep(j, lg - 1) {
            rep(i, n) {
                if (i + (1 << (j + 1)) > n) break;
                sp[j + 1][i] = max(sp[j][i], sp[j][i + (1 << j)]);
            }
        }
    }

    // [l, r)
    int get(int l, int r) {
        int k = __lg(r - l);
        return max(sp[k][l], sp[k][r - (1 << k)]);
    }
} ST;


int get_max(int x, int y) {
    if (x == y) return -1;
    x = tin[x];
    y = tin[y];
    if (x > y) swap(x, y);
    return ST.get(x, y);
}


struct segment_tree {
    struct Node {
        int ver;
        int value;
        int upd;
        int pre;

        void check(int x, int l, int r) {
            upd = x;
            if (x == 1) {
                value = pre;
                ver = l;
            } else {
                value = ver = -1;
            }
        }

        void combine(const Node &a, const Node &b) {
            value = max(a.value, b.value);
            if (a.ver != -1 && b.ver != -1) value = max(value, get_max(a.ver, b.ver));
            ver = max(a.ver, b.ver);
        }

        Node() : ver(-1), value(-1), upd(-1), pre(-1) {}
    };

    int n{};
    vector<Node> t{};

    segment_tree(int k) {
        n = k;
        t.resize(n * 4);
        make(1, 0, n);
    }

    void make(int v, int l, int r) {
        if (l + 1 == r) return;
        make(v << 1, l, (l + r) >> 1);
        make(v << 1 | 1, (l + r) >> 1, r);
        t[v].pre = max(t[v << 1].pre, t[v << 1 | 1].pre);
        t[v].pre = max(t[v].pre, get_max(l, r - 1));
    }

    void push(int v, int l, int r) {
        if (t[v].upd == -1) return;
        t[v << 1].check(t[v].upd, l, (l + r) >> 1);
        t[v << 1 | 1].check(t[v].upd, (l + r) >> 1, r);
        t[v].upd = -1;
    }

    void upd(int v, int l, int r, int lq, int rq, int x) {
        if (l >= rq || r <= lq) return;
        if (lq <= l && r <= rq) {
            t[v].check(x, l, r);
            return;
        }
        push(v, l, r);
        upd(v << 1, l, (l + r) >> 1, lq, rq, x);
        upd((v << 1) + 1, (l + r) >> 1, r, lq, rq, x);
        t[v].combine(t[v << 1], t[v << 1 | 1]);
    }

    void upd(int lq, int rq, int x) {
        upd(1, 0, n, lq, rq, x);
    }

    int get(int v) {
        if (t[1].ver == -1) return -1;
        return max(t[1].value, get_max(t[1].ver, v));
    }
};

int dsu[maxM];
int R = maxN;

void init() {
    iota(dsu, dsu + maxM, 0);
}

int get_dsu(int x) {
    return x == dsu[x] ? x : dsu[x] = get_dsu(dsu[x]);
}

void unio(int x, int y, int w) {
    x = get_dsu(x);
    y = get_dsu(y);
    value[R] = w;
    g[R].push_back(x);
    g[R].push_back(y);
    dsu[x] = dsu[y] = R++;
}


void solve() {
    init();
    int n, q;
    cin >> n >> q;
    vector<ar<int, 3>> edges;
    rep(_, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges.push_back({w, u, v});
    }
    sort(all(edges));
    for (auto &[w, u, v] : edges) {
        unio(u, v, w);
    }
    R--;
    dfs(R);
    ST.build(a);
    segment_tree st(n);

    rep(_, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            st.upd(l - 1, r, 1);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            st.upd(l - 1, r, 0);
        } else {
            int x;
            cin >> x;
            cout << st.get(x - 1) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}