#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> g, vector<int> &v, vector<int> &lvl, int s) {
    deque<int> q{s};
    v[s] = 1;
    int a;

    while (!q.empty()) {
        a = q[0];
        q.pop_front();

        for (int i = 0; i < g[a].size(); i++) {
            if (v[g[a][i]] == 0) {
                q.push_back(g[a][i]);
                lvl[g[a][i]] = lvl[a] + 1;
                v[g[a][i]] = 1;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> p(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<vector<int>> g(n+1);
    for (int i = 1; i <= n; i++) {
        if (p[i] != -1)
            g[p[i]].push_back(i);
    }

    vector<int> v(n+1, 0);
    vector<int> lvl(n+1, 0);

    for (int i = 1; i <= n; i++) {
        if (p[i] == -1 and v[i] == 0)
            bfs(g, v, lvl, i);
    }

    cout << *max_element(lvl.begin(), lvl.end()) + 1;

    return 0;
}