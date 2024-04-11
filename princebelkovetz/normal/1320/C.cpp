#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
using namespace std;
const int root = 212, mod = 1e9 + 7, N = 1e6 + 7;

struct SegTree {
    int size;
    vector <int> tree, alt;
    SegTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.resize(2 * size - 1);
        alt.resize(2 * size - 1);
    }
    void push(int v) {
        tree[2 * v + 1] += alt[v];
        tree[2 * v + 2] += alt[v];
        alt[2 * v + 1] += alt[v];
        alt[2 * v + 2] += alt[v];
        alt[v] = 0;
    }
    int get(int v, int lx, int rx, int l, int r) {
        if (l <= lx and rx <= r) return tree[v];
        if (rx <= l or r <= lx) return -mod * mod;
        int m = (lx + rx) / 2;
        push(v);
        return max(
            get(2 * v + 1, lx, m, l, r),
            get(2 * v + 2, m, rx, l, r)
        );
    }
    int get(int l, int r) {
        return get(0, 0, size, l, r);
    }
    void upd(int v, int lx, int rx, int l, int r, int x) {
        if (l <= lx and rx <= r) {
            tree[v] += x, alt[v] += x;
            return;
        }
        if (rx <= l or r <= lx) return;
        int m = (lx + rx) / 2;
        push(v);
        upd(2 * v + 1, lx, m, l, r, x);
        upd(2 * v + 2, m, rx, l, r, x);
        tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
    }
    void upd(int l, int r, int x) {
        upd(0, 0, size, l, r, x);
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    int n, m, p; cin >> n >> m >> p;
    vector <pair <int, int>> a(n), b(m), na, nb;
    vector <vector <int>> c(p, vector <int>(3));
    for (auto& x : a) cin >> x.first >> x.second;
    for (auto& x : b) cin >> x.first >> x.second;
    for (auto& x : c) cin >> x[0] >> x[1] >> x[2];
    sort(a.begin(), a.end());
    for (auto& x : a) {
        while (!na.empty() and na.back().second >= x.second)
            na.pop_back();
        if (na.empty() or na.back().first != x.first)
            na.push_back(x);
    }
    sort(b.begin(), b.end());
    for (auto& x : b) {
        while (!nb.empty() and nb.back().second >= x.second)
            nb.pop_back();
        if (nb.empty() or nb.back().first != x.first)
            nb.push_back(x);
    }
    sort(c.begin(), c.end());
    SegTree ST(N);
    int lst = -1;
    for (auto& x : nb) {
        ST.upd(lst + 1, x.first + 1, -x.second);
        lst = x.first;
    }
    ST.upd(lst + 1, N, -mod * mod);
    int was = 0, ans = -mod * mod;
    for (auto& x : na) {
        while (was < c.size() and c[was][0] < x.first)
            ST.upd(c[was][1] + 1, N, c[was][2]), was++;
        ans = max(ans, ST.get(0, N) - x.second);
    }
    cout << ans << '\n';
    return 0;
}