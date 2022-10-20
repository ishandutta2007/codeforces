#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

struct DSU {
    int numComp;
    vector<int> root;

    DSU(int n = 0) {
        numComp = n;
        root.assign(n + 1, 0);
    }

    int getRoot(int u) {
        return root[u] ? root[u] = getRoot(root[u]) : u;
    }

    bool unite(int u, int v) {
        u = getRoot(u); v = getRoot(v);
        if (u == v) return 0;
        root[v] = u;
        numComp--;
        return 1;
    }
};

int n, m, q;
int p[N];
bool del[N];
list<int> ls[N];
pair<int, int> queryRange[N];
int posInEulerTour[N];
int eulerTour[N];

struct Node {
    int maxVal;
    int id;

    Node(int maxVal = 0, int id = 0) : maxVal(maxVal), id(id) {
        
    }

    template<typename Query>
    void apply(int l, int r, const Query &val) {
        maxVal = val;
        id = l;
    }

    void pull(const Node &u, const Node &v) {
        *this = u.maxVal > v.maxVal ? u : v;
    }

    void push(int l, int r, Node &u, Node &v) {
        
    }
};

struct SegmentTree {
    void init(int node, int l, int r) {
        if (l == r) {
            t[node].apply(l, r, p[eulerTour[l]]);
            return;
        }
        int m = l + r >> 1;
        init(node << 1, l, m);
        init(node << 1 | 1, m + 1, r);
        t[node].pull(t[node << 1], t[node << 1 | 1]);
    }

    /*-----------------------------------------------------------*/
    int n;
    vector<Node> t;
    
    SegmentTree(int n) : n(n) {
        t.assign(n << 2 | 1, {});
        init(1, 1, n);
    }

    template<typename Query>
    void update(int node, int l, int r, int x, int y, const Query &val) {
        if (x > r || y < l) return;
        if (x <= l && r <= y) {
            t[node].apply(l, r, val);
            return;
        }
        int m = l + r >> 1;
        t[node].push(l, r, t[node << 1], t[node << 1 | 1]);
        update(node << 1, l, m, x, y, val);
        update(node << 1 | 1, m + 1, r, x, y, val);
        t[node].pull(t[node << 1], t[node << 1 | 1]);
    }

    Node get(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return Node();
        if (x <= l && r <= y) return t[node];
        int m = l + r >> 1;
        t[node].push(l, r, t[node << 1], t[node << 1 | 1]);
        Node p1 = get(node << 1, l, m, x, y);
        Node p2 = get(node << 1 | 1, m + 1, r, x, y);
        Node res;
        res.pull(p1, p2);
        return res;
    }
};

struct Edge {
    int u, v;
} e[N];

struct Query {
    int op, u;
} queries[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v;
    }
    for (int i = 1; i <= q; i++) {
        cin >> queries[i].op >> queries[i].u;
        if (queries[i].op == 2) del[queries[i].u] = 1;
    }
    DSU dsu(n);
    for (int i = 1; i <= n; i++) {
        ls[i].push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        if (!del[i]) {
            int u = dsu.getRoot(e[i].u);
            int v = dsu.getRoot(e[i].v);
            if (dsu.unite(u, v)) ls[u].splice(ls[u].end(), ls[v]);
        }
    }
    for (int i = q; i; i--) {
        if (queries[i].op == 1) {
            int u = dsu.getRoot(queries[i].u);
            queryRange[i] = {*ls[u].begin(), *ls[u].rbegin()};
        } else {
            int u = dsu.getRoot(e[queries[i].u].u);
            int v = dsu.getRoot(e[queries[i].u].v);
            if (dsu.unite(u, v)) {
                ls[u].splice(ls[u].end(), ls[v]);
            }
        }
    }
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (dsu.getRoot(i) == i) {
            for (int u : ls[i]) {
                posInEulerTour[u] = ++cur;
                eulerTour[cur] = u;
            }
        }
    }
    SegmentTree st(n);
    for (int i = 1; i <= q; i++) {
        if (queries[i].op == 1) {
            int l = posInEulerTour[queryRange[i].first];
            int r = posInEulerTour[queryRange[i].second];
            Node res = st.get(1, 1, n, l, r);
            cout << res.maxVal << '\n';
            st.update(1, 1, n, res.id, res.id, 0);
        }
    }
    return 0;
}