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

ll n, lvl[N], dp[N], dp1[N];
vector<int> g[N];

bool visited[N], sp[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);

    visited[s] = true;
    lvl[s] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int &i : g[x]) {
            if (!visited[i]) {
                visited[i] = true;
                lvl[i] = lvl[x] + 1;
                q.push(i);
            }
        }
    }
}

void dfs(int x) {
    sp[x] = true;

    for (int &i : g[x]) {
        if (lvl[i] == lvl[x] - 1) {
            if (!sp[i])
                dfs(i);
            dp[x] += dp[i];
        }
    }
}

void dfs1(int x) {
    visited[x] = true;

    for (int &i : g[x]) {
        if (lvl[i] == lvl[x] + 1) {
            if (!visited[i])
                dfs1(i);
            dp1[x] += dp1[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(1);

    fill(visited, visited + n + 1, false);

    dp[1] = 1;
    dfs(n);

    dp1[n] = 1;
    dfs1(1);

    double best = dp[n];

    for (int i = 2; i < n; i++) {
        if (sp[i]) {
            best = max(best, 2.0 * dp[i] * dp1[i]);
        }
    }

    cout << fixed << setprecision(10);
    cout << best / dp[n];
    return 0;
}