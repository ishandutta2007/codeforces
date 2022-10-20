#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int INF = 1e9;

int n, q;
char s[N];
int a[N];

struct IT {
    struct Node {
        int maxVal, minVal, maxLeft, maxRight, res, lazy;
        Node (int maxVal = -INF, int minVal = INF, int maxLeft = -INF, int maxRight = -INF, int res = -INF, int lazy = 0) :
            maxVal(maxVal), minVal(minVal), maxLeft(maxLeft), maxRight(maxRight), res(res), lazy(lazy) {}

        void set(int u) {
            maxVal = minVal = u;
            res = lazy = 0;
            maxLeft = maxRight = -u;
        }

        void update(const Node &u, const Node &v) {
            maxVal = max(u.maxVal, v.maxVal);
            minVal = min(u.minVal, v.minVal);
            maxLeft = max(u.maxLeft, v.maxLeft);
            maxLeft = max(maxLeft, u.maxVal - 2 * v.minVal);
            maxRight = max(u.maxRight, v.maxRight);
            maxRight = max(maxRight, v.maxVal - 2 * u.minVal);
            res = max(u.res, v.res);
            res = max(res, u.maxLeft + v.maxVal);
            res = max(res, v.maxRight + u.maxVal);
            assert(lazy == 0);
        }

        void change(int delta) {
            maxVal += delta, minVal += delta, lazy += delta;
            maxLeft -= delta, maxRight -= delta;
        }

        void debug() {
            cerr << "maxVal: " << maxVal << endl;
            cerr << "minVal: " << minVal << endl;
            cerr << "maxLeft: " << maxLeft << endl;
            cerr << "maxRight: " << maxRight << endl;
            cerr << "res: " << res << endl;
        }
    } t[N << 2];

    void init(int node, int l, int r) {
        if (l == r) {
            t[node].set(a[l]);
        } else {
            int m = l + r >> 1;
            init(node << 1, l, m);
            init(node << 1 | 1, m + 1, r);
            t[node].update(t[node << 1], t[node << 1 | 1]);
        }
    }

    void down(int node) {
        if (t[node].lazy == 0) return;
        t[node << 1].change(t[node].lazy);
        t[node << 1 | 1].change(t[node].lazy);
        t[node].lazy = 0;
    }   

    void update(int node, int l, int r, int x, int y, int delta) {
        if (x > r || y < l) return;
        if (x <= l && r <= y) {
            t[node].change(delta);
            return;
        }
        down(node);
        int m = l + r >> 1;
        update(node << 1, l, m, x, y, delta);
        update(node << 1 | 1, m + 1, r, x, y, delta);
        t[node].update(t[node << 1], t[node << 1 | 1]);
    }

    int getMaxRoot() {
        return t[1].res;
    }
} it;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    cin >> (s + 1);
    a[0] = 0;
    for (int i = 1; i <= 2 * (n - 1); i++) {
        a[i] = a[i - 1] + (s[i] == '(' ? 1 : -1);
    }
    it.init(1, 0, 2 * (n - 1));
    cout << it.getMaxRoot() << '\n';
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        if (s[u] != s[v]) {
            int delta = (s[u] == '(' ? -2 : 2);
            it.update(1, 0, 2 * (n - 1), u, v - 1, delta);
            swap(s[u], s[v]);
        }
        cout << it.getMaxRoot() << '\n';
    }
    return 0;
}