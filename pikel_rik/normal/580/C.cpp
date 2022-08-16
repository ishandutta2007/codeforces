#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> g, vector<int> arr, int m) {
    queue<int> q;
    q.push(1);

    vector<int> v(g.size());
    v[1] = 1;

    vector<int> lvl(g.size());
    lvl[1] = arr[1];

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        for (int i = 0; i < g[a].size(); i++) {
            if (v[g[a][i]] == 0) {
                v[g[a][i]] = 1;
                q.push(g[a][i]);

                if (lvl[a] == 0)
                    lvl[g[a][i]] = arr[g[a][i]];
                else if (lvl[a] > m)
                    lvl[g[a][i]] = lvl[a];
                else {
                    if (arr[g[a][i]] == 1)
                        lvl[g[a][i]] = lvl[a] + 1;
                    else
                        lvl[g[a][i]] = 0;
                }
            }
        }
    }
    return lvl;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int x, y;
    vector<vector<int>> g(n+1);

    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> lvl = bfs(g, a, m);
    int c = 0;

    for (int i = 2; i <= n; i++) {
        if (g[i].size() == 1 and lvl[i] <= m)
            c += 1;
    }

    cout << c;
    return 0;
}