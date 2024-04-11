#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 401;

int n, lvl[2][N], t0 = 1e9, t1 = 1e9;
bool adj[N][N];
vector<int> g[2][N];

bool bfs(int s, int no) {
    queue<int> q;
    q.push(s);

    vector<bool> visited(n + 1);
    visited[s] = true;
    lvl[no][s] = 0;

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        for (int &i : g[no][a]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
                lvl[no][i] = lvl[no][a] + 1;
            }
        }
    }
    return !visited[n];
}

void dfs(int cur0 = 1, int cur1 = 1, int T0 = 0, int T1 = 0) {
    if (cur0 == n or cur1 == n) {
        if (max(lvl[0][n] + t0, lvl[1][n] + t1) > max(lvl[0][n] + T0, lvl[1][n] + T1)) {
            t0 = T0;
            t1 = T1;
        }
        return;
    }

    for (int i : g[0][cur0]) {
        if (lvl[0][i] != lvl[0][cur0] + 1) continue;

        for (int j : g[1][cur1]) {
            if (lvl[1][j] != lvl[1][cur1] + 1) continue;

            if (i != j)
                dfs(i, j, T0, T1);
            else {
                if (T0 != T1)
                    dfs(i, i, T0, T1);
                else {
                    dfs(i, i, T0 + 1, T1);
                    dfs(i, i, T0, T1 + 1);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    int m; cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;

        g[0][a].push_back(b);
        g[0][b].push_back(a);

        adj[a][b] = true;
        adj[b][a] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (i != j and !adj[i][j]) {
                g[1][i].push_back(j);
                g[1][j].push_back(i);
            }
        }
    }

    if (bfs(1, 0) or bfs(1, 1)) {
        cout << "-1\n";
        return 0;
    }

    dfs(n, n, 0, 0);

    cout << max(lvl[0][n] + t0, lvl[1][n] + t1);
    return 0;
}