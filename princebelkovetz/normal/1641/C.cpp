#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <string>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>
#include <functional>
#include <set>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int mod = 1e9 + 7, N = 10;

struct SegTree {
    int n;
    vector <int> tree;
    SegTree(int n) : n(n) {
        tree.resize(2 * n, mod);
    }
    void upd(int i, int x) {
        i += n;
        tree[i] = min(x, tree[i]);
        for (i /= 2; i > 0; i /= 2)
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
    int get(int l, int r) {
        int res = mod;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = min(res, tree[l++]);
            if (r & 1) res = min(res, tree[--r]);
        }
        return res;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n, q; cin >> n >> q;
    set <int> bad;
    for (int i = 0; i <= n + 1; ++i)
        bad.insert(i);
    SegTree ST(n + 1);
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int l, r, x; cin >> l >> r >> x;
            if (x == 0) {
                auto it = bad.lower_bound(l);
                while (*it <= r) {
                    bad.erase(it);
                    it = bad.lower_bound(l);
                }
            }
            else ST.upd(l, r);

        }
        else {
            int id; cin >> id;
            if (bad.find(id) == bad.end()) {
                cout << "NO\n";
            }
            else {
                int rx = *bad.upper_bound(id);
                int lx = *(--bad.lower_bound(id));
                bool had = false;
                cout << (ST.get(lx + 1, id + 1) < rx ? "YES" : "N/A") << '\n';
            }
        }
    }


    return 0;
}