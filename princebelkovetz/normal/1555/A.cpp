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

const int mod = 1e9 + 7, N = 52;

struct segtree {
    vector <int> tree;
    int n;

    segtree(int n) : n(n), tree(2 * n, mod) {}

    void set(int i, int x) {
        i += n;
        tree[i] = min(x, tree[i]);
        for (i /= 2; i > 0; i /= 2) tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    int get(int l, int r) {
        int res = mod;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = min(tree[l++], res);
            if (r & 1) res = min(tree[--r], res);
        }
        return res;
    }
};


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int ans2 = mod * mod; 
        for (int i = 0; i < 50; ++i) {
            for (int j = 0; j < 50; ++j) {
                ans2 = min(ans2, 25 * i + 20 * j + (max(n - i * 10 - j * 8 + 5, 0ll)) / 6 * 15);
            }
        }
        cout << ans2 << '\n';
    }
    return 0;
}