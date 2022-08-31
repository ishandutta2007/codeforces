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
#include <functional>
#include <random>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

struct segment_tree {
    struct Node {
        ll val = 0;
        ll upd = 0;
    };

    int n{};
    vector<Node> tree{};

    void build(int k, vector<ll> &a) {
        n = k;
        tree.resize(n * 4);
        make(1, 0, n, a);
    }

    void make(int v, int l, int r, vector<ll> &a) {
        if (l + 1 == r) {
            tree[v].val = a[l];
            return;
        }
        make(v << 1, l, (l + r) >> 1, a);
        make((v << 1) + 1, (l + r) >> 1, r, a);
        tree[v].val = max(tree[v << 1].val, tree[(v << 1) + 1].val);
    }

    void push(int v) {
        tree[v << 1].val += tree[v].upd;
        tree[(v << 1) + 1].val += tree[v].upd;
        tree[v << 1].upd += tree[v].upd;
        tree[(v << 1) + 1].upd += tree[v].upd;
        tree[v].upd = 0;
    }

    void upd(int v, int l, int r, int lq, int rq, ll x) {
        if (l >= rq || r <= lq) return;
        if (lq <= l && r <= rq) {
            tree[v].val += x;
            tree[v].upd += x;
            return;
        }
        push(v);
        upd(v << 1, l, (l + r) >> 1, lq, rq, x);
        upd((v << 1) + 1, (l + r) >> 1, r, lq, rq, x);
        tree[v].val = max(tree[v << 1].val, tree[(v << 1) + 1].val);
    }

    ll get(int v, int l, int r, int lq, int rq) {
        if (l >= rq || r <= lq) return 0;
        if (lq <= l && r <= rq) {
            return tree[v].val;
        }
        return tree[v].upd + get(v << 1, l, (l + r) >> 1, lq, rq) +
               get((v << 1) + 1, (l + r) >> 1, r, lq, rq);
    }

    void upd(int lq, int rq, ll x) {
        upd(1, 0, n, lq, rq, x);
    }

    ll get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};

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
        for (; ~i; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    range(i, n) cin >> a[i];
    segment_tree sta;
    sta.build(n, a);
    vector<ll> b(n), c(n);
    b[0] = 0, c[0] = a[0] - b[0];
    vector<ll> bchng(n), cchng(n);
    for (int i = 1; i < n; ++i) {
        if (a[i] - c[i - 1] < b[i - 1]) {
            b[i] = b[i - 1];
            c[i] = a[i] - b[i];
            bchng[i] = 0;
            cchng[i] = c[i] - c[i - 1];
        } else {
            c[i] = c[i - 1];
            b[i] = a[i] - c[i];
            bchng[i] = b[i] - b[i - 1];
            cchng[i] = 0;
        }
    }
    fenwick fb, fc;
    fb.build(n + 100);
    fc.build(n + 100);
    range(i, n) fb.upd(i, bchng[i]);
    range(i, n) fc.upd(i, cchng[i]);
    int q;
    cin >> q;
    range(i, q + 1) {
        ll w = sta.get(0, 1) + fb.get(n + 5);
        if (w <= 0) {
            w = -(abs(w) / 2);
        } else {
            w = (w - 1) / 2 + 1;
        }
        cout << w << "\n";
        if (i == q) break;
        int l, r; ll x; cin >> l >> r >> x;
        ll wee = x;
        l--; r--;
        if (l != 0) {
            ll prev = sta.get(l-1, l);
            ll cur = sta.get(l, l + 1);
            if (cur >= prev) {
                if (cur + x >= prev) {
                    fb.upd(l, x);
                } else {
                    fb.upd(l, -cur + prev);
                    x = cur + x - prev;
                    fc.upd(l, x);
                }
            } else {
                if (cur + x < prev) {
                    fc.upd(l, x);
                } else {
                    fc.upd(l, -cur + prev);
                    x = cur + x - prev;
                    fb.upd(l, x);
                }
            }
        }
        x = wee;
        if (r != n - 1) {
            ll prev = sta.get(r, r+1);
            ll cur = sta.get(r+1, r+2);
            if (cur >= prev) {
                if (cur >= prev + x) {
                    fb.upd(r+1, -x);
                } else {
                    fb.upd(r+1, -cur + prev);
                    x = cur - prev - x;
                    fc.upd(r+1, x);
                }
            } else {
                if (cur < prev + x) {
                    fc.upd(r+1, -x);
                } else {
                    fc.upd(r+1, -cur + prev);
                    x = cur - prev - x;
                    fb.upd(r+1, x);
                }
            }
        }
        sta.upd(l, r + 1, wee);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}