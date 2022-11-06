#include <bits/stdc++.h>
using namespace std;
const int maxN = 200;
int n, a[maxN + 10], oddCnt, eveCnt;
int s = 1, t = 2, ndCnt = 2, mp[maxN + 10], ans;

struct Edge {
    int to, cap, flow, rev;
};
vector<Edge> g[maxN + 10];
int d[maxN + 10], cur[maxN + 10];
queue<int> q;
vector<int> z[maxN + 10];
int dCnt;
vector<int> ansId[maxN + 10];
bool vis[maxN + 10];

void AddEdge(int u, int v, int w) {
    g[u].push_back((Edge){v, w, 0, g[v].size()});
    g[v].push_back((Edge){u, 0, 0, g[u].size() - 1});
}

bool IsPrime(int v) {
    for (int i = 2; i * i <= v; ++i)
        if (v % i == 0) return 0;
    return 1;
}

bool Bfs() {
    for (int i = 1; i <= ndCnt; ++i)
        d[i] = i == s ? 0 : -1;
    q.push(s);
    while (!q.empty()) {
        int p = q.front(); q.pop();
        for (int i = 0; i < g[p].size(); ++i) {
            Edge e = g[p][i];
            if (e.cap > e.flow && d[e.to] == -1) {
                d[e.to] = d[p] + 1; q.push(e.to);
            }
        }
    }
    return d[t] != -1;
}

int Dfs(int p, int a) {
    if (p == t) return a;
    int ans = 0, now;
    for (int &i = cur[p]; i < g[p].size(); ++i) {
        Edge &e = g[p][i];
        if (e.cap > e.flow && d[p] + 1 == d[e.to]) {
            now = Dfs(e.to, min(a, e.cap - e.flow));
            e.flow += now; g[e.to][e.rev].flow -= now;
            ans += now; a -= now;
            if (!a) break;
        }
    }
    return ans;
}

void DfsAns(int p) {
    vis[p] = 1; ansId[dCnt].push_back(p);
    for (int i = 0; i < z[p].size(); ++i) {
        int e = z[p][i];
        if (!vis[e]) DfsAns(e);
    } 
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        mp[i] = ++ndCnt;
        if (a[i] % 2) {
            AddEdge(s, mp[i], 2);
            ++oddCnt;
        } else {
            AddEdge(mp[i], t, 2);
            ++eveCnt;
        }
    }
    if (oddCnt != eveCnt) {
        printf("Impossible"); return 0;
    }
    for (int i = 1; i <= n; ++i)
        if (a[i] % 2) {
            for (int j = 1; j <= n; ++j)
                if (IsPrime(a[i] + a[j])) AddEdge(mp[i], mp[j], 1);
        }
    while (Bfs()) {
        for (int i = 1; i <= ndCnt; ++i) cur[i] = 0;
        ans += Dfs(s, 1e9);
    }
    if (ans != n) {
        printf("Impossible"); return 0;
    } 
    for (int i = 1; i <= n; ++i)
        if (a[i] % 2) {
            for (int j = 0; j < g[mp[i]].size(); ++j) {
                Edge e = g[mp[i]][j];
                if (e.to > 2 && e.flow) {
                    z[i].push_back(e.to - 2);
                    z[e.to - 2].push_back(i);
                }
            }
        }
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) {
            ++dCnt; DfsAns(i);
        }
    printf("%d\n", dCnt);
    for (int i = 1; i <= dCnt; ++i) {
        printf("%d ", (int)ansId[i].size());
        for (int j = 0; j < ansId[i].size(); ++j)
            printf("%d ", ansId[i][j]);
        printf("\n");
    }
}