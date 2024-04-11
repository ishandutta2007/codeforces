#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 101;

int n;
vector<int> g[N];

bool active[N], visited[N], cycle = false;
int f[N], t = 0, ft = -1;

void dfs1(int x = 1, int p = -1) {
    if (ft != -1)
        return;

    f[x] = t++;

    active[x] = true;
    visited[x] = true;

    for (int &i : g[x]) {
        if (i == p) continue;

        if (active[i] and ft == -1)
            ft = f[i];
        if (!visited[i])
            dfs1(i, x);
    }

    if (ft != -1)
        return;

    active[x] = false;
}

set<int> cycc;

void dfs(int x, int p) {
    if (cycle) return;

    visited[x] = true;
    active[x] = true;

    for (int &i : g[x]) {
        if (i == p or (cycc.find(x) != cycc.end() and cycc.find(i) != cycc.end())) continue;

        if (active[i])
            cycle = true;

        if (!visited[i])
            dfs(i, x);
    }

    active[x] = false;
}

void dfs(int x) {
    visited[x] = true;
    for (int &i : g[x]) {
        if (!visited[i])
            dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    memset(f, -1, sizeof(f));

    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    bool flag = true;
    for (int i = 1; i <= n; i++) flag &= visited[i];

    fill(visited, visited + n + 1, false);

    dfs1();
    if (ft == -1 or !flag) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (active[i] and f[i] >= ft)
            cycc.insert(i);
    }

    fill(visited, visited + n + 1, false);
    fill(active, active + n + 1, false);

    for (int i : cycc) {
        visited[i] = true;
        active[i] = true;
    }

    for (int i : cycc)
        dfs(i, -1);
    cout << (cycle ? "NO\n" : "FHTAGN!\n");
    return 0;
}