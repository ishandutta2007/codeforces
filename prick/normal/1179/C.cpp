#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
const int tsize = 1 << 20;

struct Node {
    int minval;
    int add;
};

Node tree[2 * tsize];

void push(int v) {
    if (v >= tsize) return;
    tree[v * 2].minval += tree[v].add;
    tree[v * 2].add += tree[v].add;
    tree[v * 2 + 1].minval += tree[v].add;
    tree[v * 2 + 1].add += tree[v].add;
    tree[v].add = 0;
}

void update(int val, int l, int r, int v, int tl, int tr) {
    if (tr < l || r < tl) {
        return;
    }
    push(v);
    if (l <= tl && tr <= r) {
        tree[v].minval += val;
        tree[v].add += val;
        return;
    }
    int tm = (tl + tr) / 2;
    update(val, l, r, v * 2, tl, tm);
    update(val, l, r, v * 2 + 1, tm + 1, tr);
    tree[v].minval = min(tree[v * 2].minval, tree[v * 2 + 1].minval);
}

int get(int v, int tl, int tr) {
    if (tl == tr) {
        return tl;
    }
    push(v);
    int tm = (tl + tr) / 2;
    if (tree[v * 2 + 1].minval < 0) {
        return get(v * 2 + 1, tm + 1, tr);
    } else {
        return get(v * 2, tl, tm);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, m, q;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        update(-1, 1, a[i], 1, 0, tsize - 1);
    }
    vector<int> b(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        update(1, 1, b[i], 1, 0, tsize - 1);
    }
    cin >> q;
    for (int it = 0; it < q; ++it) {
        int tp, i, x;
        cin >> tp >> i >> x;
        if (tp == 1) {
            update(1, 1, a[i], 1, 0, tsize - 1);
            a[i] = x;
            update(-1, 1, a[i], 1, 0, tsize - 1);
        } else {
            update(-1, 1, b[i], 1, 0, tsize - 1);
            b[i] = x;
            update(1, 1, b[i], 1, 0, tsize - 1);
        }
        if (tree[1].minval >= 0) {
            cout << -1 << '\n';
        } else {
            cout << get(1, 0, tsize - 1) << '\n';
        }
    }
}