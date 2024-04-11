#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n;
int a[N];
int nxt[4][N];
int lastPos[N];

struct IT {
    int minVal[N << 2];
    int numMinVal[N << 2];
    int lazy[N << 2];

    void pull(int node, int l, int r) {
        if (minVal[node << 1] == minVal[node << 1 | 1]) {
            minVal[node] = minVal[node << 1];
            numMinVal[node] = numMinVal[node << 1] + numMinVal[node << 1 | 1];
        } else {
            int id = minVal[node << 1] < minVal[node << 1 | 1] ? node << 1 : node << 1 | 1;
            minVal[node] = minVal[id];
            numMinVal[node] = numMinVal[id];
        }
    }

    void push(int node, int l, int r, int m) {
        for (int it = 0; it < 2; it++) {
            minVal[node << 1 | it] += lazy[node];
            lazy[node << 1 | it] += lazy[node];
        }
        lazy[node] = 0;
    }

    void init(int node, int l, int r) {
        lazy[node] = 0;
        if (l == r) {
            minVal[node] = 0;
            numMinVal[node] = 1;
            return;
        }
        int m = l + r >> 1;
        init(node << 1, l, m);
        init(node << 1 | 1, m + 1, r);
        pull(node, l, r);
    }

    void update(int node, int l, int r, int x, int y, int delta) {
        if (x > r || y < l) return;
        if (x <= l && r <= y) {
            minVal[node] += delta;
            lazy[node] += delta;
            return;
        }
        int m = l + r >> 1;
        push(node, l, r, m);
        update(node << 1, l, m, x, y, delta);
        update(node << 1 | 1, m + 1, r, x, y, delta);
        pull(node, l, r);
    }

    int get(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return 0;
        if (x <= l && r <= y) {
            if (minVal[node] == 0) return numMinVal[node];
            return 0;
        }
        int m = l + r >> 1;
        push(node, l, r, m);
        int p1 = get(node << 1, l, m, x, y);
        int p2 = get(node << 1 | 1, m + 1, r, x, y);
        return p1 + p2;
    }
} t;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    fill(lastPos + 1, lastPos + n + 1, n + 1);
    for (int i = 0; i < 4; i++) nxt[i][n + 1] = n + 1;
    for (int i = n; i; i--) {
        nxt[0][i] = lastPos[a[i]];
        for (int j = 1; j < 4; j++) {
            nxt[j][i] = nxt[j - 1][lastPos[a[i]]];
        }
        lastPos[a[i]] = i;
    }
    t.init(1, 1, n);
    long long res = 0;
    for (int i = n; i; i--) {
        t.update(1, 1, n,         i, nxt[0][i] - 1, +1);
        t.update(1, 1, n, nxt[1][i], nxt[2][i] - 1, -1);
        t.update(1, 1, n, nxt[2][i], nxt[3][i] - 1, +1);
        res += t.get(1, 1, n, i, n);
    }   
    cout << res << endl;
    return 0;
}