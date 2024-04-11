#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> a(n, 0);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> g(n+1, vector<int> (0, 0));
    for (int i = 1; i < n; i++) {
        g[i].push_back(a[i]+i);
    }

    vector<int> visited(n+1, 0);
    deque<int> q;
    q.push_front(1);
    int b;

    while (!q.empty()) {
        b = q[0];
        q.pop_front();
        for (int i = 0; i < g[b].size(); i++) {
            if (visited[g[b][i]] == 0) {
                q.push_back(g[b][i]);
                visited[g[b][i]] = 1;
            }
        }
    }

    if (visited[t] == 0)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}