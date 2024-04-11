#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;
const int B = 320;

int n, m, lvl[N], ans[N], up[N][20], tin[N], tout[N], T;
vector<int> g[N];
vector<pair<int, int>> qu[B];

void idfs(int x, int p, int d) {
    lvl[x] = ans[x] = d;
    tin[x] = T++;

    up[x][0] = p;
    for (int i = 1; i < 20; i++)
        up[x][i] = up[up[x][i - 1]][i - 1];

    for (int &i : g[x]) {
        if (i == p) continue;
        idfs(i, x, d + 1);
    }
    tout[x] = T++;
}

bool f(int u, int v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (f(u, v))
        return u;
    if (f(v, u))
        return v;

    int x = u;
    for (int i = 19; i >= 0; i--) {
        if (up[x][i] and !f(up[x][i], v))
            x = up[x][i];
    }
    return up[x][0];
}

int dist(int u, int v) {
    return lvl[u] + lvl[v] - 2 * lvl[lca(u, v)];
}

bool visited[N];

void bfs(queue<int>& q) {
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int &i : g[x]) {
            if (!visited[i] and ans[x] + 1 < ans[i]) {
                q.push(i);
                ans[i] = 1 + ans[x];
                visited[i] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    idfs(1, 0, 0);

    for (int i = 0; i < m; i++) {
        int t, v;
        cin >> t >> v;

        qu[i / B].emplace_back(t, v);
    }

    for (int i = 0; i <= (m - 1) / B; i++) {
        vector<int> added;

        for (auto &[t, v]: qu[i]) {
            if (t == 1) {
                added.push_back(v);
            }
            else {
                int now = ans[v];
                for (int ad : added)
                    now = min(now, dist(v, ad));
                cout << now << "\n";
            }
        }

        fill(visited, visited + n + 1, false);
        queue<int> q;

        for (int ad : added) {
            q.push(ad);
            visited[ad] = true;
            ans[ad] = 0;
        }
        bfs(q);
    }
    return 0;
}