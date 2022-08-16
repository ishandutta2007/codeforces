#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n;
vector<int> g[N];

int lvl[N];
bool visited[N];

int bfs(int s) {
    fill(visited + 1, visited + n + 1, false);

    queue<int> q;
    q.push(s);

    visited[s] = true;
    lvl[s] = 0;

    int furthest = s;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int &i : g[x]) {
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

int p[N];
vector<int> subtree;

void dfs(int x, int par, int d) {
    lvl[x] = d;
    p[x] = par;
    subtree.push_back(x);

    for (int &i : g[x]) {
        if (i == par) continue;
        dfs(i, x, d + 1);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int f1 = bfs(1);
    int f2 = bfs(f1);

    dfs(f1, 0, 0);
    vector<int> path; {
        int x = f2;
        while (x) {
            path.push_back(x);
            x = p[x];
        }
    }

    int guy = 0;
    for (int j = 0; j < path.size(); j++) {
        int x = path[j];
        for (int &i : g[x]) {
            if ((j > 0 and i == path[j - 1]) or (j + 1 < path.size() and i == path[j + 1])) continue;

            subtree.clear();
            dfs(i, x, 1);

            for (int k : subtree) {
                if (lvl[k] > lvl[guy])
                    guy = k;
            }
        }
    }

    if (guy == 0) {
        guy = path[1];
        lvl[guy] = 0;
    }

    cout << path.size() - 1 + lvl[guy] << '\n';
    cout << f1 << " " << f2 << " " << guy << '\n';
    return 0;
}