#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e5 + 100, INF = 1e18;
int x[MAXN];

bool cmp(array<int, 2> a, array<int, 2> b) {
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}

int tree[2][4 * MAXN];

void pull(int i, int v) {
    tree[i][v] = min(tree[i][v * 2], tree[i][v * 2 + 1]);
}

void update(int i, int v, int vl, int vr, int ind, int val) {
    if (ind >= vr || ind < vl) return;
    if (vr - vl == 1) {
        tree[i][v] = val;
        return;
    }
    int vm = (vl + vr) / 2;
    update(i, v * 2, vl, vm, ind, val);
    update(i, v * 2 + 1, vm, vr, ind, val);
    pull(i, v);
}

int get(int i, int v, int vl, int vr, int l, int r) {
    if (l >= vr || r <= vl) {
        return INF;
    }
    if (l <= vl && r >= vr) {
        return tree[i][v];
    }
    int vm = (vl + vr) / 2;
    int res1 = get(i, v * 2, vl, vm, l, r);
    int res2 = get(i, v * 2 + 1, vm, vr, l, r);
    return min(res1, res2);
}

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        x[0] = -4e10;
        for (int i = 0; i < n; ++i) {
            cin >> x[i + 1];
        }
        n++;
        sort(x, x + n);
        vector<array<int, 2>> seg;
        for (int i = 0; i < m; ++i) {
            int l, r;
            cin >> l >> r;
            int j = upper_bound(x, x + n, r) - x;
            int k = lower_bound(x, x + n, l) - x;
            if (j == k) {
                seg.push_back({l, r});
            }
        }
        m = seg.size();
        sort(seg.begin(), seg.end(), cmp);
        vector<array<int, 2>> seg1;
        for (auto elem : seg) {
            while (!seg1.empty() && elem[1] <= seg1.back()[1]) {
                seg1.pop_back();
            }
            seg1.push_back(elem);
        }
        seg = seg1;
        m = seg.size();
        if (seg.empty()) {
            cout << 0 << "\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            seg.push_back({x[i], x[i]});
            m++;
        }
        sort(seg.begin(), seg.end());
        vector<int> rs(m);
        for (int i = 0; i < m; ++i) {
            rs[i] = seg[i][1];
        }
        fill(tree[0], tree[0] + 4 * m, INF);
        fill(tree[1], tree[1] + 4 * m, INF);
        update(0, 1, 0, m + 1, 0, -rs[0]);
        update(1, 1, 0, m + 1, 0, -rs[0] * 2);
        vector<int> dp(m + 1, 0);
        for (int i = 0; i < m; ++i) {
            int l = seg[i][0], r = seg[i][1];
            /// cout << l << ", " << r << endl;
            int k = upper_bound(x, x + n, r) - x;
            k--;
            array<int, 2> el = {x[k], x[k]};
            int rgh = lower_bound(seg.begin(), seg.end(), el) - seg.begin();
            rgh--;
            rgh--;
            int lft;
            if (k == 0) {
                lft = -1;
            } else {
                el = {x[k - 1], x[k - 1]};
                lft = upper_bound(seg.begin(), seg.end(), el) - seg.begin();
                lft--;
            }
            int t = upper_bound(rs.begin(), rs.end(), 2 * x[k] - l) - rs.begin();
            t--;
            t--;
            int val = INF;
            if (t >= lft) {
                int res = get(0, 1, 0, m + 1, lft + 1, min(t, rgh) + 2);
                res += 2 * l - x[k];
                val = min(val, res);
            }
            if (rgh >= t) {
                int res = get(1, 1, 0, m + 1, max(t, lft) + 1, rgh + 2);
                res += l + x[k];
                val = min(val, res);
            }
            rgh++;
            val = min(val, dp[rgh + 1] + l - x[k]);
            dp[i + 1] = val;
            /// cout << val << endl;
            if (i < m - 1) {
                update(0, 1, 0, m + 1, i + 1, val - rs[i + 1]);
                update(1, 1, 0, m + 1, i + 1, val - 2 * rs[i + 1]);
            } else {
                cout << val << "\n";
            }
        }
    }
    return 0;
}