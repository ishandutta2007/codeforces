#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, m, s;
int w[N];
vector<int> adj[N];
int cntTarjan;
vector<int> stTarjan;
int low[N], num[N];

int group = 0;
int root = 0;
long long a[N];
vector<int> ls[N];
int belong[N];

void dfsTarjan(int u, int p) {
    stTarjan.push_back(u);
    low[u] = num[u] = ++cntTarjan;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (!low[v]) dfsTarjan(v, u);
        low[u] = min(low[v], low[u]);
    }
    if (low[u] == num[u]) {
        ++group;
        while (1) {
            int x = stTarjan.back();
            stTarjan.pop_back();
            ls[group].push_back(x);
            if (x == s) root = group;
            a[group] += w[x];
            belong[x] = group;
            if (u == x) break;
        }
    }
}

long long res = 0;
int used[N];
int can[N];

long long dfs(int u) {
    used[u] = 1;
    can[u] = (ls[u].size() > 1);
    long long cur = 0;
    for (int id : ls[u]) {
        for (int id2 : adj[id]) {
            int v = belong[id2];
            if (used[v]) continue;
            long long foo = dfs(v);
            can[u] |= can[v];
            cur = max(cur, foo);
        }
    }
    if (can[u]) res += a[u];
    else {
        cur += a[u];
    }
    return cur;
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> s;
    dfsTarjan(1, 0);
    long long now = dfs(root);
    cout << res + now << endl;
    return 0;   
}