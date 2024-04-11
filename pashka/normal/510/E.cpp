#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <assert.h>
#include <queue>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L
#define PI 3.141592653589793238462643383279502884L

#define long long long int

using std::vector;
using std::map;
using std::set;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::cerr;

// @author: pashka

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

bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    graph.resize(n + 2);
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            addEdge(n, i, 2);
            for (int j = 0; j < n; j++) {
                if (isPrime(a[i] + a[j])) {
                    addEdge(i, j, 1);
                }
            }
        } else {
            addEdge(i, n + 1, 2);
        }
    }

    int fl = maxFlow(n, n + 1);
    if (fl < n) {
        cout << "Impossible";
    } else {
        vector<bool> z(n);
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0 && !z[i]) {
                vector<int> p;
                int c = i;
                while (!z[c]) {
                    p.push_back(c);
                    z[c] = true;
                    for (int t = 0; t < graph[c].size(); t++) {
                        edge &e = edges[graph[c][t]];
                        if (e.dst < n && !z[e.dst] && e.flw != 0) {
                            c = e.dst;
                            break;
                        }
                    }
                }
                ans.push_back(p);
            }
        }
        cout << ans.size() << "\n";
        for (auto &p : ans) {
            cout << p.size();
            for (auto i : p) {
                cout << " " << (i + 1);
            }
            cout << "\n";
        }
    }

    return 0;
}