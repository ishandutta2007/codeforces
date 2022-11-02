#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 2e5 + 10, INF = 1e9;
vector<int> divs[N];
vector<array<int, 3>> nw[N];
vector<pair<int,int>> segs[N];
int r[N], mn[N];
map<int,int> mp[N];
vector<bool> used(N);

struct SegTree {
    vector<ll> t, add, len;
    void build(int v, int l, int r) {
        len[v] = r - l + 1;
        if (l == r) return;
        int m = (l + r) / 2;
        build(2 * v, l, m), build(2 * v + 1, m + 1, r);
    }
    SegTree(int n) {
        t.resize(4 * n);
        add.resize(4 * n);
        len.resize(4 * n);
        build(1, 0, n - 1);
    }
    void inc(int v, ll val) {
        t[v] += val * len[v];
        add[v] += val;
    }
    void push(int v) {
        inc(v * 2, add[v]);
        inc(v * 2 + 1, add[v]);
        add[v] = 0;
    }
    void update(int v, int tl, int tr, int l, int r, ll val) {
        if (l > r) return;
        if (tl == l && tr == r) {
            inc(v, val);
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm), val), update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
    ll get(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (tl == l && tr == r) {
            return t[v];
        }
        push(v);
        int tm = (tl + tr) / 2;
        return (get(2 * v, tl, tm, l, min(r, tm)) + get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            if (i > j / i) {
                divs[j].pb(i);
            }
        }
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) mn[i] = n;
    vector<int> p(n + 1), pos(n + 1);
    vector<ll> ans(m);
    vector<vector<pair<int,int>>> need(n);
    vector<pair<int,int>> u(m);
    deque<int> q{n};
    p[n] = INF;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> u[i].first >> u[i].second;
        u[i].first--, u[i].second--;
        need[u[i].first].pb({i, u[i].second});
    }
    int now = 0;
    SegTree cnt(n), val(n), add(n);
    for (int i = n - 1; i >= 0; i--) {
        while (p[q.back()] < p[i]) {
            int ind = p[q.back()];
            used[ind] = 1;
            if (mn[ind] <= r[ind]) {
                cnt.update(1, 0, n - 1, mn[ind], r[ind], -1);
                for (auto to : nw[ind]) {
                    add.update(1, 0, n - 1, to[0], to[1], -to[2]);
                    val.update(1, 0, n - 1, to[0], to[1], now - to[2]);
                }
            }
            q.pop_back();
        }
        r[p[i]] = q.back() - 1;
        mn[p[i]] = r[p[i]] + 1;
        for (auto to : divs[p[i]]) {
            int a = pos[to], b = pos[p[i] / to];
            if (max({a, b, i}) < q.back()) {
                segs[min({a, b, i})].pb({p[i], max({a, b, i})});
            }
        }
        for (auto to : segs[i]) {
            if (used[to.first]) continue;
            if (to.second < mn[to.first]) {
                nw[to.first].pb({to.second, mn[to.first] - 1, now});
                cnt.update(1, 0, n - 1, to.second, mn[to.first] - 1, 1);
                add.update(1, 0, n - 1, to.second, mn[to.first] - 1, now);
            }
            mn[to.first] = min(mn[to.first], to.second);
        }
        q.pb(i);
        now++;
        for (auto to : need[i]) {
            ans[to.first] = cnt.get(1, 0, n - 1, i, to.second) * now - add.get(1, 0, n - 1, i, to.second) + val.get(1, 0, n - 1, i, to.second);
        }
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}