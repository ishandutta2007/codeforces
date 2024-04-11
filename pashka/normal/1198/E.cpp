#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

vector<int> make(vector<int> x1, vector<int> x2) {
    vector<int> x;
    x.insert(x.end(), x1.begin(), x1.end());
    x.insert(x.end(), x2.begin(), x2.end());
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    return x;
}

struct edge {
    int src, dst, cap, flw;
};

vector<edge> edges;
vector<vector<int>> graph;
vector<int> first;
vector<int> dist;

void bfs(int s) {
    dist.assign(graph.size(), -1);
    dist[s] = 0;
    int h = 0;
    vector<int> q;
    q.push_back(s);
    while (h < q.size()) {
        int x = q[h++];
        for (int i = 0; i < graph[x].size(); i++) {
            edge &e = edges[graph[x][i]];
            if (e.flw == e.cap) continue;
            int y = e.dst;
            if (dist[y] == -1) {
                dist[y] = dist[x] + 1;
                q.push_back(y);
            }
        }
    }
}

int dfs(int x, int t, int f) {
    if (f == 0) return 0;
    if (x == t) return f;
    for (int i = first[x]; i < graph[x].size(); i++) {
        edge &e = edges[graph[x][i]];
        edge &er = edges[graph[x][i] ^ 1];
        if (e.flw == e.cap || dist[e.dst] != dist[e.src] + 1)
            continue;
        int y = e.dst;
        int res = dfs(y, t, std::min(f, e.cap - e.flw));
        if (res > 0) {
            e.flw += res;
            er.flw -= res;
            return res;
        }
    }
    return 0;
}

long maxFlow(int s, int t) {
    long flow = 0;
    while (true) {
        bfs(s);
        first.assign(graph.size(), 0);
        if (dist[t] == -1) break;
        while (true) {
            int pushed = dfs(s, t, MAX_INT);
            if (pushed > 0) {
                flow += pushed;
            } else {
                break;
            }
        }
    }
    return flow;
}

void addEdge(int u, int v, int cap) {
//    cout << u << " " << v << "\n";
    edges.push_back({u, v, cap, 0});
    edges.push_back({v, u, 0, 0});
    graph[u].push_back(edges.size() - 2);
    graph[v].push_back(edges.size() - 1);
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> x1(m), x2(m), y1(m), y2(m);
    for (int i = 0; i < m; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        x1[i]--;
        y1[i]--;
    }

    if (m == 0) {
        cout << 0;
        return 0;
    }

    vector<int> x = make(x1, x2);
    vector<int> y = make(y1, y2);

    int ln = x.size() - 1;
    int rn = y.size() - 1;
    
    graph.resize(ln + rn + 2 * m + 2);
    for (int i = 0; i < ln; i++) {
        addEdge(graph.size() - 2, i, x[i + 1] - x[i]);
    }
    for (int i = 0; i < rn; i++) {
        addEdge(ln + i, graph.size() - 1, y[i + 1] - y[i]);
    }
    for (int i = 0; i < m; i++) {
        int xx1 = lower_bound(x.begin(), x.end(), x1[i]) - x.begin();
        int xx2 = lower_bound(x.begin(), x.end(), x2[i]) - x.begin();
        int yy1 = lower_bound(y.begin(), y.end(), y1[i]) - y.begin();
        int yy2 = lower_bound(y.begin(), y.end(), y2[i]) - y.begin();
        for (int j = xx1; j < xx2; j++) {
            addEdge(j, ln + rn + i, x[j + 1] - x[j]);
        }
        for (int j = yy1; j < yy2; j++) {
            addEdge(ln + rn + m + i, ln + j, y[j + 1] - y[j]);
        }
        addEdge(ln + rn + i, ln + rn + m + i, n);
    }
    cout << maxFlow(graph.size() - 2, graph.size() - 1);    

    return 0;
}