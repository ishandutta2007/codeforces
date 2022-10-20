#include <bits/stdc++.h>

using namespace std;

const int N = 150010;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/*
    change null_type to int if we want to use map instead
    find_by_order(k) returns the k-th element (0-indexed)
    order_of_key(k) returns numbers of item being strictly smaller than k
*/

// 1-indexed
template<typename T>
struct BIT {
    int n;
    vector<T> t;

    BIT(int n = -1) : n(n) {
        t.assign(n + 1, 0);
    }

    void add(int x, T v) {
        while (x <= n) {
            t[x] += v;
            x += x & -x;
        }
    }

    T get(int x) {
        T res = 0;
        while (x) {
            res += t[x];
            x -= x & -x;
        }
        return res;
    }

    T get(int l, int r) {
        return get(r) - (l ? get(l - 1) : 0);
    }
};

int n, m, k;

template<typename T>
struct Tree {
    int n;
    int curPos;
    vector<vector<pair<int, T>>> adj;
    vector<int> posIn;
    vector<int> posOut;
    vector<int> sz;
    vector<int> lv;
    vector<T> dist;
    vector<vector<int>> par;
    vector<int> order;

    vector<vector<pair<int, int>>> ls;
    BIT<int> t;

    Tree(int n = -1) : n(n) {
        curPos = 0;
        adj.assign(n + 1, vector<pair<int, T>>());
        posIn.assign(n + 1, 0);
        posOut.assign(n + 1, 0);
        sz.assign(n + 1, 0);
        lv.assign(n + 1, 0);
        dist.assign(n + 1, 0);
        if (n > 0) par.assign((int)log2(n) + 1, vector<int>(n + 1, 0));

        ls.assign(n + 1, vector<pair<int, int>>());
        t = BIT<int>(n);
        order.assign(1, 0);
    }

    void addEdge(int u, int v, T cost = 1) {
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }

    void dfs(int u, int p) {
        order.push_back(u);
        posIn[u] = ++curPos;
        sz[u] = 1;
        lv[u] = lv[p] + 1;
        par[0][u] = p;
        for (int i = 1; i < par.size(); i++) par[i][u] = par[i - 1][par[i - 1][u]];

        for (auto e : adj[u]) {
            int v = e.first;
            T cost = e.second;
            if (v == p) continue;
            dist[v] = dist[u] + cost;
            dfs(v, u);
            sz[u] += sz[v];
        }

        posOut[u] = curPos;
    }

    int getPar(int u, int k) {
        for (int i = 0; i < par.size(); i++) {
            if (k >> i & 1) {
                u = par[i][u];
            }
        }
        return u;
    }

    int getLCA(int u, int v) {
        if (lv[u] < lv[v]) swap(u, v);
        u = getPar(u, lv[u] - lv[v]);
        if (u == v) return u;
        for (int i = (int)par.size() - 1; i >= 0; i--) {
            if (par[i][u] != par[i][v]) {
                u = par[i][u];
                v = par[i][v];
            }
        }
        return par[0][u];
    }

    // find k-th node in path from u to v
    // k = 0 returns u
    // returns -1 if invalid
    int getNodeFromPath(int u, int v, int k) {
        if (k < 0) return -1;
        int w = getLCA(u, v);
        int hu = lv[u] - lv[w];
        if (k <= hu) return getPar(u, k);
        k -= hu;
        int hv = lv[v] - lv[w];
        if (k > hv) return -1;
        return getPar(v, hv - k);
    }

    // true if u is v's ancestor
    bool isAncestor(int u, int v) {
        return posIn[u] <= posIn[v] && posOut[v] <= posOut[u];
    }

    struct StackElement {
        int y;
        vector<int> *x;
        ordered_set *s;
        StackElement(int xx, int y) : y(y) {
            x = new vector<int>();
            x->push_back(xx);
            s = new ordered_set();
        }
    };

    long long join(StackElement &foo, StackElement &bar, int root) {
        int w = getLCA(foo.y, bar.y);
        long long res = 0;
        if (foo.x->size() < bar.x->size()) swap(foo, bar);
        for (int x : *bar.x) {
            int xx = getNodeFromPath(w, x, max(k, lv[w] - lv[root]));
            if (xx != -1) {
                res += foo.s->order_of_key({posOut[xx] + 1, -1}) - foo.s->order_of_key({posIn[xx], -1});
            }
        }
        foo.y = w;
        foo.x->insert(foo.x->end(), bar.x->begin(), bar.x->end());
        for (auto val : *bar.s) {
            foo.s->insert(val);
        }
        bar.x->clear();
        bar.s->clear();
        return res;
    }

    long long solve(int u, int p) {
        long long res = 0;

        for (auto e : adj[u]) {
            int v = e.first;
            T cost = e.second;
            if (v == p) continue;
            res += solve(v, u);
        }

        sort(ls[u].begin(), ls[u].end(), [&](pair<int, int> u, pair<int, int> v) {return posIn[u.second] < posIn[v.second];});

        // case 1
        for (auto val : ls[u]) {
            int x, y;
            tie(x, y) = val;
            res += t.get(posIn[x]);
            res += t.get(posIn[y]);
        }
        for (auto val : ls[u]) {
            int x, y;
            tie(x, y) = val;
            if (lv[x] - lv[u] >= k) {
                int xx = getPar(x, lv[x] - lv[u] - k);
                t.add(posIn[xx], 1);
                t.add(posOut[xx] + 1, -1);
            }
            if (lv[y] - lv[u] >= k) {
                int yy = getPar(y, lv[y] - lv[u] - k);
                t.add(posIn[yy], 1);
                t.add(posOut[yy] + 1, -1);
            }
        }

        // case 2
        vector<int> listY;
        for (auto val : ls[u]) {
            int x, y;
            tie(x, y) = val;
            if (lv[x] - lv[u] >= k) {
                int xx = getPar(x, lv[x] - lv[u] - k);
                res += upper_bound(listY.begin(), listY.end(), posIn[xx]) - lower_bound(listY.begin(), listY.end(), posIn[xx]);
            }
            if (lv[y] - lv[u] >= k) {
                int yy = getPar(y, lv[y] - lv[u] - k);
                listY.push_back(posIn[yy]);
            }
        }

        // case 3
        vector<StackElement> st;
        for (auto val : ls[u]) {
            int x, y;
            tie(x, y) = val;
            while (st.size() >= 2) {
                int w1 = getLCA(st[st.size() - 2].y, st[st.size() - 1].y);
                int w2 = getLCA(st.back().y, y);
                if (isAncestor(w1, w2)) break;
                StackElement foo = st.back();
                st.pop_back();
                StackElement bar = st.back();
                st.pop_back();
                res += join(foo, bar, u);
                st.push_back(foo);
            }
            StackElement now(x, y);
            now.s->insert({posIn[x], ++curPos});
            st.push_back(now);
        }

        while (st.size() >= 2) {
            StackElement foo = st.back();
            st.pop_back();
            StackElement bar = st.back();
            st.pop_back();
            res += join(foo, bar, u);
            st.push_back(foo);
        }

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;

    Tree<int> tree(n);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v);
    }
    
    tree.dfs(1, 0);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (tree.posIn[u] > tree.posIn[v]) swap(u, v);
        tree.ls[tree.getLCA(u, v)].push_back({u, v});
    }

    cout << tree.solve(1, 0) << endl;
    return 0;
}