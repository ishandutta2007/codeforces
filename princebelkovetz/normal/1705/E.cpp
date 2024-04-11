#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <cassert>
#include <numeric>
#include <climits>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 2e5 + 12;

struct SegTree {
    int size;
    vector <int> tree, alt;
    SegTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.resize(2 * size - 1);
        alt.resize(2 * size - 1, -1);
    }
    void push(int v, int lx, int rx) {
        if (alt[v] == -1) return;
        alt[2 * v + 1] = alt[2 * v + 2] = alt[v];
        tree[2 * v + 1] = tree[2 * v + 2] = tree[v] / 2;
        alt[v] = -1;
    }
    void upd(int v, int lx, int rx, int l, int r, int x) {
        if (l <= lx and rx <= r) {
            alt[v] = x;
            tree[v] = x * (rx - lx);
            return;
        }
        if (rx <= l or r <= lx) return;
        push(v, lx, rx);
        int m = (lx + rx) / 2;
        upd(2 * v + 1, lx, m, l, r, x);
        upd(2 * v + 2, m, rx, l, r, x);
        tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
    }
    void upd(int l, int r, int x) {
        upd(0, 0, size, l, r, x);
    }
    int get(int v, int lx, int rx, int l, int r) {
        if (l <= lx and rx <= r) return tree[v];
        if (rx <= l or r <= lx) return 0;
        push(v, lx, rx);
        int m = (lx + rx) / 2;
        return get(2 * v + 1, lx, m, l, r)
            + get(2 * v + 2, m, rx, l, r);
    }
    int get(int l, int r) {
        return get(0, 0, size, l, r);
    }
    int getLastBit(int v, int lx, int rx) {
        if (lx + 1 == rx) return lx;
        push(v, lx, rx);
        int m = (lx + rx) / 2;
        if (tree[2 * v + 2] > 0) 
            return getLastBit(2 * v + 2, m, rx);
        return getLastBit(2 * v + 1, lx, m);
    }
    int getLastBit() {
        return getLastBit(0, 0, size);
    }
    int getFirst(int v, int lx, int rx, int l, int x) {
        if (rx <= l) return -1;
        if ((1 - x) * (rx - lx) == tree[v]) return -1;
        if (lx + 1 == rx) return lx;
        push(v, lx, rx);
        int m = (lx + rx) / 2;
        int res = getFirst(2 * v + 1, lx, m, l, x);
        if (res != -1) return res;
        return getFirst(2 * v + 2, m, rx, l, x);
    }
    int getFirst(int l, int x) {
        return getFirst(0, 0, size, l, x);
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n, q; cin >> n >> q;
    SegTree tree(N);

    auto add = [&](int i) {
        int id = tree.getFirst(i, 0);
        tree.upd(i, id, 0);
        tree.upd(id, id + 1, 1);
    };

    auto sub = [&](int i) {
        int id = tree.getFirst(i, 1);
        tree.upd(i, id, 1);
        tree.upd(id, id + 1, 0);
    };

    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        add(x);
        a[i] = x;
    }

    while (q--) {
        int k, x; cin >> k >> x;
        --k;
        sub(a[k]);
        a[k] = x;
        add(a[k]);
        cout << tree.getLastBit() << '\n';
    }

    return 0;
}