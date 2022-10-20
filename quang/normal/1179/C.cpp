#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
const int M = 1000010;

struct IT {
    int minVal[M << 2], sum[M << 2];

    IT() {
        memset(minVal, 0, sizeof minVal);
        memset(sum, 0, sizeof sum);
    }

    void add(int node, int l, int r, int x, int delta) {
        if (x > r || x < l) return;
        if (l == r) {
            sum[node] += delta;
            minVal[node] = sum[node];
            return;
        }
        int m = l + r >> 1;
        add(node << 1, l, m, x, delta);
        add(node << 1 | 1, m + 1, r, x, delta);
        sum[node] = sum[node << 1] + sum[node << 1 | 1];
        minVal[node] = min(minVal[node << 1 | 1], minVal[node << 1] + sum[node << 1 | 1]);
    }

    int get(int node, int l, int r, int now) {
        if (minVal[node] + now >= 0) return -1;
        if (l == r) {
            return l;
        }
        int m = l + r >> 1;
        if (minVal[node << 1 | 1] + now < 0) return get(node << 1 | 1, m + 1, r, now);
        return get(node << 1, l, m, now + sum[node << 1 | 1]);
    }
} it;

int n, m;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        it.add(1, 1, M, a[i], -1);
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        it.add(1, 1, M, b[i], 1);
    }
    int q;
    cin >> q;
    while (q--) {
        int id, x, op;
        cin >> op >> id >> x;
        if (op == 1) {
            it.add(1, 1, M, a[id], 1);
            a[id] = x;
            it.add(1, 1, M, a[id], -1);
        } else {
            it.add(1, 1, M, b[id], -1);
            b[id] = x;
            it.add(1, 1, M, b[id], 1);
        }
        cout << it.get(1, 1, M, 0) << '\n';
    }
    return 0;
}