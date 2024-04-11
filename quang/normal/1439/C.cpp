#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, q;
int a[N];

struct Node {
    int minVal;
    long long sum;
    int lazy;

    Node() {
        minVal = sum = lazy = -1;
    }

    template<typename T>
    void apply(int l, int r, const T &val) {
        lazy = minVal = val;
        sum = 1ll * (r - l + 1) * val;
    }

    void pull(const Node &u, const Node &v) {
        minVal = min(u.minVal, v.minVal);
        sum = u.sum + v.sum;
    }

    void push(int l, int r, Node &u, Node &v) {
        if (lazy == -1) return;
        int m = l + r >> 1;
        u.minVal = v.minVal = lazy;
        u.sum = 1ll * lazy * (m - l + 1);
        v.sum = 1ll * lazy * (r - m);
        u.lazy = v.lazy = lazy;
        lazy = -1;
    }
};

struct SegmentTree {
    void init(int node, int l, int r) {
        if (l == r) {
            t[node].apply(l, r, a[l]);
            return;
        }
        int m = l + r >> 1;
        init(node << 1, l, m);
        init(node << 1 | 1, m + 1, r);
        t[node].pull(t[node << 1], t[node << 1 | 1]);
    }

    /*------------------------------------------------------------------*/
    int n;
    vector<Node> t;
    
    SegmentTree(int n) : n(n) {
        t.assign(n << 2 | 1, {});
        init(1, 1, n);
    }

    template<typename T>
    void update(int node, int l, int r, int x, int y, const T &val) {
        if (x > r || y < l) return;
        if (x <= l && r <= y) {
            t[node].apply(l, r, val);
            return;
        }
        int m = l + r >> 1;
        t[node].push(l, r, t[node << 1], t[node << 1 | 1]);
        update(node << 1, l, m, x, y, val);
        update(node << 1 | 1, m + 1, r, x, y, val);
        t[node].pull(t[node << 1], t[node << 1 | 1]);
    }

    int find(int node, int l, int r, int x, int y, int val) {
        if (x > r || y < l) return n + 1;
        if (t[node].minVal > val) return n + 1;
        if (x <= l && r <= y) {
            if (l == r) return l;
        }
        int m = l + r >> 1;
        t[node].push(l, r, t[node << 1], t[node << 1 | 1]);
        int p1 = find(node << 1, l, m, x, y, val);
        if (p1 != n + 1) return p1;
        return find(node << 1 | 1, m + 1, r, x, y, val);
    }

    pair<int, int> go(int node, int l, int r, int x, int y, int &val) {
        if (x > r || y < l) return {0, 0};
        if (x <= l && r <= y) {
            if (t[node].sum <= val) {
                val -= t[node].sum;
                return {r, 0};
            }
            if (l == r) {
                return {0, 1};
            }
        }   
        t[node].push(l, r, t[node << 1], t[node << 1 | 1]);
        int m = l + r >> 1;
        pair<int, int> p1 = go(node << 1, l, m, x, y, val);
        if (p1.second) return p1;
        pair<int, int> p2 = go(node << 1 | 1, m + 1, r, x, y, val);
        return {max(p1.first, p2.first), p2.second};
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    SegmentTree st(n);
    st.init(1, 1, n);
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            int id = st.find(1, 1, n, 1, x, y);
            if (id <= x) st.update(1, 1, n, id, x, y);
        } else {
            int res = 0;
            int last = x;
            while (1) {
                int id = st.find(1, 1, n, last, n, y);
                if (id == n + 1) break;
                pair<int, int> now = st.go(1, 1, n, id, n, y);
                res += now.first - id + 1;
                // cout << y << ' ' << last << ' ' << id << ' ' << now.first << endl;
                last = now.first + 1;
            }
            cout << res << '\n';
        }
    }
    return 0;
}