#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;

//for two nodes u and v, dist(u, v) = d(u) + d(v) - 2 * d(lca(u, v))
//euler tour, than for any l <= v <= r, lca(l, r) is minimum d(v)
//thus we don't have to find lca, but just find the maximum value of d(l) + d(r) - 2d(v), for l <= v <= r    

struct Tree {
    struct SegmentTree {
        struct Node {
            lint max_depth = 0, min_depth = 0, max_lv = 0, max_vr = 0, max_lvr = 0, lazy = 0;
            //lv, vr, lvr maintain max of d(l) - 2d(v), d(r) - 2d(v), d(l) + d(r) - 2d(v)
        };

        inline Node ADD(Node &a, Node &b) {
            Node r;
            r.max_depth = max(a.max_depth, b.max_depth);
            r.min_depth = min(a.min_depth, b.min_depth);
            r.max_lv = max({a.max_lv, b.max_lv, a.max_depth - 2 * b.min_depth});
            r.max_vr = max({a.max_vr, b.max_vr, b.max_depth - 2 * a.min_depth});
            r.max_lvr = max({a.max_lvr, b.max_lvr, a.max_lv + b.max_depth, a.max_depth + b.max_vr});
            return r;
        }

        inline void UPD(Node &a, lint x) {
            a.max_depth += x;
            a.min_depth += x;
            a.max_lv -= x;
            a.max_vr -= x;
            a.lazy += x;
        }

        vector<Node> tree;

        void lazydown(lint n) {
            UPD(tree[2 * n], tree[n].lazy);
            UPD(tree[2 * n + 1], tree[n].lazy);
            tree[n].lazy = 0;
        }

        void update(lint n, lint tl, lint tr, lint le, lint ri, lint x) {
            if (tl > tr || tr < le || ri < tl || le > ri) return;
            if (le <= tl && tr <= ri) {
                UPD(tree[n], x);
                return;
            }
            lazydown(n);
            lint mid = (tl + tr) / 2;
            update(2 * n, tl, mid, le, ri, x);
            update(2 * n + 1, mid + 1, tr, le, ri, x);
            tree[n] = ADD(tree[2 * n], tree[2 * n + 1]);
        }

        void resize(lint n) {
            tree.resize(8 * n + 5);
        }

    } seg;

    struct edge {
        lint u, v;
        lint c;
    };

    lint N;
    lint counter = 0;
    vector<edge> edges;
    vector<vector<lint>> graph;
    vector<lint> st, et;

    void dfs(lint n, lint e, lint p) {
        st[e] = counter++;
        for (auto v : graph[n]) {
            if ((edges[v].u ^ edges[v].v ^ n) == p) continue;
            dfs((edges[v].u ^ edges[v].v ^ n), v, n);
            seg.update(1, 0, 2 * N - 1, st[v], et[v] - 1, edges[v].c);
            counter++;
        }
        et[e] = counter;
    }

    void add_edge(lint u, lint v, lint c) {
        graph[u].push_back(edges.size());
        graph[v].push_back(edges.size());
        edges.push_back({u, v, c});
    }

    void resize(lint n) {
        graph.resize(n);
        st.resize(n);
        et.resize(n);
        seg.resize(n);
        N = n;
    }

    void initialize() {
        dfs(0, N - 1, -1);
    }

    inline lint query(lint d, lint e) {
        seg.update(1, 0, 2 * N - 1, st[d], et[d] - 1, (e - edges[d].c));
        edges[d].c = e;
        return seg.tree[1].max_lvr;
    }

} Solver;

int main() {
    int N, Q;
    lint W;
    cin >> N >> Q >> W;
    Solver.resize(N);
    for (int i = 1; i < N; i++) {
        int u, v; lint c;
        cin >> u >> v >> c;
        u--; v--;
        Solver.add_edge(u, v, c);
    }

    Solver.initialize();
    
    lint last = 0;
    for (int i = 0; i < Q; i++) {
        lint d, e;
        cin >> d >> e;
        d = (d + last) % (N - 1);
        e = (e + last) % W;
        last = Solver.query(d, e);
        cout << last << '\n';   
    }

    return 0;
}