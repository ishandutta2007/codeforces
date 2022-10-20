#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m, k;
int sz[N];
int root[N];

struct Edge {
    int u, v, w;
} a[N];

bool cmp(Edge u, Edge v) {
    return u.w < v.w;
}

int getRoot(int u) {
    return root[u] ? root[u] = getRoot(root[u]) : u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        sz[x] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
    }
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        int u = a[i].u;
        int v = a[i].v;
        u = getRoot(u);
        v = getRoot(v);
        if (u == v) continue;
        root[v] = u;
        sz[u] += sz[v];
        if (sz[u] == k) {
            for (int j = 1; j <= k; j++) {
                cout << a[i].w << ' ';
            }
            cout << endl;
            return 0;
        }
    }
    exit(1);
    return 0;
}