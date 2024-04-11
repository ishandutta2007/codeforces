#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 5000 + 5;

int n, m, p[N], tin[N], tout[N], T;
vector<int> g[N];

pair<int, int> edges[N];
pair<pair<int, int>, int> paths[N];
int val[N];

void dfs(int x, int par) {
    p[x] = par;
    tin[x] = T++;

    for (int &i : g[x]) {
        if (i == par) continue;
        const pair<int, int> edge = edges[i];
        if (edge.first == x)
            dfs(edge.second, i);
        else dfs(edge.first, i);
    }
    tout[x] = T++;
}

bool f(int u, int v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(i - 1);
        g[v].push_back(i - 1);
        edges[i - 1] = {u, v};
    }

    dfs(1, -1);

    cin >> m;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        paths[i] = make_pair(make_pair(u, v), w);

        int x = u;
        while (!f(x, v)) {
            val[p[x]] = max(val[p[x]], w);
            if (edges[p[x]].first != x)
                x = edges[p[x]].first;
            else x = edges[p[x]].second;
        }

        x = v;
        while (!f(x, u)) {
            val[p[x]] = max(val[p[x]], w);
            if (edges[p[x]].first != x)
                x = edges[p[x]].first;
            else x = edges[p[x]].second;
        }
    }

    for (int i = 0; i < m; i++) {
        int u = paths[i].first.first, v = paths[i].first.second, w = paths[i].second;

        int x = u, mn = INT_MAX;
        while (!f(x, v)) {
            mn = min(mn, val[p[x]]);
            if (edges[p[x]].first != x)
                x = edges[p[x]].first;
            else x = edges[p[x]].second;
        }

        x = v;
        while (!f(x, u)) {
            mn = min(mn, val[p[x]]);
            if (edges[p[x]].first != x)
                x = edges[p[x]].first;
            else x = edges[p[x]].second;
        }

        if (mn != w) {
            cout << "-1\n";
            return 0;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        cout << max(1, val[i]) << " ";
    }
    return 0;
}