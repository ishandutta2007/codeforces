#include <bits/stdc++.h>

using namespace std;

struct JiDriverSegmentTree {
    static const int T = (1 << 22);
    static const int INF = 1e9 + 7;

    struct Node {
        int max;
        long long sum;

        Node():
            max(INF),
            sum(INF) {}
    } tree[T];

    void updateFromChildren(int v) {
        tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
        tree[v].max = max(tree[2 * v].max, tree[2 * v + 1].max);
    }

    void build(int v, int l, int r, const vector<int>& inputArray) {
        if (l + 1 == r) {
            tree[v].max = tree[v].sum = inputArray[l];
        } else {
            int mid = (r + l) / 2;
            build(2 * v, l, mid, inputArray);
            build(2 * v + 1, mid, r, inputArray);
            updateFromChildren(v);
        }
    }

    void build(const vector<int>& inputArray) {
        build(1, 0, inputArray.size(), inputArray);
    }

    void updateModEq(int v, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql || tree[v].max < val) {
            return;
        }
        if (l + 1 == r) {
            tree[v].max %= val;
            tree[v].sum = tree[v].max;
            return;
        }
        int mid = (r + l) / 2;
        updateModEq(2 * v, l, mid, ql, qr, val);
        updateModEq(2 * v + 1, mid, r, ql, qr, val);
        updateFromChildren(v);
    }

    void updateEq(int v, int l, int r, int qi, int val) {
        if (l + 1 == r) {
            tree[v].max = tree[v].sum = val;
            return;
        }
        int mid = (l + r) / 2;
        if (qi < mid) {
            updateEq(2 * v, l, mid, qi, val);
        } else {
            updateEq(2 * v + 1, mid, r, qi, val);
        }
        updateFromChildren(v);
    }

    long long findSum(int v, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return tree[v].sum;
        }
        int mid = (r + l) / 2;
        return findSum(2 * v, l, mid, ql, qr) + findSum(2 * v + 1, mid, r, ql, qr);
    }
} segTree;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> inputArray(n);
    for (int &val : inputArray) {
        cin >> val;
    }
    segTree.build(inputArray);
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int ql, qr;
            cin >> ql >> qr;
            ql--;
            cout << segTree.findSum(1, 0, n, ql, qr) << '\n';
        } else if (type == 2) {
            int ql, qr, x;
            cin >> ql >> qr >> x;
            ql--;
            segTree.updateModEq(1, 0, n, ql, qr, x);
        } else if (type == 3) {
            int qi, y;
            cin >> qi >> y;
            qi--;
            segTree.updateEq(1, 0, n, qi, y);
        }
    }
    return 0;
}