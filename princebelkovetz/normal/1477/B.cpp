#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
using namespace std;
#define ld long double
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7, N = 5e3 + 2;
struct segtree {
    int size;
    vector <int> tree, mod;
    void push(int v, int lx, int rx) {
        if (lx + 1 == rx or !mod[v]) return;
        if (mod[v] == 1) {
            mod[2 * v + 1] = 1, mod[2 * v + 2] = 1;
            tree[2 * v + 1] = (rx - lx) / 2;
            tree[2 * v + 2] = (rx - lx) / 2;
        }
        if (mod[v] == 2) {
            mod[2 * v + 1] = 2, mod[2 * v + 2] = 2;
            tree[2 * v + 1] = 0;
            tree[2 * v + 2] = 0;
        }
        mod[v] = 0;
    }
    void build(int v, int lx, int rx, vector <int>& a) {
        if (lx + 1 == rx) {
            if (lx < a.size()) tree[v] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * v + 1, lx, m, a);
        build(2 * v + 2, m, rx, a);
        tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
    }
    void init(vector <int>& a) {
        int n = a.size();
        size = 1;
        while (size < n) {
            size *= 2;
        }
        tree.resize(2 * size - 1);
        mod.resize(2 * size - 1);
        build(0, 0, size, a);
    }
    int sum(int v, int lx, int rx, int l, int r) {
        if (l <= lx and rx <= r) {
            return tree[v];
        }
        if (rx <= l or r <= lx) return 0;
        push(v, lx, rx);
        int m = (lx + rx) / 2;
        int s1 = sum(2 * v + 1, lx, m, l, r);
        int s2 = sum(2 * v + 2, m, rx, l, r);
        return s1 + s2;
    }
    int sum(int l, int r) {
        return sum(0, 0, size, l, r);
    }
    void set(int v, int lx, int rx, int l, int r, int x) {
        if (l <= lx and rx <= r) {
            mod[v] = 2 - x;
            if (x == 0) tree[v] = 0;
            else tree[v] = (rx - lx);
            return;
        }
        if (rx <= l or r <= lx) return;
        push(v, lx, rx);
        int m = (lx + rx) / 2;
        set(2 * v + 1, lx, m, l, r, x);
        set(2 * v + 2, m, rx, l, r, x);
        tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
    }
    void set(int l, int r, int x) {
        set(0, 0, size, l, r, x);
    }
};
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt --> 0) {
        int n, q; cin >> n >> q;
        string s, t; cin >> s >> t;
        vector <int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            a[i] = (s[i] - '0'), b[i] = (t[i] - '0');
        segtree st;
        st.init(b);
        vector <vector <int>> qs(q, vector <int>(2));
        for (auto& x : qs) cin >> x[0] >> x[1];
        reverse(qs.begin(), qs.end());
        bool c = true;
        for (auto& x : qs) {
            int l = x[0] - 1, r = x[1];
            int sum = st.sum(l, r);
            int all = r - l;
            int lb, rb;
            if (all & 1) lb = all / 2, rb = lb + 1;
            else lb = all / 2 - 1, rb = lb + 2;
            if (sum <= lb) st.set(l, r, 0);
            else if (sum >= rb) st.set(l, r, 1);
            else {
                c = false;
                break;
            }
        }
        vector <int> ok(n);
        for (int i = 0; i < n; ++i) {
            ok[i] = st.sum(i, i + 1);
        }
        if (ok != a) c = false;
        cout << (c ? "YES" : "NO") << '\n';
    }
    return 0;
}