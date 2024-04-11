#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

const long long INF = (1ll << 60);

int n;
long long s[N];
int res[N];

struct IT {
    long long t[N << 2];
    long long lazy[N << 2];

    void init(int node, int l, int r) {
        lazy[node] = 0;
        if (l == r) {
            t[node] = 1ll * l * (l - 1) / 2;
        } else {
            int m = l + r >> 1;
            init(node << 1, l, m);
            init(node << 1 | 1, m + 1, r);
            t[node] = min(t[node << 1], t[node << 1 | 1]);
        }
    }

    void down(int node) {
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
        t[node << 1] -= lazy[node];
        t[node << 1 | 1] -= lazy[node];
        lazy[node] = 0;
    }

    int get(int node, int l, int r, long long now) {
        if (l == r) {
            return l;
        }
        int m = l + r >> 1;
        down(node);
        if (t[node << 1 | 1] <= now) return get(node << 1 | 1, m + 1, r, now);
        return get(node << 1, l, m, now);
    }

    void update(int node, int l, int r, int x, int y, long long val) {
        if (x > r || y < l) return;
        if (x <= l && r <= y) {
            t[node] -= val;
            lazy[node] += val;
            return;
        }
        int m = l + r >> 1;
        down(node);
        update(node << 1, l, m, x, y, val);
        update(node << 1 | 1, m + 1, r, x, y, val);
        t[node] = min(t[node << 1], t[node << 1 | 1]);
    }

    void change(int node, int l, int r, int x, long long val) {
        if (x > r || x < l) return;
        if (l == r) {
            t[node] = val;
            lazy[node] = 0;
            return;
        }
        int m = l + r >> 1;
        down(node);
        change(node << 1, l, m, x, val);
        change(node << 1 | 1, m + 1, r, x, val);
        t[node] = min(t[node << 1], t[node << 1 | 1]);
    }
} it;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    it.init(1, 1, n);
    for (int i = n; i; i--) {
        res[i] = it.get(1, 1, n, s[i]);
        it.update(1, 1, n, res[i] + 1, n, res[i]);
        it.change(1, 1, n, res[i], INF);
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}