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
#include <cassert>
#include <iomanip>
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace __gnu_pbds;

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9;
const int maxN = 2e5 + 1;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct segment_tree {
    struct Node {
        ll sum = 0;
        int mn = 0, s_mn = INFi;
        int cnt = 0;
        int upd = 0;
        int updsum = 0;

        void combine(const Node &a, const Node &b) {
            mn = min(a.mn, b.mn);
            cnt = a.cnt + b.cnt;
            s_mn = INFi;
            if (b.mn != mn) {
                cnt -= b.cnt;
                s_mn = b.mn;
            } else if (a.mn != mn) {
                s_mn = a.mn;
                cnt -= a.cnt;
            }
            s_mn = min(s_mn, min(a.s_mn, b.s_mn));
            sum = a.sum + b.sum;
        }

        void check(int &val) {
            if (mn >= val) return;
            sum += 1ll * cnt * (val - mn);
            mn = val;
            upd = val;
        }

        void checkadd(int &val, int l, int r) {
            mn += val;
            s_mn += val;
            updsum += val;
            upd += val;
            sum += 1ll * val * (r - l);
        }
    };

    void push(int v, int l, int r) {
        tree[v << 1].checkadd(tree[v].updsum, l, (l + r) >> 1);
        tree[(v << 1) + 1].checkadd(tree[v].updsum, (l + r) >> 1, r);
        tree[v << 1].check(tree[v].upd);
        tree[(v << 1) + 1].check(tree[v].upd);
        tree[v].updsum = 0;
    }

    vector<Node> tree{};
    int n{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
        make(1, 0, n);
    }

    void make(int v, int l, int r) {
        tree[v].cnt = r - l;
        if (l + 1 == r) return;
        make(v << 1, l, (l + r) >> 1);
        make((v << 1) + 1, (l + r) >> 1, r);
    }

    void updsum(int v, int l, int r, int &lq, int &rq, int &val) {
        if (lq <= l && r <= rq) {
            tree[v].checkadd(val, l, r);
            return;
        }
        push(v, l, r);
        int mid = (l + r) >> 1;
        if (mid > lq) updsum(v << 1, l, mid, lq, rq, val);
        if (rq > mid) updsum((v << 1) + 1, mid, r, lq, rq, val);
        tree[v].combine(tree[v << 1], tree[(v << 1) + 1]);
    }

    void updmax(int v, int l, int r, int &lq, int &rq, int &val) {
        if (tree[v].mn >= val) return;
        if (lq <= l && r <= rq && tree[v].s_mn > val) {
            tree[v].check(val);
            return;
        }
        push(v, l, r);
        int mid = (l + r) >> 1;
        if (mid > lq) updmax(v << 1, l, mid, lq, rq, val);
        if (rq > mid) updmax((v << 1) + 1, mid, r, lq, rq, val);
        tree[v].combine(tree[v << 1], tree[(v << 1) + 1]);
    }

    ll get(int v, int l, int r, int &lq, int &rq) {
        if (lq <= l && r <= rq) {
            return tree[v].sum;
        }
        push(v, l, r);
        int mid = (l + r) >> 1;
        ll res = 0;
        if (mid > lq) res += get(v << 1, l, mid, lq, rq);
        if (rq > mid) res += get((v << 1) + 1, mid, r, lq, rq);
        return res;
    }

    ll get(int lq, int rq) {
        auto res = get(1, 0, n, lq, rq);
        return res;
    }

    void updmax(int lq, int rq, int val) {
        updmax(1, 0, n, lq, rq, val);
    }

    void updsum(int lq, int rq, int val) {
        updsum(1, 0, n, lq, rq, val);
    }
};

void solve() {
    segment_tree st;
    int n;
    cin >> n;
    st.build(n);
    int start = -1;
    string s;
    cin >> s;
    ll ans = 0;
    range(i, n) {
        if (s[i] == '1') {
            if (!i || s[i - 1] == '0') start = i;
            st.updsum(start, i + 1, 1);
            int kek = i - start + 1;
            st.updmax(0, start, kek);
        }
        ans += st.get(0, n);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}