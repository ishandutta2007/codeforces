#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

struct dsu {
    vector<set<int>> st;
    vector<int> par;
    dsu(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        st.resize(n);
        for (int i = 0; i < n; i++) {
            st[i].insert(i);
        }
    }
    int find_set(int v) {
        if (v == par[v]) return v;
        else return par[v] = find_set(par[v]);
    }
    vector<pair<int,int>> union_set(int a, int b) {
        vector<pair<int,int>> ret;
        a = find_set(a);
        b = find_set(b);
        if (a == b) {
            return ret;
        } else {
            if (st[a].size() < st[b].size()) {
                swap(a, b);
            }
            for (auto to : st[b]) {
                auto it = st[a].upper_bound(to);
                if (it != st[a].end()) {
                    ret.pb({to, *it});
                }
                if (it != st[a].begin()) {
                    ret.pb({*prev(it), to});
                }
            }
            for (auto to : st[b]) {
                st[a].insert(to);
            }
            st[b].clear();
            par[b] = a;
            return ret;
        }
    }
};

struct Fenwick {
    vector<int> t;
    Fenwick(int n) {
        t.resize(n);
    }
    void upd(int i, int d) {
        for (; i < t.size(); i = (i | (i + 1))) {
            t[i] = max(t[i], d);
        }
    }
    int get(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans = max(ans, t[r]);
        }
        return ans;
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
        int n, m, q;
        cin >> n >> m >> q;
        dsu g(n);
        vector<int> ans(q);
        vector<pair<int,int>> u(m);
        vector<vector<pair<int,int>>> add(n), qu(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            auto mas = g.union_set(a, b);
            for (auto to : mas) {
                add[to.first].pb({to.second, i + 1});
            }
        }
        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            qu[l].pb({r, i});
        }
        Fenwick f(n);
        for (int i = n - 1; i >= 0; i--) {
            for (auto to : add[i]) {
                f.upd(to.first, to.second);
            }
            for (auto to : qu[i]) {
                ans[to.second] = f.get(to.first);
            }
        }
        for (int i = 0; i < q; i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}