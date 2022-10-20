#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n, q;
int a[N];
int t[N];

struct Query {
    int x, y, id;
} queries[N];

int res[N];

struct ST {
    int sum[N << 2];

    void init(int node, int l, int r) {
        sum[node] = 0;
        if (l < r) {
            int m = l + r >> 1;
            init(node << 1, l, m);
            init(node << 1 | 1, m + 1, r);
        }
    }

    int getT(int node, int l, int r, int delta) {
        if (l == r) return l;
        int m = l + r >> 1;
        if (sum[node << 1 | 1] >= delta) return getT(node << 1 | 1, m + 1, r, delta);
        else return getT(node << 1, l, m, delta - sum[node << 1 | 1]);
    }

    void update(int node, int l, int r, int x) {
        if (x > r || x < l) return;
        if (l == r) {
            sum[node]++;
            return;
        }
        int m = l + r >> 1;
        update(node << 1, l, m, x);
        update(node << 1 | 1, m + 1, r, x);
        sum[node] = sum[node << 1] + sum[node << 1 | 1];
    }

    int get(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return 0;
        if (x <= l && r <= y) return sum[node];
        int m = l + r >> 1;
        int p1 = get(node << 1, l, m, x, y);
        int p2 = get(node << 1 | 1, m + 1, r, x, y);
        return p1 + p2;
    }
} st;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;   
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = i - a[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> queries[i].x >> queries[i].y;
        queries[i].id = i;
    }
    sort(queries + 1, queries + q + 1, [&](Query &u, Query &v) {
        return u.y > v.y;
    });

    int canErase = 0;

    // build t
    st.init(1, 0, n);
    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) {
            t[i] = 0;
        } else if (a[i] == 0) {
            t[i] = i;
            canErase++;
        } else {
            if (canErase < a[i]) {
                t[i] = 0;
            } else {
                t[i] = st.getT(1, 0, n, a[i]);
                t[i] = min(t[i], i);
                canErase++;
            }
        }
        st.update(1, 0, n, t[i]);
    }
    st.init(1, 0, n);
    int cur = 1;
    for (int i = 1; i <= q; i++) {
        // cout << "# " << queries[i].x << ' ' << queries[i].y << endl;
        while (cur <= n && cur <= n - queries[i].y) {
            // cout << "update " << t[cur] << endl;
            st.update(1, 0, n, t[cur]);
            cur++;
        }
        res[queries[i].id] = st.get(1, 0, n, queries[i].x + 1, n);
    }
    for (int i = 1; i <= q; i++) {
        cout << res[i] << '\n';
    }
    return 0;
}