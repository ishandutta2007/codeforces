#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 998244353, p = 239, N = 4e5 + 5;

struct segtree {
    int size;
    vector <int> tree;

    segtree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.resize(2 * size - 1, -1);
    }

    void upd(int v, int lx, int rx, int i, int x) {
        if (lx + 1 == rx) {
            tree[v] = x;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            upd(2 * v + 1, lx, m, i, x);
        else
            upd(2 * v + 2, m, rx, i, x);
        tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
    }

    void upd(int i, int x) {
        upd(0, 0, size, i, x);
    }

    int way(int v, int lx, int rx, int k) {
        if (lx + 1 == rx)
            return lx;
        int m = (lx + rx) / 2;
        if (tree[2 * v + 1] <= k)
            return way(2 * v + 1, lx, m, k);
        return way(2 * v + 2, m, rx, k);
    }

    int way (int k) {
        return way(0, 0, size, k);
    }

};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);

    int n; cin >> n;
    vector <int> a(n), last(n + 1, -1);

    for (auto& x : a) cin >> x, --x;

    segtree ST(n + 3);

    vector <int> mex(n + 3);

    for (int i = 0; i < n; ++i) {
        if (a[i]) mex[0] = 1;
        if (last[a[i]] != i - 1) {
            mex[ST.way(last[a[i]])] = 1;
        }
        last[a[i]] = i;
        ST.upd(a[i], i);
    }
    for (int i = 0; i <= n; ++i) {
        if (last[i] != n - 1) {
            mex[ST.way(last[i])] = 1;
        }
    }
    for (int i = 0; i < n + 3; ++i) {
        if (!mex[i]) {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    return 0;
}