#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int INF = 8e18;

struct st {
    vector<int> t;
    st(int n) {
        t.resize(4 * n, INF);
    }
    void update(int v, int l, int r, int pos, int val) {
        if (l == r) {
            t[v] = val;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) {
            update(2 * v, l, m, pos, val);
        } else {
            update(2 * v + 1, m + 1, r, pos, val);
        }
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (l > r) return INF;
        if (tl == l && tr == r) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return min(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> x(n), w(n), res(m, INF);
    vector<pair<int,int>> u(m);
    vector<vector<int>> qu(n), qu2(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> w[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> u[i].first >> u[i].second;
        u[i].first--, u[i].second--;
        qu[u[i].second].pb(i);
        qu2[u[i].first].pb(i);
    }
    deque<int> q;
    st t(n), t2(n);
    for (int i = 0; i < n; i++) {
        while (q.size() > 0 && w[q.back()] >= w[i]) {
            t.update(1, 0, n - 1, q.back(), abs(x[q.back()] - x[i]) * (w[i] + w[q.back()]));
            q.pop_back();
        }
        q.pb(i);
        for (auto to : qu[i]) {
            res[to] = min(res[to], t.get(1, 0, n - 1, u[to].first, i));
        }
    }
    q.clear();
    for (int i = n - 1; i >= 0; i--) {
        while (q.size() > 0 && w[q.back()] >= w[i]) {
            t2.update(1, 0, n - 1, q.back(), abs(x[q.back()] - x[i]) * (w[i] + w[q.back()]));
            q.pop_back();
        }
        q.pb(i);
        for (auto to : qu2[i]) {
            res[to] = min(res[to], t2.get(1, 0, n - 1, i, u[to].second));
        }
    }
    for (int i = 0; i < m; i++) {
        cout << res[i] << endl;
    }
    return 0;
}