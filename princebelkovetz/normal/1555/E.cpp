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

const int MOD = 1e9 + 7, N = 52;

struct segtree {
    vector <int> tree, mod;
    int size;
    segtree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.resize(2 * size - 1);
        mod.resize(2 * size - 1);
    }
    void push(int v, int lx, int rx) {
        if (lx + 1 != rx) {
            tree[2 * v + 1] += mod[v];
            tree[2 * v + 2] += mod[v];
            mod[2 * v + 1] += mod[v];
            mod[2 * v + 2] += mod[v];
        }
        mod[v] = 0;
    }
    void add(int v, int lx, int rx, int l, int r, int x) {
        if (l <= lx and rx <= r) {
            mod[v] += x, tree[v] += x;
            return;
        }
        if (rx <= l or r <= lx) return;
        push(v, lx, rx);
        int m = (lx + rx) / 2;
        add(2 * v + 1, lx, m, l, r, x);
        add(2 * v + 2, m, rx, l, r, x);
        tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
    }
    void add(int l, int r, int x) {
        add(0, 0, size, l, r, x);
    }
    int get(int v, int lx, int rx, int l, int r) {
        if (l <= lx and rx <= r) return tree[v];
        if (rx <= l or r <= lx) return MOD;
        push(v, lx, rx);
        int m = (lx + rx) / 2;
        return min(get(2 * v + 1, lx, m, l, r),
            get(2 * v + 2, m, rx, l, r));
    }
    int get(int l, int r) {
        return get(0, 0, size, l, r);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int n, m; cin >> n >> m;
    vector <vector <int>> a(n, vector <int>(3));
    for (auto& x : a) cin >> x[1] >> x[2] >> x[0];
    sort(a.begin(), a.end());

    int ans = MOD;
    int r = 0, l = 0;
    segtree ST(m + 1);
    while (ST.get(1, m) == 0) {
        ST.add(a[r][1], a[r][2], 1);
        r++;
    }
    r--;
    while (true) {
        while (ST.get(a[l][1], a[l][2]) > 1) {
            ST.add(a[l][1], a[l][2], -1);
            l++;
        }
        ans = min(ans, a[r][0] - a[l][0]);
        ++r;
        if (r == n) break;
        ST.add(a[r][1], a[r][2], 1);
    }
    cout << ans << '\n';
    return 0;
}