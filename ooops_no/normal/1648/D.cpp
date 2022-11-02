#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int INF = 4e18, N = 5e5 + 10;

struct node {
    int l, r, ans;
};

node t[4 * N];

node get_node(node a, node b) {
    node c;
    c.l = max(a.l, b.l);
    c.r = max(a.r, b.r);
    c.ans = max({a.ans, b.ans, b.r + a.l});
    return c;
}

void update(int v, int l, int r, int pos, pair<int,int> p) {
    if (l == r) {
        t[v] = {p.first, p.second, p.second + p.first};
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) {
        update(2 * v, l, m, pos, p);
    } else {
        update(2 * v + 1, m + 1, r, pos, p);
    }
    t[v] = get_node(t[v * 2], t[v * 2 + 1]);
}

node get(int v, int tl, int tr, int l, int r) {
    if (l > r) return {-INF, -INF, -INF};
    if (tl == l && tr == r) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return get_node(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

struct st {
    vector<int> t;
    st(int n) {
        t.resize(4 * n, -INF);
    }
    void update(int v, int l, int r, int pos, int val) {
        if (l == r) {
            t[v] = max(t[v], val);
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) {
            update(2 * v, l, m, pos, val);
        } else {
            update(2 * v + 1, m + 1, r, pos, val);
        }
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (l > r) return -INF;
        if (tl == l && tr == r) return t[v];
        int tm = (tl + tr) / 2;
        return max(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(3, vector<int>(n)), add(n), del(n);
    vector<int> sf(n), pr(n), l(q), r(q), k(q);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i] >> k[i];
        l[i]--, r[i]--;
        add[r[i]].pb(i);
        del[l[i]].pb(i);
    }
    for (int i = 0; i < n; i++) {
        pr[i] = (i > 0 ? pr[i - 1] : 0) + a[1][i];
    }
    for (int i = n - 1; i >= 0; i--) {
        sf[i] = (i + 1 < n ? sf[i + 1] : 0) + a[2][i];
    }
    int sum = 0, ans = -INF;
    st dp(n), dif(n);
    for (int i = 0; i < n; i++) {
        sum += a[0][i];
        dif.update(1, 0, n - 1, i, sum + a[1][i] - pr[i]);
        int val = -INF;
        for (auto to : add[i]) {
            int res = max(dp.get(1, 0, n - 1, max(0ll, l[to] - 1), i - 1), dif.get(1, 0, n - 1, l[to], i)) + pr[i] - k[to];
            val = max(val, res);
        }
        dp.update(1, 0, n - 1, i, val - pr[i]);
    }
    for (int i = 0; i < n; i++) {
        update(1, 0, n - 1, i, {dp.get(1, 0, n - 1, i, i), pr[i] + sf[i]});
    }
    for (int i = 0; i < n; i++) {
        for (auto j : del[i]) {
            ans = max(ans, get(1, 0, n - 1, max(0ll, l[j] - 1), r[j]).ans - k[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        update(1, 0, n - 1, i, {dif.get(1, 0, n - 1, i, i), pr[i] + sf[i]});
    }
    for (int i = 0; i < n; i++) {
        for (auto j : del[i]) {
            ans = max(ans, get(1, 0, n - 1, l[j], r[j]).ans - k[j]);
        }
    }
    cout << ans << endl;
    return 0;
}