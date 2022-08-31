#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 5e5 + 5;

int n, m, ans[N];
vector<pair<int, int>> g[N];

int lvl[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);

    ans[s] = 1;
    lvl[s] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto& [i, t] : g[x]) {
            if (lvl[i] == -1 and ans[i] == t) {
                lvl[i] = lvl[x] + 1;
                q.push(i);
            } else if (ans[i] == -1) {
                ans[i] = 1 - t;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0, u, v, t; i < m; i++) {
        cin >> u >> v >> t;
        g[v].emplace_back(u, t);
    }

    memset(ans, -1, sizeof(ans));
    memset(lvl, -1, sizeof(lvl));
    bfs(n);
    cout << lvl[1] << '\n';
    for (int i = 1; i <= n; i++) cout << max(0, ans[i]); cout << '\n';
    return 0;
}