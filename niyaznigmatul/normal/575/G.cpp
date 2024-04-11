#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <queue>
#include <algorithm>
#include <cassert>
#include <cstdio>

using namespace std;

struct Edge
{
    Edge(int v, int c):v(v), c(c) {}
    int v, c;
};

const int INF = numeric_limits<int>::max();
const int NMAX = 200000;

int n;
typedef vector<Edge> Graph[NMAX];
Graph g;
vector<int> ans;
int ppp[NMAX];
int dpp[NMAX];

void bfs(int s, const Graph& g, vector<int>& d, bool rem)
{
    queue<int> q, qq;
    q.push(s);
    qq.push(s);

    d.resize(n, INF);
    d[s] = 0;
    if (rem)
        while (!qq.empty()) {
            int v = qq.front();
            qq.pop();
            for(size_t i = 0; i < g[v].size(); ++i) {
                const Edge& e = g[v][i];
                if (e.c == 0 && d[e.v] == INF) {
                    d[e.v] = 0;
                    q.push(e.v);
                    qq.push(e.v);
                    ppp[e.v] = v;
                    dpp[e.v] = dpp[v] + 1;
                }
            }
        }



    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for(size_t i = 0; i < g[v].size(); ++i) {
            const Edge& e = g[v][i];
            if (d[e.v] == INF) {
                d[e.v] = d[v] + 1;
                q.push(e.v);
            }
        }
    }
}

class ClearedUsed
{
public:
    ClearedUsed(size_t size)
        : curIdx_(0), used_(size, -1)
    {}

    void use(int idx)
    {
        used_[idx] = curIdx_;
    }

    bool isUsed(int idx)
    {
        return used_[idx] == curIdx_;
    }

    void clear()
    {
        ++curIdx_;
    }
private:
    int curIdx_;
    vector<int> used_;
};

int layer[2][NMAX];
int pos[2];

void solve() {
    vector<int> dFrom, dTo;
    int s = 0, t = n - 1;
    bfs(0, g, dFrom, true);
    int dist = dFrom[t];
    // assert(dist != INF);
    bfs(t, g, dTo, false);

    vector<int> ans, path;

    ClearedUsed used(n);

    int ci = 0, ni = 1;
    pos[ci] = 0;
    for (int i = 0; i < n; i++) if (dFrom[i] == 0)
        layer[ci][pos[ci]++] = i;
    for(int curDist = 0; curDist < dist; ++curDist) {
        int minColor = INF;

        for(int vertexIter = 0; vertexIter < pos[ci]; ++vertexIter) {
            int v = layer[ci][vertexIter];
            //assert(dFrom[v] == curDist);
            for(size_t edgeIter = 0; edgeIter < g[v].size(); ++edgeIter) {
                const Edge& e = g[v][edgeIter];
                if (dTo[e.v] == dist - curDist - 1) {
                    if (e.c < minColor) {
                        minColor = e.c;
                        pos[ni] = 1;
                        layer[ni][0] = e.v;
                        ppp[e.v] = v;
                        dpp[e.v] = dpp[v] + 1;
                        used.clear();
                        used.use(e.v);
                    } else if (e.c == minColor) {
                        if (!used.isUsed(e.v)) {
                            layer[ni][pos[ni]++] = e.v;
                            used.use(e.v);
                            ppp[e.v] = v;
                            dpp[e.v] = dpp[v] + 1;
                        } else if (dpp[v] + 1 < dpp[e.v]) {
                            ppp[e.v] = v;
                            dpp[e.v] = dpp[v] + 1;
                        }
                    }
                }
            }
        }
        //assert(minColor != INF);
        ans.push_back(minColor);

        pos[ci] = 0;
        swap(ci, ni);
    }
    path.push_back(t);
    string res = "";
    for(size_t i = 0; i < ans.size(); ++i) {
        printf("%d", ans[i]);
    }
    if (ans.size() == 0) printf("0");
    printf("\n");
    reverse(path.begin(), path.end());
    while (path.back() != s) {
        int x = path.back();
        path.push_back(ppp[x]);
    }
    printf("%d\n", (int) path.size());
    for (size_t i = 0; i < path.size(); ++i) {
        if (i > 0) putchar(' ');
        printf("%d", n - path[i] - 1);
    }
    puts("");
}

void readdata() {
    int m;
    assert(scanf("%d%d", &n, &m) == 2);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        assert(scanf("%d%d%d", &a, &b, &c) == 3);
        a = n - a - 1;
        b = n - b - 1;
        g[a].push_back(Edge(b, c));
        g[b].push_back(Edge(a, c));
    }
}

int main() {
    readdata();
    solve();
    return 0;
}