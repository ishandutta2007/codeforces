#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int fact[maxN];

int rev(int a) {
    return binpow(a, md - 2);
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxN; ++i) fact[i] = mul(fact[i - 1], i);
}

int C(int n, int k) {
    if (k > n || k < 0) return 0;
    return mul(fact[n], rev(mul(fact[k], fact[n - k])));
}

struct segment_tree {
    struct Node {
        int val = 0;
        int upd_add = 0;
        int upd_mul = 1;

        void check_add(int x, int l, int r) {
            upd_add = add(upd_add, x);
            val = add(val, mul(x, r - l));
        }

        void check_mul(int x) {
            upd_mul = mul(upd_mul, x);
            upd_add = mul(upd_add, x);
            val = mul(val, x);
        }

        void combine(const Node &a, const Node &b) {
            val = add(a.val, b.val);
        }
    };

    int n{};
    vector<Node> tree{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
    }

    void push(int v, int l, int r) {
        if (tree[v].upd_mul != 1) {
            tree[v << 1].check_mul(tree[v].upd_mul);
            tree[(v << 1) + 1].check_mul(tree[v].upd_mul);
            tree[v].upd_mul = 1;
        }
        if (tree[v].upd_add) {
            int mid = (r + l) >> 1;
            tree[v << 1].check_add(tree[v].upd_add, l, mid);
            tree[(v << 1) + 1].check_add(tree[v].upd_add, mid, r);
            tree[v].upd_add = 0;
        }
    }

    void upd(int v, int l, int r, int &lq, int &rq, int &av, int &mv) {
        if (l >= rq || r <= lq) return;
        if (lq <= l && r <= rq) {
            tree[v].check_mul(mv);
            tree[v].check_add(av, l, r);
            return;
        }
        push(v, l, r);
        upd(v << 1, l, (l + r) >> 1, lq, rq, av, mv);
        upd((v << 1) + 1, (l + r) >> 1, r, lq, rq, av, mv);
        tree[v].combine(tree[v << 1], tree[(v << 1) + 1]);
    }

    int get(int v, int l, int r, int lq, int rq) {
        if (l >= rq || r <= lq) return 0;
        if (lq <= l && r <= rq) {
            return tree[v].val;
        }
        push(v, l, r);
        return add(get(v << 1, l, (l + r) >> 1, lq, rq),
                   get((v << 1) + 1, (l + r) >> 1, r, lq, rq));
    }

    void upd(int lq, int rq, int add_v, int mul_v) {
        upd(1, 0, n, lq, rq, add_v, mul_v);
    }

    int get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    segment_tree st;
    st.build(n);

    vector<set<pair<int, int>>> segments(n + 1);
    auto upd = [&](int l, int r, int x) {
        pair<int, int> kek = {l, -1};
        auto it = segments[x].lower_bound(kek);
        int ll = l, rr = r;
        if (it != segments[x].begin()) --it;
        int previ = l;
        while (it != segments[x].end()) {
            auto p = *it;
            if (max(ll, p.first) <= min(rr, p.second)) {
                ll = min(ll, p.first);
                rr = max(rr, p.second);
            }
            if (p.first >= r) {
                if (p.first == r) {
                    segments[x].erase(it);
                }
                break;
            }
            if (p.second <= l) {
                it++;
                if (p.second == l) {
                    segments[x].erase(prev(it));
                }
                continue;
            }
            if (p.first > previ) {
                st.upd(previ, p.first, 1, 1);
            }
            st.upd(max(p.first, l), min(p.second, r), 0, 2);
            ++it;
            segments[x].erase(prev(it));
            previ = min(p.second, r);
        }
        if (previ < r) {
            st.upd(previ, r, 1, 1);
        }
        segments[x].insert({ll, rr});
    };

    range(_, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            upd(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            cout << st.get(l, r) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}