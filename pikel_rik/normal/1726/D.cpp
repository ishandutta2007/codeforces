#include <bits/stdc++.h>
using namespace std;

struct union_find {
    int n, c;
    std::vector<int> p, r;

    union_find() : n(), c() {}

    union_find(int n) : n(n), c(n), p(n), r(n, 1) {
        std::iota(p.begin(), p.end(), 0);
    }

    int count() const noexcept {
        return c;
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    bool merge(int x, int y) {
        int l1 = find(x);
        int l2 = find(y);
        if (l1 == l2) {
            return false;
        }
        if (r[l1] >= r[l2]) {
            r[l1] += r[l2];
            p[l2] = l1;
        } else {
            p[l1] = l2;
            r[l2] += r[l1];
        }
        c -= 1;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        struct edge { int u, v; };

        vector<edge> e(m);
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            auto &[u, v] = e[i];
            cin >> u >> v;
            g[--u].push_back(i);
            g[--v].push_back(i);
        }

        union_find uf(n);

        vector<bool> tree(m);
        for (int i = 0; i < m; i++) {
            tree[i] = uf.merge(e[i].u, e[i].v);
        }

        union_find another_uf(n);

        bool okay = true;
        for (int i = 0; i < m; i++) {
            if (!tree[i]) {
                okay &= another_uf.merge(e[i].u, e[i].v);
            }
        }

        if (okay) {
            for (int i = 0; i < m; i++) {
                cout << tree[i];
            }
            cout << '\n';
            continue;
        }

        vector<int> p(n, -2);
        auto dfs = [&](int u, auto &&self) -> void {
            for (int i : g[u]) {
                int v = e[i].u ^ e[i].v ^ u;
                if (tree[i] && p[v] == -2) {
                    p[v] = i;
                    self(v, self);
                }
            }
        };

        int j = find(tree.begin(), tree.end(), false) - tree.begin();
        int u = e[j].u, v = e[j].v;

        p[u] = -1;
        dfs(u, dfs);

        tree[j] = true;
        tree[p[v]] = false;

        for (int i = 0; i < m; i++) {
            cout << tree[i];
        }
        cout << '\n';
    }
    return 0;
}