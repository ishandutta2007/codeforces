#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

struct dsu {
    vector<int> par;
    dsu(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    int find_set(int v) {
        if (par[v] == v) return v;
        else return par[v] = find_set(par[v]);
    }
    bool union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) return 0;
        par[a] = b;
        return 1;
    }
};

struct edge {
    int a, b, c;
};

struct event {
    int c, t, a, b;
};

vector<int> get(vector<int> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a;
    vector<edge> q;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a.pb(w);
        u--, v--;
        q.pb({u, v, w});
    }
    a = get(a);
    int sz = a.size();
    a.pb(a[sz - 1] + 1);
    a.pb(0);
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            a.pb((q[i].c + q[j].c + 2) / 2);
        }
    }
    a = get(a);
    sz = a.size();
    vector<int> ans(sz), bal(sz);
    for (int j = 0; j < sz; j++) {
        dsu g(n);
        int val = a[j];
        vector<event> p;
        for (int i = 0; i < m; i++) {
            if (q[i].c >= val) {
                p.pb({q[i].c - val, -1, q[i].a, q[i].b});
            } else {
                p.pb({val - q[i].c, 1, q[i].a, q[i].b});
            }
        }
        sort(p.begin(), p.end(), [&] (event a, event b) {return make_pair(a.c, a.t) < make_pair(b.c, b.t);});
        for (auto t : p) {
            if (g.union_set(t.a, t.b)) {
                ans[j] += t.c;
                bal[j] += t.t;
            }
        }
    }
    int p, k, A, B, C;
    cin >> p >> k >> A >> B >> C;
    vector<int> e(k);
    for (int i = 0; i < k; i++) {
        if (i < p) cin >> e[i];
        else e[i] = (e[i - 1] * A + B) % C;
    }
    int res = 0;
    for (int i = 0; i < k; i++) {
        int l = -1, r = sz;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (a[mid] <= e[i]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        res ^= ans[l] + bal[l] * (e[i] - a[l]);
    }
    cout << res << endl;
    return 0;
}