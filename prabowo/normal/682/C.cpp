#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int n;
int a[N];
vector <pair<int, int>> edge[N];

int sz[N];
int getSize(int u) {
    for (int i=0; i<edge[u].size(); i++) {
        int v = edge[u][i].first;
        sz[u] += getSize(v);
    }
    return ++sz[u];
}

int dfs (int u, int dist) {
    if (dist > a[u]) return sz[u];
    
    int ret = 0;
    for (int i=0; i<edge[u].size(); i++) {
        int v = edge[u][i].first;
        int w = edge[u][i].second;
        ret += dfs(v, max(0, dist + w));
    }
    return ret;
}

int main() {
    scanf ("%d", &n);
    for (int i=0; i<n; i++) scanf ("%d", a + i);
    
    int u, v, w;
    for (int i=1; i<n; i++) {
        scanf ("%d %d", &u, &w);
        edge[--u].push_back(make_pair(i, w));
    }
    
    getSize(0);
    printf ("%d\n", dfs(0, 0));
    
    return 0;
}