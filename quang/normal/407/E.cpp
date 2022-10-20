#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 200010;
const int INF = 5e9;

int n, k, d;
int a[N];
int b[N];

struct IT {
    int lazy[N << 2];
    int minVal[N << 2];

    void down(int node) {
        if (lazy[node] == 0) return;
        minVal[node << 1] += lazy[node];
        minVal[node << 1 | 1] += lazy[node];
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
        lazy[node] = 0;
    }

    void set(int node, int l, int r, int id, int val) {
        if (id > r || id < l) return;
        if (l == r) {
            lazy[node] = val;
            minVal[node] = val;
            return;
        }
        down(node);
        int m = l + r >> 1;
        set(node << 1, l, m, id, val);
        set(node << 1 | 1, m + 1, r, id, val);
        minVal[node] = min(minVal[node << 1], minVal[node << 1 | 1]);
    }

    void update(int node, int l, int r, int x, int y, int delta) {
        if (x > r || y < l) return;
        if (x <= l && r <= y) {
            lazy[node] += delta;
            minVal[node] += delta;
            return;
        }
        down(node);
        int m = l + r >> 1;
        update(node << 1, l, m, x, y, delta);
        update(node << 1 | 1, m + 1, r, x, y, delta);
        minVal[node] = min(minVal[node << 1], minVal[node << 1 | 1]);
    }

    int find(int node, int l, int r, int u) {
        if (l == r) {
            if (minVal[node] <= u) return l;
            return -1;
        }
        down(node);
        int m = l + r >> 1;
        if (minVal[node << 1 | 1] <= u) return find(node << 1 | 1, m + 1, r, u);
        else if (minVal[node << 1] <= u) return find(node << 1, l, m, u);
        return -1;
    }

    int get(int node, int l, int r, int id) {
        if (l == r) return minVal[node];
        down(node);
        int m = l + r >> 1;
        if (id <= m) return get(node << 1, l, m, id);
        return get(node << 1 | 1, m + 1, r, id);
    }
} it;

void solve(pair<int, int> &res, int l, int r) {
    map<int, int> last;
    vector<tuple<int, int, int>> stMax, stMin;
    int bound = r + 1;
    for (int i = r; i >= l; i--) {
        it.set(1, 1, n, i, -i);
        if (last.count(a[i])) {
            int newBound = last[a[i]];
            while (bound > newBound) {
                bound--;
                it.set(1, 1, n, bound, INF);
            }
        }
        last[a[i]] = i;
        // cerr << "inside " << i << ' ' << bound << endl;
        int cur = i;
        while (!stMax.empty() && get<0>(stMax.back()) <= a[i]) {
            int delta = a[i] - get<0>(stMax.back());
            int low = get<1>(stMax.back());
            int high = get<2>(stMax.back());
            high = min(high, bound - 1);
            it.update(1, 1, n, low, high, delta);
            cur = get<2>(stMax.back());
            stMax.pop_back();
        }
        stMax.push_back({a[i], i, cur});

        cur = i;
        while (!stMin.empty() && get<0>(stMin.back()) >= a[i]) {
            int delta = get<0>(stMin.back()) - a[i];
            int low = get<1>(stMin.back());
            int high = get<2>(stMin.back());
            high = min(high, bound - 1);
            it.update(1, 1, n, low, high, delta);
            cur = get<2>(stMin.back());
            stMin.pop_back();
        }
        stMin.push_back({a[i], i, cur});

        int ans = it.find(1, 1, n, k - i);
//         cerr << ans << endl;
//         cerr << "max "<< endl;
//         for (auto u : stMax) cerr << get<0>(u) << ' ' << get<1>(u) << ' ' << get<2>(u) << endl;
// cerr << "min "<< endl;
//             for (auto u : stMin) cerr << get<0>(u) << ' ' << get<1>(u) << ' ' << get<2>(u) << endl;
//             if (i == 6) cout << it.get(1, 1, n, 8) << ' ' << k - l << endl;
        assert(ans != -1);
        if (res.second - res.first <= ans - i) res = {i, ans};
    }

    while (bound > l) {
        bound--;
        it.set(1, 1, n, bound, INF);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int minVal = *min_element(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) a[i] -= minVal;
    if (d == 0) {
        pair<int, int> res = {1, 0};
        for (int l = 1, r = 1; l <= n; l = r) {
            while (r <= n && a[l] == a[r]) r++;
            pair<int, int> ans = {l, r - 1};
            if (res.second - res.first < ans.second - ans.first) res = ans;
        }
        cout << res.first << ' ' << res.second << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        b[i] = a[i] % d;
        a[i] /= d;
    }
    pair<int, int> res = {n + 1, n + 1};
    for (int i = 1; i <= n; i++) it.set(1, 1, n, i, INF);
    for (int r = n, l = n; r >= 1; r = l) {
        while (l >= 1 && b[l] == b[r]) l--;
        solve(res, l + 1, r);
    }
    cout << res.first << ' ' << res.second << endl;
    return 0;
}