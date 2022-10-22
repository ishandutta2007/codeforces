#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int used[MAXN], deled[MAXN];
int pr[MAXN];
int p[MAXN], sz[MAXN];
set<array<int, 2>> st[MAXN];

int get(int v) {
    if (p[v] == v) {
        return v;
    }
    return get(p[v]);
}

int get_val(int i) {
    int res = pr[i];
    if (!st[i].empty()) {
        auto it = st[i].end();
        it--;
        res = max(res, (*it)[0]);
    }
    return res;
}

int join(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) {
        return -1;
    }
    if (sz[u] < sz[v]) {
        swap(u, v);
    }
    sz[u] += sz[v];
    st[u].insert({get_val(v), v});
    p[v] = u;
    return v;
}

void del(int i) {
    i = deled[i];
    if (i == -1) {
        return;
    }
    int u = p[i];
    p[i] = i;
    int sv = get_val(u);
    st[u].erase({get_val(i), i});
    while (u != p[u]) {
        int v = p[u];
        int sv1 = get_val(v);
        st[v].erase({sv, u});
        st[v].insert({get_val(u), u});
        sv = sv1;
        u = v;
    }
}

int go(int v) {
    if (pr[v] == get_val(v)) {
        return v;
    }
    auto it = st[v].end();
    it--;
    return go((*it)[1]);
}

void get_ans(int i) {
    i = get(i);
    i = go(i);
    cout << pr[i] << '\n';
    int sv = get_val(i);
    pr[i] = 0;
    while (i != p[i]) {
        int v = p[i];
        int sv1 = get_val(v);
        st[v].erase({sv, i});
        st[v].insert({get_val(i), i});
        sv = sv1;
        i = p[i];
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        cin >> pr[i];
    }
    vector<array<int, 2>> ed(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        ed[i] = {u, v};
    }
    vector<array<int, 2>> qu(q);
    for (int i = 0; i < q; ++i) {
        cin >> qu[i][0] >> qu[i][1];
        qu[i][1]--;
        if (qu[i][0] == 2) {
            used[qu[i][1]] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        p[i] = i; sz[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        if (!used[i]) {
            deled[i] = join(ed[i][0], ed[i][1]);
        }
    }
    for (int i = q - 1; i >= 0; --i) {
        if (qu[i][0] == 2) {
            int j = qu[i][1];
            deled[j] = join(ed[j][0], ed[j][1]);
        }
    }
    for (int i = 0; i < q; ++i) {
        int t = qu[i][0], v = qu[i][1];
        if (t == 1) {
            get_ans(v);
        } else {
            del(v);
        }
    }
    return 0;
}