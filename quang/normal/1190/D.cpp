#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
pair<int, int> a[N];

struct IT {
    int t[N << 2];

    IT() {
        memset(t, 0, sizeof t);
    }

    void add(int node, int l, int r, int x) {
        if (x > r || x < l) return;
        if (l == r) {
            t[node] = 1;
            return;
        }
        int m = l + r >> 1;
        add(node << 1, l, m, x);
        add(node << 1 | 1, m + 1, r, x);
        t[node] = t[node << 1] + t[node << 1 | 1];
    }

    int get(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return 0;
        if (x <= l && r <= y) {
            return t[node];
        }
        int m = l + r >> 1;
        int p1 = get(node << 1, l, m, x, y);
        int p2 = get(node << 1 | 1, m + 1, r, x, y);
        return p1 + p2;
    }
} it;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> val;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        val.push_back(a[i].first);
    }
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    for (int i = 1; i <= n; i++) {
        a[i].first = lower_bound(val.begin(), val.end(), a[i].first) - val.begin() + 1;
    }
    sort(a + 1, a + n + 1, [](pair<int, int> &u, pair<int, int> &v) {
        if (u.second != v.second) return u.second > v.second;
        return u.first < v.first;
    });
    long long res = 0;
    for (int l = 1, r = 1; l <= n; l = r) {
        while (r <= n && a[r].second == a[l].second) r++;

        for (int i = l; i < r; i++) {
            //left side
            int foo = it.get(1, 1, n, 1, a[i].first - 1);

            //right side
            int suff = (i == r - 1 ? n : a[i + 1].first - 1);
            int bar = it.get(1, 1, n, a[i].first + 1, suff);
            res += 1ll * (foo + 1) * (bar + 1);

            it.add(1, 1, n, a[i].first);
        }
    }
    cout << res << endl;
    return 0;
}