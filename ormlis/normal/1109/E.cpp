#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

/*
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 2e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int mod;

inline int add(const int &a, const int &b) {
    return a + b >= mod ? a + b - mod : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + mod : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % mod;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int phi;

int rev(int a) {
    return binpow(a, phi - 1);
}

vector<int> mods;
vector<vector<int>> pw;
int cnt;

int get_pow(int i, int b) {
    while (pw[i].size() <= b) {
        int x = pw[i].back();
        x = mul(x, mods[i]);
        pw[i].push_back(x);
    }
    return pw[i][b];
}

struct modular_num {
    vector<int> num;
    int ml;

    modular_num(int x = 1) {
        num.resize(cnt, 0);
        range(i, cnt) {
            while (x % mods[i] == 0) {
                num[i]++;
                x /= mods[i];
            }
        }
        ml = x % mod;
    }

    int get() {
        int res = ml;
        range(i, cnt) {
            res = mul(res, get_pow(i, num[i]));
        }
        return res;
    }
};

modular_num operator+(modular_num a, const modular_num &b) {
    range(i, cnt) a.num[i] += b.num[i];
    a.ml = mul(a.ml, b.ml);
    return a;
}

struct segment_tree {
    struct Node {
        int sum;
        int upd_sum;
        modular_num upd;

        void check(modular_num &num) {
            upd = upd + num;
            upd_sum = mul(sum, upd.get());
        }

        void combine(const Node &a, const Node &b) {
            sum = upd_sum = add(a.upd_sum, b.upd_sum);
        }

        Node() : sum(0), upd_sum(0) {}
    };

    vector<Node> tree{};
    int n{};

    void build(vector<int> &a) {
        n = a.size();
        tree.resize(n * 4);
        make(1, 0, n, a);
    }

    void make(int v, int l, int r, vector<int> &a) {
        if (l + 1 == r) {
            tree[v].sum = tree[v].upd_sum = 1;
            auto mn = modular_num(a[l]);
            tree[v].check(mn);
            return;
        }
        make(v << 1, l, (l + r) >> 1, a);
        make(v << 1 | 1, (l + r) >> 1, r, a);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    void push(int v) {
        if (tree[v].upd.get() == 1) return;
        tree[v << 1].check(tree[v].upd);
        tree[v << 1 | 1].check(tree[v].upd);
        tree[v].upd = modular_num();
        tree[v].sum = tree[v].upd_sum;
    }

    void upd(int v, int l, int r, int lq, int rq, modular_num &x) {
        if (l >= rq || r <= lq) return;
        if (lq <= l && r <= rq) {
            tree[v].check(x);
            return;
        }
        push(v);
        upd(v << 1, l, (l + r) >> 1, lq, rq, x);
        upd(v << 1 | 1, (l + r) >> 1, r, lq, rq, x);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    int get(int v, int l, int r, int &lq, int &rq) {
        if (l >= rq || r <= lq) return 0;
        if (lq <= l && r <= rq) return tree[v].upd_sum;
        push(v);
        return (get(v << 1, l, (l + r) >> 1, lq, rq) +
                get(v << 1 | 1, (l + r) >> 1, r, lq, rq)) % mod;
    }

    int get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }

    void upd(int lq, int rq, modular_num x) {
        upd(1, 0, n, lq, rq, x);
    }
};

void init() {
    int x = mod;
    phi = x;
    auto add = [&](int p) {
        phi -= phi / p;
        mods.push_back(p);
        pw.push_back({1});
    };
    for (int p = 2; p * p <= x; ++p) {
        if (x % p == 0) {
            add(p);
            while (x % p == 0) x /= p;
        }
    }
    if (x != 1) add(x);
    cnt = mods.size();
}

void solve() {
    int n;
    cin >> n >> mod;
    init();
    segment_tree st;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    st.build(a);
    int q;
    cin >> q;
    range(_, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            modular_num mn(x);
            st.upd(l, r, mn);
        } else if (t == 2) {
            int p, x;
            cin >> p >> x;
            modular_num mn(x);
            p--;
            range(i, cnt) {
                mn.num[i] *= -1;
            }
            mn.ml = rev(mn.ml);
            st.upd(p, p + 1, mn);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.get(l - 1, r) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}