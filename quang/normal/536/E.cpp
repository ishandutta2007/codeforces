#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, q;
vector<int> adj[N];
int f[N];
tuple<int, int, int> edges[N];
tuple<int, int, int, int> queries[N];
int lv[N], par[N], numChild[N];
int top[N], HLDList[N], posInHLD[N], cntHLD;
int res[N];

void dfsInit(int u, int p) {
    lv[u] = lv[p] + 1;
    par[u] = p;
    numChild[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfsInit(v, u);
        numChild[u] += numChild[v];
    }
}

void dfsBuildHLD(int u, int p, int root) {
    top[u] = root;
    HLDList[++cntHLD] = u;
    posInHLD[u] = cntHLD;
    int maxChild = -1;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (maxChild == -1 || numChild[maxChild] < numChild[v]) {
            maxChild = v;
        }
    }
    if (maxChild != -1) dfsBuildHLD(maxChild, u, root);
    for (int v : adj[u]) {
        if (v == p || v == maxChild) continue;
        dfsBuildHLD(v, u, v);
    }
}

struct Node {
    int pref, suff, sum;
    int full;
    Node(int pref = 0, int suff = 0, int sum = 0, int full = 0) : pref(pref), suff(suff), sum(sum), full(full) {}

    void set() {
        pref = suff = 1;
        full = 1;
        sum = 0;
    }

    void merge(Node l, Node r) {
        if (l.full == -1) {
            *this = r;
            return;
        }
        if (r.full == -1) {
            *this = l;
        }
        if (l.full) {
            if (r.full) {
                pref = suff = l.pref + r.pref;
                full = 1;
                sum = 0;
            } else {
                sum = r.sum;
                suff = r.suff;
                pref = l.pref + r.pref;
                full = 0;
            }
        } else {
            if (r.full) {
                sum = l.sum;
                pref = l.pref;
                suff = l.suff + r.suff;
                full = 0;
            } else {
                full = 0;
                sum = l.sum + r.sum;
                pref = l.pref;
                suff = r.suff;
                sum += f[l.suff + r.pref];
            }
        }
    }

    void flip() {
        swap(suff, pref);
    }

    int get() {
        if (full) return f[pref];
        int res = sum;
        res += f[pref];
        res += f[suff];
        return res;
    }
};

struct IT {
    Node t[N << 2];

    void set(int node, int l, int r, int id) {
        if (id > r || id < l) return;
        if (l == r) {
            t[node].set();
            return;
        }
        int m = l + r >> 1;
        set(node << 1, l, m, id);
        set(node << 1 | 1, m + 1, r, id);
        t[node].merge(t[node << 1], t[node << 1 | 1]);
    }

    Node get(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return Node(0, 0, 0, -1);
        if (x <= l && r <= y) {
            return t[node];
        }
        int m = l + r >> 1;
        Node p1 = get(node << 1, l, m, x, y);
        Node p2 = get(node << 1 | 1, m + 1, r, x, y);
        p1.merge(p1, p2);
        return p1;
    }
} it;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        cin >> f[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {w, u, v};
    }
    for (int i = 1; i <= q; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        queries[i] = {l, u, v, i};
    }
    sort(queries + 1, queries + q + 1);
    sort(edges + 1, edges + n);
    reverse(queries + 1, queries + q + 1);
    reverse(edges + 1, edges + n);

    dfsInit(1, 0);
    dfsBuildHLD(1, 0, 1);
    int cur = 1;
    for (int i = 1; i <= q; i++) {
        while (cur <= n && get<0>(edges[cur]) >= get<0>(queries[i])) {
            int u = get<1>(edges[cur]);
            int v = get<2>(edges[cur]);
            int id = par[u] == v ? u : v;
            it.set(1, 1, n, posInHLD[id]);
            cur++;
        }

        int len, u, v, id;
        tie(len, u, v, id) = queries[i];
        Node uu, vv;
        while (top[u] != top[v]) {
            if (lv[top[u]] < lv[top[v]]) {
                swap(u, v);
                swap(uu, vv);
            }
            Node foo = it.get(1, 1, n, posInHLD[top[u]], posInHLD[u]);
            uu.merge(foo, uu);
            u = par[top[u]];
        }
        if (lv[u] < lv[v]) {
            swap(u, v);
            swap(uu, vv);
        }
        if (u != v) {
            Node foo = it.get(1, 1, n, posInHLD[v] + 1, posInHLD[u]);
            uu.merge(foo, uu);
        }
        uu.flip();
        uu.merge(uu, vv); 
        res[id] = uu.get();
    }   
    for (int i = 1; i <= q; i++) cout << res[i] << '\n';
    return 0;
}