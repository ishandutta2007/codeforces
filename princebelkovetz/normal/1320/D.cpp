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
#include <bitset>
#include <functional>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int mod = 1e9 + 7, p = 239, N = 2e5 + 5;

int pw[N], rev[N];
int binpow(int a, int b) {
    if (!b) return 1ll;
    if (b & 1) return a * binpow(a, b - 1) % mod;
    int t = binpow(a, b / 2);
    return t * t % mod;
}
struct Node {
    int lc, rc, len, h;
    vector <int> cnt;
    Node() {
        cnt.resize(2, 0);
        lc = rc = 0;
        len = 0;
        h = 0;
    }
    Node(int x) {
        cnt.resize(2, 0);
        lc = rc = x;
        len = 1;
        cnt[x] = 1;
        h = x;
    }
    Node operator+(const Node& node) const {
        Node res;
        res.cnt[0] = cnt[0] + node.cnt[0];
        res.cnt[1] = cnt[1] + node.cnt[1];
        if (!node.len) {
            res.len = len, res.h = h;
            res.lc = lc, res.rc = rc;
            return res;
        }
        if (!len) {
            res.len = node.len, res.h = node.h;
            res.lc = node.lc, res.rc = node.rc;
            return res;
        }
        if (rc and node.lc) {
            res.len = len + node.len - 2;
            res.h = h - pw[len - 1] + pw[len - 1] * (node.h - 1) % mod * rev[1] % mod;
            if (lc and len > 1) res.lc = 1;
            if (node.rc and node.len > 1) res.rc = 1;
        }
        else {
            res.len = len + node.len;
            res.h = h + pw[len] * node.h % mod;
            res.lc = lc;
            res.rc = node.rc;
        }
        res.h = (res.h + mod) % mod;
        return res;
    }
    bool operator==(const Node& node) const {
        return cnt[0] == node.cnt[0] 
            and cnt[1] == node.cnt[1] 
            and h == node.h;
    }
};

struct SegTree {
    int size;
    vector <Node> tree;
    SegTree(string& s) {
        int n = s.size();
        size = 1;
        while (size < n) size <<= 1;
        tree.resize(2 * size - 1);
        build(0, 0, size, s);
    }
    void build(int v, int lx, int rx, string& s) {
        if (lx + 1 == rx) {
            tree[v] = lx < s.size() ? Node(s[lx] - '0') : Node();
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * v + 1, lx, m, s);
        build(2 * v + 2, m, rx, s);
        tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
    }
    Node get(int v, int lx, int rx, int l, int r) {
        if (l <= lx and rx <= r) return tree[v];
        if (rx <= l or r <= lx) return Node();
        int m = (lx + rx) / 2;
            auto ls = get(2 * v + 1, lx, m, l, r);
        auto rs = get(2 * v + 2, m, rx, l, r);
        auto ok = ls + rs;
        return ok;
    }
    Node get(int l, int r) {
        return get(0, 0, size, l, r);
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);

    pw[0] = rev[0] = 1;
    for (int i = 1; i < N; ++i) {
        pw[i] = pw[i - 1] * p % mod;
        rev[i] = binpow(pw[i], mod - 2);
    }

    int n; cin >> n;
    string s; cin >> s;
    SegTree ST(s);
    int q; cin >> q;
    while (q--) {
        int l1, l2, len; cin >> l1 >> l2 >> len;
        l1--, l2--;
        auto g1 = ST.get(l1, l1 + len), g2 = ST.get(l2, l2 + len);
        cout << (g1 == g2 ? "Yes" : "No") << '\n';
    }
    return 0;
}