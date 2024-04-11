#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <cassert>
#include <bitset>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
const int N = 1e4 + 3;
int n;
bitset <N> res;
struct segtree {
    int size;
    vector <vector <int>> a;
    vector <bitset<N>> rs;
    segtree(int n = 0) {
        size = 1;
        while (size < n) size *= 2;
        a.resize(size * 2 - 1);
        rs.resize(size * 2 - 1);
    }
    void add(int v, int lx, int rx, int x, int l, int r) {
        if (l <= lx and rx <= r) {
            a[v].push_back(x);
            return;
        } 
        if (rx <= l or r <= lx)
            return;
        int m = (lx + rx) / 2;
        add(2 * v + 1, lx, m, x, l, r);
        add(2 * v + 2, m, rx, x, l, r);
    }
    void add(int x, int l, int r) {
        add(0, 0, size, x, l, r);
    }
    void way2(int v, int lx, int rx, bitset<N> &cur) {
        for (auto& x : a[v]) {
            cur |= cur << x;
        }
        rs.push_back(cur);
        if (lx + 1 == rx) {
            res |= cur;
        }
        else {
            int m = (lx + rx) / 2;
            way2(2 * v + 1, lx, m, cur);
            cur = rs.back();
            way2(2 * v + 2, m, rx, cur);
        }
        rs.pop_back();
    }
    void way() {
        bitset <N> cur;
        cur[0] = 1;
        way2(0, 0, size, cur);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int q; cin >> n >> q;
    segtree ST(n);
    while (q --> 0) {
        int l, r, x;
        cin >> l >> r >> x;
        ST.add(x, l - 1, r);
    }
    ST.way();
    vector <int> ans;
    for (int i = 1; i <= n; ++i)
        if (res[i])
            ans.push_back(i);
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}