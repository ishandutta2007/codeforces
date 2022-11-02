#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld double
#define ll long long

mt19937 rnd(51);

const int N = 1e5 + 10;
vector<bool> used(2 * N);

struct SegTree {
    vector<vector<int>> t;
    void build(int n) {
        t.resize(4 * n);
    }
    void update(int v, int l, int r, int pos, int val) {
        t[v].pb(val);
        if (l == r) {
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) {
            update(2 * v, l, m, pos, val);
        } else {
            update(2 * v + 1, m + 1, r, pos, val);
        }
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (l > r) return -1;
        if (tl == l && tr == r) {
            while (t[v].size() > 0 && used[t[v].back()]) {
                t[v].pop_back();
            }
            if (t[v].size() == 0) return -1;
            else return t[v].back();
        }
        int tm = (tl + tr) / 2;
        return max(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};

struct SegTree2 {
    vector<vector<pair<int,int>>> t;
    void build(int n) {
        t.resize(4 * n);
    }
    void update(int v, int l, int r, int pos, pair<int,int> val) {
        t[v].pb(val);
        if (l == r) {
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) {
            update(2 * v, l, m, pos, val);
        } else {
            update(2 * v + 1, m + 1, r, pos, val);
        }
    }
    pair<int,int> get(int v, int tl, int tr, int l, int r) {
        if (l > r) return {-1, -1};
        if (tl == l && tr == r) {
            while (t[v].size() > 0 && used[t[v].back().second]) {
                t[v].pop_back();
            }
            if (t[v].size() == 0) return {-1, -1};
            else return t[v].back();
        }
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) used[i] = 0;
        vector<int> c(n), l(n), r(n), u, ord(n);
        iota(ord.begin(), ord.end(), 0);
        for (int i = 0; i < n; i++) {
            cin >> c[i] >> l[i] >> r[i];
            u.pb(l[i]);
            u.pb(r[i]);
        }
        sort(u.begin(), u.end());
        u.erase(unique(u.begin(), u.end()), u.end());
        int m = u.size();
        vector<SegTree> tr(2);
        vector<SegTree2> g(2);
        tr[0].build(m);
        tr[1].build(m);
        g[0].build(m);
        g[1].build(m);
        for (int i = 0; i < n; i++) {
            l[i] = lower_bound(u.begin(), u.end(), l[i]) - u.begin();
            r[i] = lower_bound(u.begin(), u.end(), r[i]) - u.begin();
            tr[c[i]].update(1, 0, m - 1, l[i], i);
            tr[c[i]].update(1, 0, m - 1, r[i], i);
        }
        int cnt = 0;
        sort(ord.begin(), ord.end(), [&](int i, int j){return r[i] < r[j];});
        for (auto i : ord) {
            g[c[i]].update(1, 0, m - 1, l[i], {r[i], i});
        }
        for (auto i : ord) {
            if (!used[i]) {
                cnt++;
                used[i] = 1;
                deque<int> q{i};
                while (q.size() > 0) {
                    int j = q.front();
                    q.pop_front();
                    while (1) {
                        int val = tr[c[j] ^ 1].get(1, 0, m - 1, l[j], r[j]);
                        if (val == -1) break;
                        used[val] = 1;
                        q.pb(val);
                    }
                    while (1) {
                        pair<int,int> val = g[c[j] ^ 1].get(1, 0, m - 1, 0, l[j]);
                        if (val.first > r[j]) {
                            used[val.second] = 1;
                            q.pb(val.second);
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}