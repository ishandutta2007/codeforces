#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
pair<int, int> last[N];

struct IT {
    int t[N << 2];
    void init(int node, int l, int r) {
        t[node] = 0;
        if (l == r) return;
        int m = l + r >> 1;
        init(node << 1, l, m);
        init(node << 1 | 1, m + 1, r);
    }
    void add(int node, int l, int r, int id, int val) {
        if (id > r || id < l) return;
        if (l == r) {
            t[node] = val;
            return;
        }
        int m = l + r >> 1;
        add(node << 1, l, m, id, val);
        add(node << 1 | 1, m + 1, r, id, val);
        t[node] = max(t[node << 1], t[node << 1 | 1]);
    }
    int get(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return 0;
        if (x <= l && r <= y) return t[node];
        int m = l + r >> 1;
        int p1 = get(node << 1, l, m, x, y);
        int p2 = get(node << 1 | 1, m + 1, r, x, y);
        return max(p1, p2);
    }
} it;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        last[i] = {0, u};
    }
    int q;
    cin >> q;
    it.init(1, 1, q);
    for (int i = 1; i <= q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int p, x;
            cin >> p >> x;
            last[p] = {i, x};
        } else {
            int x;
            cin >> x;
            it.add(1, 1, q, i, x);
        }
    }
    for (int i = 1; i <= n; i++) {
        int res = it.get(1, 1, q, last[i].first + 1, q);
        res = max(res, last[i].second);
        cout << res << ' ';
    }
    cout << endl;
    return 0;
}