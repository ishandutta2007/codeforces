#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct IT {
    int t[2][N << 2];

    void init(int node, int l, int r) {
        t[0][node] = t[1][node] = 3;
        if (l < r) {
            int m = l + r >> 1;
            init(node << 1, l, m);
            init(node << 1 | 1, m + 1, r);
        }
    }

    void update(int node, int l, int r, int x, int val) {
        if (x > r || x < l) return;
        if (l == r) {
            t[0][node] ^= (1 << val);
            t[1][node] ^= (1 << val);
            return;
        }
        int m = l + r >> 1;
        update(node << 1, l, m, x, val);
        update(node << 1 | 1, m + 1, r, x, val);
        if (t[1][node << 1] & t[0][node << 1 | 1]) {
            t[0][node] = t[0][node << 1];
            t[1][node] = t[1][node << 1 | 1];
        } else {
            t[0][node] = t[1][node] = 0;
        }
    }

    bool get() {
        return (t[0][1] & 1) && (t[1][1] & 2);
    }
} t;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    t.init(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int r, c;
        cin >> r >> c;
        r--;
        t.update(1, 1, n, c, r);
        if (t.get()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}