#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(2 * m + 1, vector<int> (2, 0));
    vector<int> level(2 * m + 1, 0);
    vector<int> visited(2 * m + 1, 0);

    deque<int> q;

    if (n > m)
        cout << n - m;
    else {
        for (int i = 1; i < g.size(); i++) {
            if (i-1 > 0) {
                g[i][0] = i - 1;
            }
            if (i <= m) {
                g[i][1] = 2 * i;
            }
        }

        q.push_front(n);
        int a;

        while (q.size() > 0) {
            a = q[0];
            q.pop_front();
            visited[a] = 1;

            for (int i = 0; i < g[a].size(); i++) {
                if (g[a][i] != 0 and visited[g[a][i]] == 0) {
                    q.push_back(g[a][i]);
                    level[g[a][i]] = level[a] + 1;
                    visited[g[a][i]] = 1;
                }
            }
        }
        cout << level[m];
    }

    return 0;
}