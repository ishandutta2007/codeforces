#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, a, b, da, db;
vector<int> g[N];

int p[N], lvl[N];

void dfs(int x) {
    for (auto& i : g[x]) {
        if (i == p[x]) continue;
        p[i] = x;
        lvl[i] = lvl[x] + 1;
        dfs(i);
    }
}

bool visited[N];

int bfs(int s) {
    fill(visited, visited + n + 1, false);
    queue<int> q;
    q.push(s);

    lvl[s] = 0;
    visited[s] = true;

    int furthest = s;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto& i : g[x]) {
            if (!visited[i]) {
                visited[i] = true;
                lvl[i] = lvl[x] + 1;
                q.push(i);
                if (lvl[i] > lvl[furthest])
                    furthest = i;
            }
        }
    }
    return furthest;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> a >> b >> da >> db;
        for (int i = 1; i <= n; i++) g[i].clear();

        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int diameter = lvl[bfs(bfs(1))];
        da = min(da, diameter);
        db = min(db, diameter);

        lvl[a] = 0;
        p[a] = 0;
        dfs(a);
        
        if (2 * da >= db or lvl[b] <= da)
            cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}