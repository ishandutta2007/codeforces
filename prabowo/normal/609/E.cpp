#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int N = 200000;
const int M = 200000;

struct Edge {
    int u, v, w;

    bool operator < (const Edge &other) const {
        return w < other.w;
    }
};

int n, m;
Edge edges[M];
vector < pair<int, int> > adj[N]; // adjacency list of the minimum spanning tree

struct Minimum_Spanning_Tree {
    int parent[N];
    Edge edge[N];

    int dsu (int x) {
        if (x == parent[x]) return x;
        return parent[x] = dsu(parent[x]);
    }

    long long Kruskal () {
        for (int i=0; i<m; i++) edge[i] = edges[i];
        sort (edge, edge + m);

        for (int i=0; i<n; i++)
            parent[i] = i;

        int cnt = 0;
        long long ret = 0;
        for (int i=0; i<m; i++) {
            if (dsu(edge[i].u) != dsu(edge[i].v)) {
                adj[ edge[i].u ].push_back ( make_pair(edge[i].v, edge[i].w) );
                adj[ edge[i].v ].push_back ( make_pair(edge[i].u, edge[i].w) );

                parent[dsu(edge[i].u)] = dsu(edge[i].v);
                ret += edge[i].w;

                //printf("%d %d %d\n", edge[i].u, edge[i].v, edge[i].w);
            }
        }

        return ret;
    }
} mst;

struct Segment_Tree {
    int maks[4 * N];

    void update (int node, int l, int r, int x, int val) {
        if (l > x || r < x) return;
        if (l == x && r == x) {
            maks[node] = val;
            return;
        }

        int mid = l + r >> 1;
        update (2 * node + 1, l, mid + 0, x, val);
        update (2 * node + 2, mid + 1, r, x, val);
        maks[node] = max(maks[2 * node + 1], maks[2 * node + 2]);
        return;
    }

    int query (int node, int l, int r, int a, int b) {
        if (l > b || r < a) return 0;
        if (l >= a && r <= b) return maks[node];

        int mid = l + r >> 1;
        return max(query (2 * node + 1, l, mid + 0, a, b), query (2 * node + 2, mid + 1, r, a, b));
    }
} segment;

struct Heavy_Light_Decomposition {
    int parent[N], heavy[N];
    int size[N], depth[N];
    int chain[N], head[N];
    int order[N], value[N];

    void dfs (int x) {

        size[x] = 1;
        for (int i=0; i<adj[x].size(); i++) {
            int j = adj[x][i].first;
            if (j == parent[x]) continue;

            parent[j] = x;
            depth[j] = depth[x] + 1;
            value[j] = adj[x][i].second;

            dfs(j);

            size[x] += size[j];
            if (heavy[x] == -1 || size[heavy[x]] < size[j])
                heavy[x] = j;
        }

    }

    void build () {
        parent[0] = -1;
        depth[0] = 0;
        memset (heavy, -1, sizeof heavy);

        dfs(0);

        int cnt = 0;
        int pre = 0;

        for (int i=0; i<n; i++) {
            if (parent[i] == -1 || heavy[parent[i]] != i) {
                for (int j=i; j != -1; j = heavy[j]) {
                    chain[j] = cnt;
                    head[j] = i;
                    segment.update(0, 0, n-1, pre, value[j]);
                    order[j] = pre++;
                }
                cnt++;
            }
        }
    }

    int query (int x, int y) {
        int ret = 0;
        while (chain[x] != chain[y]) {
            if (depth[head[x]] < depth[head[y]]) {
                ret = max(ret, segment.query(0, 0, n-1, order[head[y]], order[y]));
                y = parent[head[y]];
            } else {
                ret = max(ret, segment.query(0, 0, n-1, order[head[x]], order[x]));
                x = parent[head[x]];
            }
        }

        if (depth[x] < depth[y])
            return max(ret, segment.query(0, 0, n-1, order[x] + 1, order[y]));
        return max(ret, segment.query(0, 0, n-1, order[y] + 1, order[x]));
    }
} hld;

void init () {
    scanf("%d %d", &n, &m);

    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        edges[i].u--;
        edges[i].v--;
    }
}

int solve () {
    long long ans = mst.Kruskal();
    hld.build();

    for (int i=0; i<m; i++)
        printf("%I64d\n", ans + edges[i].w - hld.query(edges[i].u, edges[i].v));

    return 0;
}

int main () {
    init();
    solve();
    return 0;
}