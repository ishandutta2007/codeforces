#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

struct edge {
    int f, c;
    edge() {
        f = c = 0;
    }
    edge(int _c) {
        f = 0;
        c = _c;
    }
};

vector<edge> edges;
vector<vector<pii>> graph;

int add_edge(int a, int b, int c) {
    graph[a].puba({b, szof(edges)});
    edges.puba(edge(c));
    graph[b].puba({a, szof(edges)});
    edges.puba(edge());
    return 0;
}

int add_node() {
    graph.puba({});
    return szof(graph) - 1;
}

vector<int> dist;
vector<int> cnt;

int build_layers(int s, int t) {
    dist = vector<int>(szof(graph), INF);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (szof(q)) {
        int v = q.front();
        q.pop();
        for (pii to : graph[v]) {
            auto& e = edges[to.ss];
            if (e.f < e.c && dist[to.ff] > dist[v] + 1) {
                dist[to.ff] = dist[v] + 1;
                q.push(to.ff);
            }
        }
    }
    if (dist[t] == INF) {
        return 0;
    }
    return 1;
}

int push_flow(int v, int t, int f) {
    //cerr << v << endl;
    if (v == t) {
        return f;
    }
    while (cnt[v] < szof(graph[v])) {
        pii to = graph[v][cnt[v]];
        //cerr << v << " " << to.ff << " " << to.ss << endl;
        auto& e = edges[to.ss];
        //cerr << v << " -> " << to.ff << " " << e.f << " " << e.c << " " << dist[v] << " " << dist[to.ff] << endl;
        if (e.f < e.c && dist[to.ff] == dist[v] + 1) {
            int tmp = push_flow(to.ff, t, min(f, e.c - e.f));
            if (tmp) {
                e.f += tmp;
                edges[to.ss ^ 1].f -= tmp;
                //cerr << v << " " << to.ff << endl;
                return tmp;
            }
        }
        ++cnt[v];
    }
    return 0;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, m;
    scanf("%d%d", &n, &m);

    int s = add_node();
    int t = add_node();
    vector<int> index;

    vector<int> nodes;
    for (int i = 0; i < n; ++i) {
        nodes.puba(add_node());
    }

    vector<pii> inp;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        inp.puba({a, b});
        int tmp = add_node();
        index.puba(szof(edges));
        add_edge(s, tmp, 1);
        add_edge(tmp, nodes[a], 1);
        add_edge(tmp, nodes[b], 1);
    }
    
    for (int i = 0; i < n; ++i) {
        add_edge(nodes[i], t, 0);
    }

    int l = -1, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        for (auto& e : edges) {
            e.f = 0;
        }
        for (int i = 0; i < n; ++i) {
            edges[szof(edges) - 2 - i * 2].c = mid;
        }

        //cerr << mid << endl;

        int flow = 0;
        while (build_layers(s, t)) {
            cnt = vector<int>(szof(graph), 0);
            int tmp = 0;
            while ((tmp = push_flow(s, t, INF))) {
                flow += tmp;
            }
        }

        //cerr << flow << endl;
        if (flow == m) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << "\n";

    for (auto& e : edges) {
        e.f = 0;
    }
    for (int i = 0; i < n; ++i) {
        edges[szof(edges) - 2 - i * 2].c = r;
    }

    //cerr << r << endl;

    int flow = 0;
    while (build_layers(s, t)) {
        cnt = vector<int>(szof(graph), 0);
        int tmp = 0;
        while ((tmp = push_flow(s, t, INF))) {
            flow += tmp;
        }
    }

    for (int i = 0; i < m; ++i) {
        if (edges[index[i] + 2].f) {
            cout << inp[i].ff + 1 << " " << inp[i].ss + 1 << "\n";
        } else {
            cout << inp[i].ss + 1 << " " << inp[i].ff + 1 << "\n";
        }
    }
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}